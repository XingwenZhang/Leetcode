class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        s.push(x);
        for(int i=1; i<s.size(); i++){
            s.push(s.front());
            s.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = s.front();
        s.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return s.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return s.empty();
    }
private:
    queue<int> s;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */