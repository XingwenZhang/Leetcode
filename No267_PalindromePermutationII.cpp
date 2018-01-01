// 267. Palindrome Permutation II

// Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

// For example:

// Given s = "aabb", return ["abba", "baab"].

// Given s = "abc", return [].

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        // Use map to store the char and its count
        unordered_map<char, int> m;
        vector<string> res;
        vector<char> even_char;
        for(auto& item : s){
            m[item]++;
        }
        int odd_cnt = 0;
        string odd_str = "";
        // Check the odd count's number
        for(auto & ele : m){
            if (ele.second % 2 != 0){
                odd_cnt++;
                if(odd_cnt > 1){
                    return res;
                }
                odd_str.push_back(ele.first);

                // If the odd is bigger than 1
                for(int i=0; i<ele.second/2; i++){
                    even_char.push_back(ele.first);
                }
            }
            else{
                for(int i=0; i<ele.second/2; i++){
                    even_char.push_back(ele.first);
                }
            } 
        }

        // Sort and use next_permutation func
        sort(even_char.begin(), even_char.end());
        // string odd_str(1, odd_char);
        do{
            string part(even_char.begin(), even_char.end());
            string rev_part(part);
            reverse(rev_part.begin(), rev_part.end());
            res.push_back(part + odd_str + rev_part);
        }while(next_permutation(even_char.begin(), even_char.end()));
        return res;
    }
};