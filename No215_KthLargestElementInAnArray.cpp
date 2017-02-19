/*215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.*/

//directed method, sort it and find the kth largest element
//time complexity O(nlogn)
/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};*/

// size-k min heap
// time complexity nlogk
/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > heap;
        for(auto elem : nums){
        	if(heap.size()<k){
        		heap.push(elem);
        	}
        	else if(elem > heap.top()){
        		heap.pop();
        		heap.push(elem);
        	}
        }
        return heap.top();
    }
};*/

// max heap 
// time complexity n+klogn
/*class Solution{
public:
	int findKthLargest(vector<int>& nums, int k){
		priority_queue<int> heap(nums.begin(), nums.end());
		for(int i=0; i<k-1; i++){
			heap.pop();
		}
		return heap.top();
	}
};*/

// multiset

class Solution{
public:
	int findKthLargest(vector<int>& nums, int k){
		multiset<int> mulSet;
		for(auto elem : nums){
			mulSet.insert(elem);
			if(mulSet.size() > k){
				mulSet.erase(mulSet.begin());
			}
		}
		return *mulSet.begin();
	}
};


