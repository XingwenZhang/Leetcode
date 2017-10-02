// 472. Concatenated Words


// Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

// Example:
// Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
//  "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
// Note:
// The number of elements of the given array will not exceed 10,000
// The length sum of elements in the given array will not exceed 600,000.
// All the input string will only include lower case letters.
// The returned elements order does not matter.


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        if(words.size() == 0){
            return res;
        }
        unordered_set<string> hashset(words.begin(), words.end());
        
        for(auto& word : words){
            if(concatenate_util(word, hashset, 0, 0)){
                res.emplace_back(word);
            }
        }
        return res;
    }

    // At least combined by 2
    bool concatenate_util(string& word, unordered_set<string> words, int pos, int cnt){
        if(pos >= word.size() && cnt >= 2){
            return true;
        }
        for(int i=1; i<=word.size()-pos; i++){ // i for the length of substr
            string temp = word.substr(pos, i);
            if(words.count(temp) > 0 && concatenate_util(word, words, pos+i, cnt+1)){
                return true;
            }
        }
        return false;
    }
};


class Solution{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words){
        unordered_set<string> hashset(words.begin(), words.end());
        vector<string> res;
        if(words.size()){
            res.emplace_back("");
            return res;
        }
        for(auto word : words){
            int len = word.size();
            vector<bool> cache(len+1, false); // the previous is Concatenated or not, not incluing the char.at(i)
            cache[0] = true; // No char is true
            for(int i=0; i<len; i++){
                // If the word[start to i-1] is not caoncaatenated, continue
                if(!cache[i])
                    continue;
                for(int j=i+1; j<=len; j++){
                    if(j-i < len && hashset.count(word.substr(i, j-i))){
                        cache[j] = true;
                    }
                }
                if(cache[len]){
                    res.emplace_back(word);
                    break;
                }
            }
        }
        return res;
    }
};

