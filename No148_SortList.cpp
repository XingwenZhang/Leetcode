// 148. Sort List


// Sort a linked list in O(n log n) time using constant space complexity.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// MergeSort for linked list
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         merge_sort(&head);
//         return head;
//     }
//     void merge_sort(ListNode** node){
//         if(*node == nullptr || (*node)->next == nullptr)
//             return;
//         ListNode* a, *b;
//         split_list(*node, &a, &b);
//         merge_sort(&a);
//         merge_sort(&b);

//         *node = merge_list(a, b);
//     }
//     ListNode* merge_list(ListNode* a, ListNode* b){
//         if(a == nullptr){
//             return b;
//         }
//         if(b == nullptr){
//             return a;
//         }
//         ListNode* res = nullptr;

//         if(a->val <= b->val){
//             res = a;
//             res->next = merge_list(a->next, b);
//         }
//         else{
//             res = b;
//             res->next = merge_list(a, b->next);
//         }
//         return res;
//     }
//     // Slow and fast double pointers
//     void split_list(ListNode* s, ListNode** front, ListNode** last){
//         ListNode *slow=nullptr, *fast=nullptr;
//         if(s==nullptr || s->next == nullptr){
//             *front = s;
//             *last = nullptr;
//         }
//         slow = s;
//         fast = s->next;
//         while(fast){
//             fast = fast->next;
//             while(fast){
//                 slow = slow->next;
//                 fast = fast->next;
//             }
           
//         }
//         *front = s;
//         *last = slow->next;
//         slow->next = nullptr;
//     }
// };





// AC solution
// MergeSort for linked list
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* a, *b;
        split_list(head, &a, &b);
        a=sortList(a);
        b=sortList(b);

        head = merge_list(a, b);
        return head;

    }
    // void merge_sort(ListNode** node){
    //     if(*node == nullptr || (*node)->next == nullptr)
    //         return;
    //     ListNode** a, **b;
    //     split_list(*node, a, b);
    //     merge_sort(a);
    //     merge_sort(b);

    //     *node = merge_list(*a, *b);
    // }
    ListNode* merge_list(ListNode* a, ListNode* b){
        if(a == nullptr){
            return b;
        }
        if(b == nullptr){
            return a;
        }
        ListNode* res = nullptr;

        if(a->val <= b->val){
            res = a;
            res->next = merge_list(a->next, b);
        }
        else{
            res = b;
            res->next = merge_list(a, b->next);
        }
        return res;
    }
    // Slow and fast double pointers
    void split_list(ListNode* s, ListNode** front, ListNode** last){
        ListNode *slow=nullptr, *fast=nullptr;
        if(s==nullptr || s->next == nullptr){
            *front = s;
            *last = nullptr;
        }
        slow = s;
        // fast = s->next;
        fast = s->next;
        while(fast){
            fast = fast->next;
            if(fast){
                slow = slow->next;
                fast = fast->next;
            }
           
        }
        *front = s;
        *last = slow->next;
        slow->next = nullptr; // terminate the first half
    }
};