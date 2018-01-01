//  266. Palindrome Permutation

//  Given a string, determine if a permutation of the string could form a palindrome.

// For example,
// "code" -> False, "aab" -> True, "carerac" -> True.

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> a;

        for(auto& b:s){
            a.flip(b);
        }

        return a.count() < 2;
    }
};


class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> a;
        for(auto& b : s){
            if(a.count(b) == 0){
                a.insert(b);
            }
            else{
                a.erase(b);
            }
        }
        return a.size() < 2;
    }
};