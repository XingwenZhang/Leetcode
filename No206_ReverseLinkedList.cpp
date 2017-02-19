/*206. Reverse Linked List

Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* rear = NULL;
        if(head==NULL || head->next == NULL){
        	return head;
        }
        while(cur!=NULL){
        	rear = cur->next;
        	cur->next = pre;
        	pre = cur;
        	cur = rear;
        }
        return pre;
    }
};*/

// iterative reverse linked list
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = head;
        ListNode* next = head;

        while(head){
        	next = head->next;
        	head->next = pre;
        	pre = head;
        	head = next;
        }
        return pre;
    }
};*/

// recursive reverse linked list
// not very easy to understand, pay attention to the sequence of function and reverse operation.
// the idea is that: go to the end of the linkedlist, and reverse, the node return is just the last node of the linkedlist
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
        	return head;
        }
        //sequence is very important
        ListNode* node = reverseList(head->next);
        //reverse operation
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};