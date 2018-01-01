// 253. Meeting Rooms II


// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return 2.


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
    // Use map to store the time and counts
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;

        for(auto &item : intervals){
            ++m[item.start]; // occupy a room
            --m[item.end]; // release a room 
        }

        int res = 0, room = 0;

        for(auto& item : m){
            res = max(res, room += item.second);
        }

        return res;
    }


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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start_time, end_time;
        for(auto& item : intervals){
            start_time.emplace_back(item.start);
            end_time.emplace_back(item.end);
        }

        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());

        int endpos = 0;
        int res = 0;

        for(int i=0; i<intervals.size(); i++){
            if(start_time[i] < end_time[endpos]) res++;
            else endpos++; // If start >= end means the prev meeting has finished
        }

        return res;
    }
};

