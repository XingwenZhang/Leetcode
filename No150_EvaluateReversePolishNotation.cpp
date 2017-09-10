// 150. Evaluate Reverse Polish Notation

// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for(auto& item : tokens){
            if(item == "+" || item == "-" || item=="*" || item=="/"){
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                if(item == "+"){
                    nums.push(first+second);
                }
                if(item == "-"){
                    nums.push(first - second);
                }
                if(item == "*"){
                    nums.push(first * second);
                }
                if(item == "/"){
                    nums.push(first / second);
                }
            }
            else{
                nums.push(stoi(item,nullptr));
            }
        }
        return nums.top();
    }
};