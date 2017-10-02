// 146. LRU Cache

// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:

// LRUCache cache = new LRUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

//难点在于如果在O(1)时间内实现Put操作。如果是单一的数据结构，就我的知识来说是无法完成这个要求的
//因此想到空间换时间，结合俩个数据结构来实现
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!hash_map.count(key)) return -1;
        // If find key, modify the order of cache
        auto it = hash_map[key];
        cache.splice(cache.begin(), cache, it); // Put it into front, hash_map[key] dont't change, still point to the origin
        return it->second;
    }
    
    void put(int key, int value) {
        // If the key already in hash_map
        if(hash_map.count(key)){
            cache.erase(hash_map[key]);
        }
        cache.push_front(make_pair(key, value));
        hash_map[key] = cache.begin();

        // Capacity
        if(cache.size() > cap){
            auto last = cache.back().first;
            cache.pop_back();
            hash_map.erase(last);
        }
    }

    int cap; // Capacity of cache
    list<pair<int, int> > cache; // Cache
    unordered_map<int, list<pair<int,int> >::iterator> hash_map; // Store key and its location in cache

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */