// 170. Two Sum III - Data structure design

// Design and implement a TwoSum class. It should support the following operations: add and find.

// add - Add the number to an internal data structure.
// find - Find if there exists any pair of numbers which sum is equal to the value.

// For example,
// add(1); add(3); add(5);
// find(4) -> true
// find(7) -> false

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        // hash_map.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        hash_map[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto& item : hash_map){
            item.second--;
            if(hash_map.count(value - item.first) && (hash_map[value - item.first] > 0)){
                item.second++;
                return true;
            }
            item.second++;
        }
        return false;
    }
private:
    // the find function must consider the count of the number
    unordered_map<int, int> hash_map; // number, times
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */