// 138. Copy List with Random Pointer

// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

// Return a deep copy of the list.


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	RandomListNode *new_head = new RandomListNode(0);
    	RandomListNode *cur = new_head;
    	map<RandomListNode*, RandomListNode*> list_map;
    	while(head){
    		cur->next = new RandomListNode(head->label);
    		list_map[head] = cur->next;
    		cur = cur->next;
    		head = head->next;
    	}

    	for(auto& item : list_map){
    		item.second->random = list_map[item.first->random];
    	}
    	return new_head->next;

    }
};