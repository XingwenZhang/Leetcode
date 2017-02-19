/*141. Linked List Cycle
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// directed method, use set to check if there is some duplicate
/*class Solution {
public:
    bool hasCycle(ListNode *head) {
    	// for small data, set is better, because it doesn't need to cal the hash function
    	unordered_set<ListNode*> hashSet;
    	while(head){
    		if(hashSet.insert(head).second == false){
    			return true;
    		}
    		head = head->next;
    	}
    	return false;
    }
};*/





//improvement, no need extra space
// fast and slow pointer, if there is a cycle, these two will ecounter with each other
class Solution{
public:
	bool hasCycle(ListNode *head){
		if(!head){
			return false;
		}
		ListNode *fast = head;
		ListNode *slow = head;
		while(fast->next!=NULL && fast->next->next!=NULL){
			fast = fast->next->next;
			slow = slow->next;
			if(fast == slow){
				return true;
			}
		}
		return false;
	}
};