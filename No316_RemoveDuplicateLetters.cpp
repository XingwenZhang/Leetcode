// 316. Remove Duplicate Letters

// Given a string which contains only lowercase letters, 
// remove duplicate letters so that every letter appear once 
// and only once. You must make sure your result is the smallest 
// in lexicographical order among all possible results.

// Example:
// Given "bcabc"
// Return "abc"

// Given "cbacdcbc"
// Return "acdb"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[256] = {0}, visited[256] = {0};
        string res = "0";

        for(auto a : s) ++m[a];
        for(auto a : s){
            --m[a];
            if(visited[a]) continue;

            // Pop out all bigger characters
            while(a < res.back() && m[res.back()]){
                visited[res.back()] = 0;
                res.pop_back();
            }

            // Add current char
            res += a;
            // set visited
            visited[a] = 1;


        }

        return res.substr(1);
    }
};