/*234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// direct way, traverse list and store the val into array
// memory limit exceed
/*class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(head == NULL){
    		return true;
    	}
    	vector<int> temp;
        while(head){
        	temp.push_back(head->val);
        }
        for(int i=0; i<=temp.size(); i++){
        	if(temp[i]!=temp[temp.size()-i-1]){
        		return false;
        	}
        }
        return true;
    }
};*/


class Solution {
public:
    bool isPalindrome(ListNode* head) {

    	if(!head){
    		return true;
    	}

    	ListNode *fast = head, *slow = head;

    	while(fast->next != NULL && fast->next->next != NULL){
    		fast = fast->next->next;
    		slow = slow->next;
    	}

    	slow = reserveList(slow->next);

    	while(slow!=NULL){
    		if(head->val!=slow->val){
    			return false;
    		}
    		head = head->next;
    		slow = slow->next;
    	}
    	return true;


    }
private:
	ListNode* reserveList(ListNode* node){
		ListNode *pre = NULL;
		ListNode *next = NULL;
		while(node){
			next = node->next;
			node->next = pre;
			pre = node;
			node = next;
		}
		return pre;
	}
};