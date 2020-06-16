// PALINDROME LINKED LIST

/*  PROBLEM:
    Given a singly linked list, determine if it is a palindrome.
*/ 

/*  EXAMPLE:

    Input: 1->2
    Output: false

    Input: 1->2->2->1
    Output: true
*/

/*  APPROACH: 
    1. Check if the list is empty and return true if so, since empty lists are considered as palindromic.
    2. Initialize two pointers such that one traverses the list two nodes at a time and the other traverses the list one node at a time.
    3. When the fast pointer is at the end of the list, the slow pointer is at the halfway-point of the list.
    4. Reverse one half of the list.
    5. Vertically compare each element of the two sub-lists and check if they are equal.
    6. If every element is equal, return true. If they are not equal, return false.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

// Linked list definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Reverse Linked List
    ListNode* reverseList(ListNode* head) {
        // Initialise a pointer for the previous node and a pointer for the current node
        struct ListNode *prev = NULL, *curr = head;
        // Exit the loop when the current node reaches null
        while(curr) {
            // Store the address of the node next to current since a node does not have reference to previous nodes
            struct ListNode *temp = curr->next;
            // Change the current node's pointer to point to the previous node
            curr->next = prev;
            // Move the previous node to the next element
            prev = curr;
            // Move the current node to the node after the next element
            curr = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // An empty list is considered to be a palindrome
        if(head == NULL) {
            return true;
        }

        // Initialize a fast pointer and a slow pointer to traverse through the list
        struct ListNode *fast = head, *slow = head;

        // Exit when the fast pointer reaches the end of the list
        while(fast->next != NULL && fast->next->next != NULL) {
            // Move the slow pointer one node at a time
            slow = slow->next;
            // Move the fast pointer two nodes at a time
            fast = fast->next->next;
        }
        // The slow pointer is at the middle element, so we reverse half of the list
        slow->next = reverseList(slow->next);
        slow = slow->next;

        while(slow) {
            // If the starting nodes of the two sub-lists are not equal, they are not palindromes
            if(head->val != slow->val) {
                return false;
            }
            // Move the slow and head pointers and compare the remaining elements
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
