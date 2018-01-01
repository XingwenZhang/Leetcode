// 224. Basic Calculator

// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

// You may assume that the given expression is always valid.

// Some examples:
// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23
// // Note: Do not use the eval built-in library function.

class Solution {
public:
    // Reverse Polish notation, two stacks
    int calculate(string s) {
        stack<char> signs;
        stack<int> nums;
        int tmp = 0;
        bool flag = false;
        for(auto& item : s){
            if(item >= '0' && item <= '9'){
                tmp *= 10;
                tmp += item - '0';
                flag = true;
            }
            else if(item == '+' || item == '-'){
                if(flag){
                    nums.push(tmp);
                    tmp = 0; // reset tmp
                    flag = false; // reset flag
                }
                

                if(signs.empty()){
                    signs.push(item);
                }
                else if(sings.top() == '('){
                    signs.push(item);
                }
                else{
                    int prev_sign = signs.top();
                    signs.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int num1 = nums.top();
                    nums.pop();
                    int res = prev_sign == '+' ? num1 + num2 : num1 - num2;
                    nums.push(res);

                    signs.push(item);
                }
            }

            else if(item == '('){
                signs.push(item);
            }

            else if(item == ')'){
                if(flag){
                    nums.push(tmp);
                    tmp = 0;
                    flag = false;
                }

                while(signs.top() != '('){
                    int prev_sign = signs.top();
                    signs.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int num1 = nums.top();
                    nums.pop();
                    int res = prev_sign == '+' ? num1 + num2 : num1 - num2;
                    nums.push(res);
                }


                signs.pop(); // pop out "("
            }
        }

        if(flag){
            nums.push(tmp);
            tmp = 0;
            flag = false;
        }
        while(!signs.empty()){
            int prev_sign = signs.top();
            signs.pop();
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            int res = prev_sign == '+' ? num1 + num2 : num1 - num2;
            nums.push(res);
        }

        return nums.top();
    }
};