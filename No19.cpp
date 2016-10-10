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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //ListNode* headDup=head;
        //double pointer, the interval is n
        ListNode *header = new ListNode(0);
        header->next = head;
        ListNode *p1,*p2;
        p1=header;
        p2=header;
        while(n)
        {
        	p2=p2->next;
        	n--;
        }
        while(p2->next)
        {
        	p1=p1->next;
        	p2=p2->next;
        }
        p1->next=p1->next->next;
        return header->next;
    }
};