// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

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
    ListNode* rotateRight(ListNode* head, int k) {
        
    	if(k == 0 || head == NULL){
    		return head;
    	}

    	// Get the length of list
    	int len = 0;
    	ListNode* temp = head;
    	while(temp != NULL){
    		temp = temp->next;
    		len++;
    	}

    	// If k is bigger than or equal to length of list
    	// set k to the modular 
    	if(k >= len){
    		k = k%len;
    	}
        
        // If k equal to 0, return head 
        if(k == 0){
            return head;
        }
        
        // The normal situation
        // Double pointer, distance is k
        ListNode* pre = head;
        ListNode* post = pre;
        for(int i = k; i > 0; i--){
        	post = post->next;
        }

        // Post points to the last element
        // Pre points to the element right before k 
        while(post->next != NULL){
        	post = post->next;
        	pre = pre->next;
        }

        ListNode* res = pre->next;
        pre->next = NULL;
        post->next = head;

        return res;
    }
};