class Solution {
public:

	//using two unordered_map
    vector<int> findSubstring(string s, vector<string>& words) 
    {
    	vector<int> ans;
    	int wordsNum = words.size();

    	if(!wordsNum) return ans;

    	int wordLen = words[0].size();

    	//store all words
    	unordered_map<string,int> wordStore;
    	

    	//store all words
    	for(auto i:words)
    	{
    		wordStore[i]++;
    	}

    	//test if exist
    	unordered_map<string,int> test;

    	//all word's length is equal
    	for(int i=0; i<s.size()-wordLen*wordsNum+1; i++)
    	{
    		int j;
    		for(j=0; j<wordsNum; j++)
    		{
    			//find another word
    			string word = s.substr(i+j*wordLen,wordLen);

    			//find if exists
    			if(wordStore.find(word)!=wordStore.end())
    			{
    				test[word]++;

    				//the combination goes over the number
    				if(test[word]>wordStore[word])
    				{
    					break;
    				}
    			}
    			else
    			{
    				break;
    			}

    		}

   			//clear test everytime
   			test.clear();

    		//j==wordsNum means exist
    		if(j==wordsNum)
    		{
    			ans.push_back(i);
    		}
    	}
    	return ans;
    }
};