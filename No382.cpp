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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */

    int getRandom() {
        //ListNode* headCopy = head;
        //here must use template variable temp, it is because in real use the random function is not only used once,
        //if do not, the second use of getRandom function, the head has already been changed, so the result is challangeable.
        ListNode* temp = head;
        int result = temp->val;
        //这里i应该是从1开始
        for(int i = 1; temp->next != NULL; i++)
        {
        	temp = temp->next;
        	if(randResult(i))
        	{
        		result = temp->val;
        	}
        }
        return result;
    }
      
    
private:
	ListNode* head;
	bool randResult(int num)
	{
		int randNum = rand()%(num+1);
		if(randNum == num)
			return true;
		return false;
	}
};


/*private:
	ListNode* head;
	int randResult(int num)
	{
		int randNum = rand()%(num+1);
		return randNum;
	}

};*/
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */