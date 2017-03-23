// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        vector<string> restemp;
        string interval = "";
        vector<string> dir;
        for(auto& i : path){
        	if(i == '/'){
        		dir.push_back(interval);
        		interval.clear();
        	}
   			else{
   				interval += i;
   			}
        	
        }

        if(!interval.empty()){
        	dir.push_back(interval);
        }

        for(auto& j : dir){
        	if(j == "."){
        		continue;
        	}
        	if(j == ".."){
        		if(!restemp.empty())
        			restemp.pop_back();
        	}
        	// For corner case ///
        	else if(!j.empty())
        		restemp.push_back(j);
        }

        for(auto& k : restemp){
        	res += "/";
        	res += k;
        }
        if(res.empty()){
        	res += "/";
        }

        return res;
    }
};


