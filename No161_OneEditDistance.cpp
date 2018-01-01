// 161. One Edit Distance

// Given two strings S and T, determine if they are both one edit distance apart.

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // s for longer one
        if(t.size() > s.size()) swap(s, t);

        int len_s = s.size();
        int len_t = t.size();

        int diff = len_s - len_t;

        if(diff > 1) return false; // diff bigger than 1, than return false

        else if(diff == 1){
            for(int i=0; i<len_t; i++){
                if(s[i] != t[i]){
                    return s.substr(i+1) == t.substr(i);
                }
            }
            // if the diff is for the last char
            return true;
        }

        else{
            int cnt = 0;

            for(int i=0; i<len_t; i++){
                if(s[i] != t[i]) cnt++;
            }
            return cnt == 1; // must be one, cannot be equal
        }

    }
};

// class Solution {
// public:
//     bool isOneEditDistance(string s, string t) {
//         int min_len = min(s.size(), t.size());

//         for(int i=0; i<min_len; i++){
//             if(s[i] != t[i]){
//                 if(s.size() == t.size()) return s.substr(i+1) == t.substr(i+1);

//                 else if(s.size() > t.size()) return s.substr(i+1) == t.substr(i);

//                 else return s.substr(i) == t.substr(i+1);
//             }
//         }

//         // If the min_len is equal
//         return abs(s.size() - t.size()) == 1;
//     }
// };