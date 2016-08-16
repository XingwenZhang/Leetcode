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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* front = new ListNode(0);
        ListNode* cur = head;
        ListNode* temp = front ;

        front->next = head; 
        

        while(cur!=NULL && cur->next != NULL)
        {
        	front->next = cur->next;
        	cur->next = cur->next->next;
        	front->next->next = cur;
        	front=cur;
        	cur = cur->next;
        }

        return temp->next;



        
    }
};