/*155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.*/


// use double linked list to build up stack

class myListNode{
public:
	int val;
	myListNode *next;
	myListNode *pre;
	//store the min value up to this node
	int minVal;
	myListNode(int x):val(x), minVal(INT_MAX), next(NULL), pre(NULL) {}
};

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        head = new myListNode(INT_MAX);
        cur = head;
    }
    
    void push(int x) {
        myListNode *node = new myListNode(x);
        node->minVal = min(cur->minVal, x);
        cur->next = node;
        node->pre = cur;
        cur = node;
    }
    
    void pop() {
        if(cur == head){
        	return;
        }
        myListNode *temp = cur;
        cur = cur->pre;
        cur->next = NULL;
        delete temp;
    }
    
    int top() {
        return cur->val;
    }
    
    int getMin() {
        return cur->minVal;
    }
private:
	myListNode *head;
	myListNode *cur;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


I build up a special doubly-linked list to store the Min Stack.
And I add a minVal field into the list to store the the minimum value.
The code is as follows:
```
class myListNode{
public:
	int val;
	myListNode *next;
	myListNode *pre;
	//store the min value up to this node
	int minVal;
	myListNode(int x):val(x), minVal(INT_MAX), next(NULL), pre(NULL) {}
};

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        head = new myListNode(INT_MAX);
        cur = head;
    }
    
    void push(int x) {
        myListNode *node = new myListNode(x);
        node->minVal = min(cur->minVal, x);
        cur->next = node;
        node->pre = cur;
        cur = node;
    }
    
    void pop() {
        if(cur == head){
        	return;
        }
        myListNode *temp = cur;
        cur = cur->pre;
        cur->next = NULL;
        delete temp;
    }
    
    int top() {
        return cur->val;
    }
    
    int getMin() {
        return cur->minVal;
    }
private:
	myListNode *head;
	myListNode *cur;
};
```