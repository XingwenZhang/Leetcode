// 249. Group Shifted Strings

// Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

// "abc" -> "bcd" -> ... -> "xyz"
// Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

// For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
// A solution is:

// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]


class Solution {
public:

    // The assumption is wrong, not must be arithmetic progression
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;

        map<pair<int,int>, vector<int> > hash_map; // key for arithmetic progression and length, value for the index of same index

        for(int i=0; i<strings.size(); i++){
            int len = strings[i].size();
            int common_diff;
            if(len != 1) {
                common_diff = (strings[i].back() - strings[i].front()) / (len-1);
                if(common_diff < 0){
                    common_diff = (common_diff + 26) %26;
                }
            }
            else common_diff = 0;

            hash_map[{common_diff, len}].push_back(i);
        }

        vector<string> tmp;
        for(auto& item : hash_map){
            for(auto& index : item.second){
                tmp.push_back(strings[index]);
            }
            res.push_back(tmp);
            tmp.clear();
        }

        return res;
    }
};

// AC
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;

        map<string, vector<int> > hash_map; // key for diff in a string

        for(int i=0; i<strings.size(); i++){
            string key = "";

            for(int j=0; j<strings[i].size(); j++){
                key += (strings[i][j] - strings[i][0] + 26 ) % 26; // avoid neg value
            }

            hash_map[key].push_back(i);
        }

        vector<string> tmp;
        for(auto& item : hash_map){
            for(auto& index : item.second){
                tmp.push_back(strings[index]);
            }
            res.push_back(tmp);
            tmp.clear();
        }

        return res;
    }
};


