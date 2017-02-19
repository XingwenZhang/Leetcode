/*127. Word Ladder
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.*/

// use bfs to search the neighbors

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int> > q;
        vector<bool> visited(wordList.size(),false);
        //int len = 2;

/*        //delete the same word as beginword in wordList
        bool flag = true;
        for(auto ele : wordList){
        	if(ele == beginWord){
        		wordList.erase(find(wordList.begin(), wordList.end(), ele));
        	}
        	if(ele == endWord){
        		flag = false;
        	}

        }
        if (flag){
        	return 0;
        }
*/
        //cannot add the endword into wordList, because it requires the endword should also be in the wordlist
        //wordList.push_back(endWord);
        q.push(make_pair(beginWord,1));
        while(!q.empty()){
        	string query = q.front().first;
        	int len = q.front().second;
        	q.pop();
        	
        	for(int i=0; i<wordList.size(); i++){
        		if(!visited[i] && isNeighbor(query, wordList[i])){
        			q.push(make_pair(wordList[i],len+1));
        			visited[i] = true;
        			//cannot delete element during the loop
        			//wordList.erase(find(wordList.begin(),wordList.end(),ele));
        			if(wordList[i] == endWord){
        				return len+1;
        			}
        		}
        	}
        }
        return 0;
    }
private:
	bool isNeighbor(string& a, string& b){
		if(a.size()!=b.size()){
			return false;
		}
		int count = 0;
		int i = 0;
		while(i<a.size()){
			if(count > 1){
				return false;
			}
			if(a[i]!=b[i]){
				count ++;
			}
			i++;
		}
		return count == 1 ? true: false;
	}
};


// improvement, two end bfs
// todo