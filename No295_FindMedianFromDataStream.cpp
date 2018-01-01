// 295. Find Median from Data Stream

// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

// Examples: 
// [2,3,4] , the median is 3

// [2,3], the median is (2 + 3) / 2 = 2.5

// Design a data structure that supports the following two operations:

// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.
// For example:

// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2
// Credits:
// Special thanks to @Louis1992 for adding this problem and creating all test cases.

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        // continue;
        // Keep small.size == big.size or small.size == big.size + 1
    }
    
    void addNum(int num) {
        small_part.push(num);
        big_part.push(small_part.top());
        small_part.pop();

        if(small_part.size() < big_part.size()){
            small_part.push(big_part.top());
            big_part.pop();
        }
    }
    
    double findMedian() {
        double median = 0.0;
        if(small_part.size() == big_part.size()){
            double small = small_part.top();
            double big = big_part.top();
            median = (small + big) / 2;
        }
        else if(small_part.size() == big_part.size() + 1){
            median = small_part.top();
        }

        return median;
    }
private:
    priority_queue<int> small_part; // max heap
    priority_queue<int, vector<int>, greater<int> > big_part; // min heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */