// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// For example:
// Given "25525511135",

// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)



class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string sol;
        backtrack(res, sol, s, 0, 0);
        return res;
    }

private:
	bool validIP(string IP){
		if(IP[0]=='0' && IP.size()!=1){
			return false;
		}
		int IPnum = stoi(IP);
		if(IPnum >= 0 && IPnum <= 255){
			return true;
		}
		return false;
	}
	void backtrack(vector<string> &res, string & sol, string &s, int pos, int part){
		if(part == 4 && pos == s.size()){
			res.push_back(sol);
		}

		for(int i=pos; i<s.size(); i++){
			if(part < 4 && i-pos < 3 && validIP(s.substr(pos, i-pos+1))){
				sol.append(s.substr(pos, i-pos+1));
				part += 1;
				if(part < 4){
					sol.push_back('.');
				}

				backtrack(res, sol, s, i+1, part);

				if(part < 4){
					// Pop_back '.'
					sol.pop_back();
				}
				part -= 1;

				sol.erase(sol.end()-(i-pos+1), sol.end());

			}
		}
	}
// private:
// 	// Judge if the num is valid [0, 255]
// 	bool validNum(string num){
// 		int n = stoi(num);
// 		if(n>=0 && n<=255){
// 			return true;
// 		}
// 		return false;
// 	}

// 	// Judge if the split is valid
// 	bool validSplit(int restLen, int restNum){
// 		float lenPerN = float(restLen) / restNum;
// 		if(lenPerN > 3){
// 			return false;
// 		}
// 		return true;
// 	}

// 	void IpAddressHelper(vector<vector<string>> &res, vector<string> &tempRes, string &path, string s, int num){
// 		for(auto& i : s){
// 			path += i;
// 			if(path.size() > 3){
// 				break;
// 			}
// 			if(validNum(path) && validSplit(s.size()-path.size(), num)){
// 				tempRes.push_back(path);
// 				path.clear();
// 			}
// 		}
// 	}

};