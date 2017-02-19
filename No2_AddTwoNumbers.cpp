//No.2 Add two numbers

/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8*/


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* temp = res;

        int sum = 0;
        while(l1!=NULL || l2!=NULL){
        	sum /= 10;
        	if(l1!=NULL){
        		sum += l1->val;
        		l1 = l1->next;
        	}
        	if(l2!=NULL){
        		sum += l2->val;
        		l2 = l2->next;
        	}
        	temp->next = new ListNode(sum%10);
        	temp = temp->next;
        }

        if (sum / 10 == 1){
        	temp->next = new ListNode(1);
        }

        return res->next;
    }
};