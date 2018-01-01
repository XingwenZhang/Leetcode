// 605. Can Place Flowers

// Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

// Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: True
// Example 2:
// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: False
// Note:
// The input array won't violate no-adjacent-flowers rule.
// The input array size is in the range of [1, 20000].
// n is a non-negative integer which won't exceed the input array size.

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.empty()) return false;

        // Why this doesn't work?
        // if(*(flowerbed.begin()) == 0) flowerbed.insert(flowerbed.begin(), 0);
        // if(*(flowerbed.end()) == 0) flowerbed.push_back(0);

        if(flowerbed.front() == 0) flowerbed.insert(flowerbed.begin(), 0);
        if(flowerbed.back() == 0) flowerbed.push_back(0);

        int len = flowerbed.size(), cnt = 0, sum = 0;

        for(int i=0; i<len; i++){
        	if(flowerbed[i] == 0) ++cnt;
        	else{
        		sum += (cnt - 1) / 2;
        		cnt = 0;
        	}
        }

        if(cnt != 0){
        	sum += (cnt - 1) / 2;
        }

        return sum >= n;
    }
};