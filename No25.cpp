/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//wrong understanding the question, just swap the head and tail
/*
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL)
            return NULL;
        if(head->next==NULL && k>=1)
        {
            return head;
        }
        if(k==1)
        {
            return head;
        }
    	ListNode *p,*q;
    	ListNode* newHead = new ListNode(0);
    	newHead->next = head; 
    	p = newHead;
    	q=newHead;
    	int len = k;
    	while(q)
    	{
    		while(--len>0)
    		{
    			if(!q->next)
    				break;
    			q=q->next;
    		}
    		if(len!=0 || q->next==NULL)
    		{
    			break;
    		} 
    	else
    		{
    			if(p->next==q && q->next->next==NULL)
    			{
    				ListNode * temp=p->next;
    				p->next = q->next;
    				//q->next = temp;
    				
    				q->next = temp->next->next;
    				p->next->next = q;
    			}
    			else
    			{
    				
                    ListNode *temp = p->next;
    				p->next = q->next;
    				q->next = temp;
    				temp = p->next->next;
    				p->next->next = q->next->next;
    				q->next->next = temp;
    			}
    			
    		}
    		len = k;
    		//q=q->next;
    		p=q;

    	}
    	return newHead->next;
    }
};*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//can use stack change the order
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

    	//corner-case
    	if(k==1 || head==NULL ||head->next==NULL)
    	{
    		return head;
    	}
        stack<ListNode*> container;
        ListNode* newHead=new ListNode(0);
        newHead->next=head;
        ListNode* p=head;
        ListNode* q=newHead;
        int len=k;
        while(true)
        {
        	while(len-->0)
        	{
        		if(p==NULL)
        			break;
        		container.push(p);
        		p=p->next;
        	}
        	if(len!=-1)
        	{
        		break;
        	}
        	else
        	{

        		while(!container.empty())
        		{
        			ListNode* temp = container.top();
        			q->next = temp;
        			temp->next = NULL;
        			container.pop();
        			q=q->next;
        		}
        		q->next = p;

        	}
        	len = k;
        }
        return newHead->next;
    }
};