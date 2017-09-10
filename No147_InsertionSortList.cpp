// 147. Insertion Sort List

// Sort a linked list using insertion sort.


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
    // Find i and insert into 0~i-1
    ListNode* insertionSortList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre_head = new ListNode(-1);
        ListNode *pre = new ListNode(-1);
        pre_head->next = cur;
        pre->next = cur;
        bool flag = false;
        while(cur){
            ListNode *tmp = pre_head;
            while(tmp->next != cur){
                if(cur->val < tmp->next->val){
                    ListNode *temp = tmp->next;
                    tmp->next = cur;
                    // Pre is just one before the cur
                    pre->next = cur->next;
                    cur = cur->next;
                    tmp->next->next = temp;
                    flag = true;
                    break;
                }
                tmp = tmp->next;
            }
            if(!flag){
                pre = cur;
                cur = cur->next;
            }
            flag = false;
            
        }
        return pre_head->next;
    }
};