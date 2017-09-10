// 354. Russian Doll Envelopes

// You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

// What is the maximum number of envelopes can you Russian doll? (put one inside other)

// Example:
// Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).


class Solution {
public:
    static bool compare_pair(pair<int, int> a, pair<int,int> b){ // Here static !!!
            return a.first < b.first;
        }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() == 0)
            return 0;
        vector<int> cache(envelopes.size(), 1);
        
        sort(envelopes.begin(), envelopes.end(), compare_pair);
        for(int i=1; i<envelopes.size(); i++){
            for(int j=0; j<i; j++){
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second && cache[i] < cache[j]+1){
                    cache[i] = cache[j] + 1;
                }
            }
        }   
        int max_num = INT_MIN;
        for(int k=0; k<cache.size(); k++){
            if(cache[k] > max_num){
                max_num = cache[k];
            }
        }
        return max_num;
    }
};


class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        pair<int,int> prev (0,0);
        return envelope_util(0, envelopes.size()-1, envelopes, prev);
    }
    int envelope_util(int left, int right, vector<pair<int,int>>& vp, pair<int,int>& prev){
        if(left > right){
            return 0;
        }
        int res = 0;
        for(int i=left; i<=right; i++){
            if(vp[i].first > prev.first && vp[i].second > prev.second){
                res = max(res, max(envelope_util(left, i-1, vp, vp[i])+1, envelope_util(i+1, right, vp, vp[i])+1));
            }
            else{
                res = max(res, max(envelope_util(left, i-1, vp, prev), envelope_util(i+1, right, vp, prev)));
            }
        }
        return res;
    }
};



class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        pair<int,int> prev (0,0);
        return envelope_util2(envelopes, envelopes.size(), prev);
    }
    int envelope_util2(vector<pair<int,int>>& vp, int n, pair<int,int>& prev){
        if(n == 0){
            return 0;
        }
        int res = 0;
        for(int i=0; i<vp.size(); i++){
            if(vp[i].first > prev.first && vp[i].second > prev.second){
                res = max(res, envelope_util2(vp, n-1, vp[i])+1);
            }
            else{
                res = max(res, envelope_util2(vp, n-1, prev));
            }
        }
        return res;
    }
};



class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        pair<int,int> prev (0,0);
        envelopes.push_back(prev);
        vector<vector<int> > cache(envelopes.size()+1, vector<int>(envelopes.size()+1, 0));
        return envelope_util3(envelopes, envelopes.size()-1, envelopes.size()-1, cache);
    }
    int envelope_util3(vector<pair<int,int>>& vp, int n, int prev, vector<vector<int>>& cache){
        if(n == 0){
            return 0;
        }
        if(cache[n][prev] != 0){
            return cache[n][prev];
        }
        int res = 0;
        for(int i=0; i<vp.size(); i++){
            if(vp[i].first > vp[prev].first && vp[i].second > vp[prev].second){
                res = max(res, envelope_util3(vp, n-1, i, cache)+1);
            }
            else{
                res = max(res, envelope_util3(vp, n-1, prev, cache));
            }
        }
        return cache[n][prev] = res;

    }
};




// TLE 这道题的测试对递归不友好啊，2333333，暂时只有排序按照LIS那题做的方法AC
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        pair<int,int> prev (0,0);
        envelopes.push_back(prev);
        vector<int> cache(envelopes.size()+1, 0);
        return envelope_util4(envelopes, envelopes.size()-1, cache);
    }
    int envelope_util4(vector<pair<int,int>>& vp, int prev, vector<int>& cache){
        if(cache[prev] != 0){
            return cache[prev];
        }
        int res = 0;
        for(int i=0; i<vp.size()-1; i++){
            if(vp[i].first > vp[prev].first && vp[i].second > vp[prev].second){
                res = max(res, envelope_util4(vp, i, cache)+1);
            }
        }
        return cache[prev] = res;
    }
};