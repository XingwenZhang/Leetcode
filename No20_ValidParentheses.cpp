/*20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.*/


// stack 
class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;

        for(auto ele:s){
        	switch(ele){
        		case '(':
        		case '[':
        		case '{': paren.push(ele); break;
        		case ')': if(paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
        		case ']': if(paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
        		case '}': if(paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
        	}
        }
        return paren.empty();

    }
};