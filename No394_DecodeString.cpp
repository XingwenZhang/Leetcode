// 394. Decode String

// Given an encoded string, return it's decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

// Examples:

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

// Recursion
class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return decode(s, pos);

    }
    // Handle one bracket
    string decode(string& s, int& pos){
        string res = "";
        int len = s.size();
        while(pos < len && s[pos] != ']'){ // If equal to ], then this function finishes
            // alpha
            if(s[pos]<'0' || s[pos] > '9'){
                res += s[pos];
                pos++;
            }
            else{
                int cnt = 0;
                while(s[pos]>='0' && s[pos]<='9' && pos<len){
                    cnt = cnt*10 + s[pos]-'0';
                    pos++;
                }
                // skip [
                pos++;
                string t = decode(s, pos);

                // skip inner ]
                pos++;

                while(cnt){
                    res += t;
                    cnt--;
                }
            }
        }
        return res;
    }
};



// Iterative
class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> s_stack;

        string t="";
        string res="";
        int cnt=0;
        int len = s.size();
        for(int i=0; i<len; i++){
            if(s[i]>='0' && s[i]<='9'){
                cnt = cnt*10 + s[i]-'0';
            }
            else if(s[i] == '['){ // push into stack
                nums.push(cnt);
                cnt = 0;
                s_stack.push(t);
                t.clear();
            }
            else if(s[i] == ']'){
                int n_top = nums.top();
                nums.pop();
                while(n_top){
                    s_stack.top() += t;
                    n_top--;
                }
                t = s_stack.top();
                s_stack.pop();
            }
            else{
                t += s[i];
            }
        }
        return s_stack.empty() ? t : s_stack.top();

    }
}
  








