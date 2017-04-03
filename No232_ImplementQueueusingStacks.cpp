// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.
// Notes:
// You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
// // You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).



class MyQueue {
public:
	// Two stacks to operate
	// one stack for push operation
	// one stack for pop operation
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        push_stack_.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(pop_stack_.empty()){
        	while(!push_stack_.empty()){
        		pop_stack_.push(push_stack_.top());
        		push_stack_.pop();
        	}
        }
        int res = pop_stack_.top();
        pop_stack_.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(pop_stack_.empty()){
        	while(!push_stack_.empty()){
        		pop_stack_.push(push_stack_.top());
        		push_stack_.pop();
        	}
        }
        int res = pop_stack_.top();
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(push_stack_.empty() && pop_stack_.empty()){
        	return true;
        }
        return false;
    }
private:
	stack<int> push_stack_;
	stack<int> pop_stack_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */