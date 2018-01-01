// 186. Reverse Words in a String II

// Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

// The input string does not contain leading or trailing spaces and the words are always separated by a single space.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Could you do it in-place without allocating extra space?

// Related problem: Rotate Array

// Update (2017-10-16):
// We have updated the function signature to accept a character array, so please reset to the default code definition by clicking on the reload button above the code editor. Also, Run Code is now available!

class Solution {
public:
    // Reverse the whole string then reverse the words seperately
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int index_of_space = 0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == ' '){
                reverse(str.begin()+index_of_space, str.begin()+i);
                index_of_space = i+1;
            }
        }
        // Reverse the last word
        reverse(str.begin()+index_of_space, str.end());
    }
};