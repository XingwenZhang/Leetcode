class Solution {
public:
    string reverseString(string s) {
        

        //use s to initialize to make sure temp has enough space to store the characters
        string temp(s);
        int len = s.length();
        len--;
        for(int i=0; i<s.length(); i++)
        {
        	temp[i]=s[len--];
        }
        return temp;
    }
};