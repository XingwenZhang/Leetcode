// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


// The largest rectangle is shown in the shaded area, which has area = 10 unit.

// For example,
// Given heights = [2,1,5,6,2,3],
// return 10.


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	// Two stacks are sync
        stack<int> position;
        stack<int> high;
        // If the vector is empty, then the result is just 0
        int max_area = 0;
        int len = heights.size();
        int start_point = -1;
        int area = 0;
        for(int i=0; i<len; i++){
        	if(high.empty() || heights[i] > high.top()){
        		high.push(heights[i]);
        		position.push(i);
        	}
        	// heights[i] < high.top()
        	while(!high.empty() && heights[i] <= high.top()){
        		area = high.top() * (i-position.top());
        		high.pop();
        		// Keep position, which is the start point for the small rectange
        		start_point = position.top();
        		position.pop();
        		

        		// Update max_area
        		if(area > max_area){
        			max_area = area;
        		}
        	}

        	// Here the heights[i] is bigger than high.top()
        	high.push(heights[i]);
        	position.push(start_point);
        }

        // Handle the rest elements in stack
        while(!high.empty()){
        	area = high.top() * (len - position.top());
        	if(area > max_area){
        		max_area = area;
        	}
        	high.pop();
        	position.pop();
        }

        return max_area;
    }
};