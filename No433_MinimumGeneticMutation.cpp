// 433. Minimum Genetic Mutation

// A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

// Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

// For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

// Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

// Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

// Note:

// Starting point is assumed to be valid, so it might not be included in the bank.
// If multiple mutations are needed, all mutations during in the sequence must be valid.
// You may assume start and end string is not the same.
// Example 1:

// start: "AACCGGTT"
// end:   "AACCGGTA"
// bank: ["AACCGGTA"]

// return: 1
// Example 2:

// start: "AACCGGTT"
// end:   "AAACGGTA"
// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

// return: 2
// Example 3:

// start: "AAAAACCC"
// end:   "AACCCCCC"
// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

// return: 3

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string, int> > q;
        q.push(make_pair(start, 0));
        vector<bool> visited(bank.size(), false);
        while (!q.empty()){
            string prev = q.front().first;
            int len = q.front().second;
            q.pop();
            for(int i=0; i<bank.size(); i++){
                if(!visited[i] && isNeighbor(prev, bank[i])){
                    q.push(make_pair(bank[i], len+1));
                    visited[i] = true;
                    if(bank[i] == end){
                    return len+1;
                    }
                }
                
            }

        }
        return -1;

    }

    bool isNeighbor(const string& a, const string& b){
        int cnt = 0;
        if(a.size() != b.size())
            return false;

        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i])
                cnt ++;
            if(cnt > 1)
                return false;
        }
        return cnt == 1 ? true : false;
    }
};