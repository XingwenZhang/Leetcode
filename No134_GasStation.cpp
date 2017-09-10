// 134. Gas Station

// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

// Note:
// The solution is guaranteed to be unique.


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        if(len == 0){
            return -1;
        }
        int total = 0, partial_sum = INT_MAX, start = 0;
        // Find the minest total and start by the next index
        for (int i=0; i<len; i++){
            total += gas[i] - cost[i];
            if(total < partial_sum){
                partial_sum = total;
                start = i+1;
            }
        }
        if(total < 0){
            return -1;
        }
        else{
            return start % len;
        }
    }
};