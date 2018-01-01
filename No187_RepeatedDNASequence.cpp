// 187. Repeated DNA Sequences

// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

// For example,

// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].

// Directly usage of Rabin Karp, it needs some improvment to store the hash value
class Solution {
public:
    int rabinKarp(string text, string pattern){
        assert(text.size() >= pattern.size());

        int res = 0;

        const int prime = 101;
        const int base = 256;

        int t_hash = 0;
        int p_hash = 0;

        int update_hash = 1;

        // update_hash means how many times base you times during calculate the hash value
        for(int i=0; i<pattern.size() - 1; i++){
            update_hash = update_hash * base % prime;
        }

        for(int i=0; i<pattern.size(); i++){
            p_hash = ((p_hash * base % prime ) + pattern[i] ) % prime;
            t_hash = ((t_hash * base % prime) + text[i]) % prime;
        }
        // Here need to <=, in order to do the last comparsion 
        for(int j=0; j<=text.size() - pattern.size(); j++){
            // If equal hash value, it has probability to be the same
            if(t_hash == p_hash){
                int k = 0;
                for(k=0; k<pattern.size(); k++){
                    if(pattern[k] != text[j+k]) break;
                }
                if(k == pattern.size()){
                    res++;
                }
            }

            // If the hash value is not equal, update the hash value by 
            // rolling hash
            // Add prime to avoid the negative hash value
            if(j < text.size() - pattern.size()){
                t_hash = ((t_hash - update_hash * text[j])
                    * base % prime  + text[j+pattern.size()]) % prime;
                if(t_hash < 0) t_hash += prime;
            }
            
        }

        return res;

    }

    vector<string> findRepeatedDnaSequences(string s) {
        set<string> res;
        if(s.size() < 10) return vector<string>(res.begin(), res.end());
        string pattern;
        for(int i=0; i<s.size()-10; i++){
            pattern = s.substr(i, 10);

            if(res.count(pattern) == 0 && rabinKarp(s, pattern) > 1){
                res.insert(pattern);
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};




bool sameString(string& s, unordered_multimap<int,string> multi_hash, int key){
    auto range = multi_hash.equal_range(key);
    for(auto iter = range.first; iter != range.second; iter++){
        if (s == iter->second){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int base = 256;
        const int prime = 101;
        const int pattern_length = 10;
        int update_hash = 1;

        int p_hash = 0;

//        set<pair<int, string>> unique_hash;
        unordered_multimap<int, string> unique_hash;
        unordered_set<string> repeated_string;

        // Update_hash calculation
        for(int i=0; i<pattern_length-1; i++){
            update_hash = update_hash * base % prime;
        }

        for(int i=0; i<s.size(); i++){
            if(i < pattern_length)
                p_hash = (p_hash * base + s[i]) % prime;

            // update p_hash
            if (i > pattern_length - 1){
                p_hash = ((p_hash - update_hash * s[i-pattern_length]) * base + s[i]) % prime;
                if(p_hash < 0) p_hash += prime;
                //cout << "every hash value " << p_hash << endl;
            }

            if (i > pattern_length - 2){
                string sub_string = s.substr(i-pattern_length+1, pattern_length);
                if(!unique_hash.count(p_hash) || (unique_hash.count(p_hash) && !sameString(sub_string, unique_hash, p_hash))) {
                    unique_hash.insert(make_pair(p_hash, s.substr(i-pattern_length+1, pattern_length)));
                    //cout << "set hash " << p_hash << endl;
                }
                else {

                    repeated_string.insert(s.substr(i-pattern_length+1, pattern_length));
                    //cout << "p_hash " << p_hash << " string " << s.substr(i-pattern_length+1, pattern_length) << endl;
                }
            }
        }
        vector<string> res(repeated_string.begin(), repeated_string.end());
        return res;
    }
};



// No use of hash, directly store the string, pass
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res, unique;
        const int pattern_length = 10;
        for(int i=0; i + pattern_length <= s.size(); i++){
            string tmp = s.substr(i, pattern_length);
            if(unique.count(tmp)) res.insert(tmp);
            else{
                unique.insert(tmp);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};