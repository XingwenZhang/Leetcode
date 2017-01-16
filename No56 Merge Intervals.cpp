/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public: 
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()){
        	return intervals;
        }

        vector<Interval> res;

        //sort all elements according to their start point
        sort(intervals.begin(), intervals.end(), [](Interval x, Interval y){return x.start<y.start;});

        res.push_back(intervals[0]);

        //judge if need to combine   
        for(int i = 1; i<intervals.size(); i++){
        	if(res.back().end < intervals[i].start){
        		res.push_back(intervals[i]);
        	}
        	else
        	{
        		res.back().end = max(intervals[i].end, res.back().end);
        	}
        }

        return res;
    }
};