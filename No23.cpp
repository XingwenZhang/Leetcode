/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
    	int size = lists.size();
    	ListNode* head = new ListNode(0);
    	ListNode* headtemp = head;
    	initiate(size);
    	for(int i=0; i<size; i++)
    	{
    	    if(lists[i])
    		    insert(lists[i]);
    		//lists[i]=lists[i]->next;
    	}
    	while(!isEmpty())
    	{
    		ListNode* temp=deleteMin();
    		if(temp->next)
    		{
    			insert(temp->next);
    		}
    		ListNode* node = new ListNode(0);
    		node=temp;
    		head->next = node;
    		head=head->next;
    	}
    	return headtemp->next;

        
    }
private:
	int N=0;
	ListNode** Key;
	void initiate(int size)
	{
		Key = new ListNode*[size+1];
	}
	void swap(int i, int j)
	{
		ListNode* temp = Key[i];
		Key[i]=Key[j];
		Key[j]=temp;
	}
	void sink(int k)
	{
		while(2*k<=N)
		{
			int j=2*k;
			if(j<N && Key[j]->val>Key[j+1]->val)
				j++;
			if(Key[k]->val<Key[j]->val)
				break;
			swap(k,j);
			k=j;
		}
	}
	void swim(int k)
	{
		while(k>1 && Key[k]->val<Key[k/2]->val)
		{
			swap(k,k/2);
			k=k/2;
		}
	}
	void insert(ListNode* value)
	{
		Key[++N]=value;
		swim(N);
	}
	ListNode* deleteMin()
	{
		ListNode* min = Key[1];
		swap(1,N);
		Key[N--]=NULL;
		sink(1);
		return min;
	}
	bool isEmpty()
	{
		return N==0;
	}
};