// 290. Word Pattern

// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

// Credits:
// Special thanks to @minglotus6 for adding this problem and creating all test cases.


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, int> s;
        unordered_map<char, int> c;
        istringstream is(str);
        // vector<string> s(istream_iterator<string>{is},
        //                 istream_iterator<string>());

        int index = 0;
        for(string word; is >> word; index++){
            if(s.count(word) || c.count(pattern[index])){
                // default value for unknown key is 0
                if(s[word] != c[pattern[index]]) return false;
            }
            else{
                s[word] = c[pattern[index]] = index + 1; // plus one to avoid the default value 0
            }
        }

        return index == pattern.size();
        
    }
};