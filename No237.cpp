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
    void deleteNode(ListNode* node) {
    	//it is because that we cannot find the front node,
    	//so the strategy is just to let the rear node to replace the 
    	//node. And what's more, the struct can be assigned directly 
    	//by =. So the solution is ok.
        *node = *(node->next);
    }
};