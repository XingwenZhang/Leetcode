// 143. Reorder List

// Given a singly linked list L: L0?L1?…?Ln-1?Ln,
// reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head){
            return;
        }
        // Loop once, find length of list
        ListNode *tmp = head;
        int n = 0;
        while(tmp->next){
            n++;
            tmp = tmp->next;
        }

        // Reorder
        ListNode *new_head = head;
        ListNode *origin_next = NULL;
        int index = 0;
        while((n-index)-index - 1 > 0){
            int skip = n-2*index - 1;
            tmp = new_head;
            while(skip--){
                tmp = tmp->next;
            }
            origin_next = new_head->next;
            new_head->next = tmp->next;
            tmp->next = NULL;
            new_head->next->next = origin_next;

            new_head = origin_next;
            index++;
        }
        

    }
};