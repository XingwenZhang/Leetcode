// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".


class Solution {
public:
    string addBinary(string a, string b) {
        
        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        string res = "";
        while(i>=0 || j>=0 || carry== 1){
        	carry += i>=0 ? a[i]-'0' : 0;
        	carry += j>=0 ? b[j]-'0' : 0;
        	res = to_string(carry-2) + res;
        	carry = carry / 2;
        }

        return res;

    }
};