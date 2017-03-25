// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.


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
    ListNode* deleteDuplicates(ListNode* head) {
    	if(head == NULL){
    		return head;
    	}
        bool dup = false;
        ListNode *pre=new ListNode(-1), *cur=head, *tmpHead=pre;
        tmpHead->next = head;
        while(cur != NULL){
        	if(cur->next && cur->val == cur->next->val){
        		dup = true;
        		cur = cur->next;
        	}
        	// Delete the duplicate elements
        	// If the duplicates are repeated, like 1 1 1 2 2 2 3
        	// the pre->next will update, but pre will not update
        	else if(dup){
        		cur = cur->next;
        		pre->next = cur;
        		dup = false;
        	}
        	else{
        		pre = cur;
        		cur = cur->next;
        	}
        }
        return tmpHead->next;
    }

};