// MERGE TWO SORTED LISTS

/*  PROBLEM:
    Merge two sorted linked lists and return it as a new list. 
    The new list should be made by splicing together the nodes of the first two lists.
*/ 

/*  EXAMPLE:

    Input: 1->2->4, 1->3->4
    Output: 1->1->2->3->4->4
*/

/*  APPROACH: Iterative
    1. Check if either of the lists are empty and return the other list if so.
    2. Check the first element in both lists to find the smallest element and store it in a temporary variable.
    3. Connect subsequent nodes to to the node stored in the previous step.
    4. If the element is the first element in the list, then set all pointers to point to this element. Else, set the pointers to reference the next element to be added.
    5. After the loop exits, check if there are any elements remaining in either list and connect the pointer of the last element to the remaining elements in that list.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Return the other list if one of the lists are empty
        if(!l1) {
            return l2;
        }
        if(!l2) {
            return l1;
        }
        // Initialize two pointers to track the head and current nodes
        struct ListNode *head = NULL, *curr = NULL;

        while(l1 && l2) {
            struct ListNode *temp;
            // If the smallest element is the first element of l1
            if(l1->val < l2->val) {
                // Store the element in a temporary variable and connect subsequent nodes to this node
                temp = l1;
                l1 = l1->next;
            }
            // If the smallest element is the first element of l2
            else {
                // Store the element in a temporary variable and connect subsequent nodes to this node
                temp = l2;
                l2 = l2->next;
            }
            // If the element is the first element, let all pointers point to this element
            if(head == NULL) {
                head = curr = temp;
            }
            else {
                // The current pointer points to the next element to be added, stored in temp
                curr->next = temp;
                // Move the current pointer
                curr = temp;
            }
        }
        // If elements still remain in l1, the current pointer points to the remainder of l1
        if(l1 != NULL) {
            curr->next = l1;
        }
        // If elements still remain in l1, the current pointer points to the remainder of l1
        if(l2 != NULL) {
            curr->next = l2;
        }
        return head;
    }
};
