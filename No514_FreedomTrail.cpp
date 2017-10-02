// 514. Freedom Trail

// In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.

// Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.

// Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button. 
// At the stage of rotating the ring to spell the key character key[i]:
// You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
// If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
// Example:

// Input: ring = "godding", key = "gd"
// Output: 4
// Explanation:
//  For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
//  For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
//  Also, we need 1 more step for spelling.
//  So the final output is 4.
// Note:
// Length of both ring and key will be in range 1 to 100.
// There are only lowercase letters in both strings and might be some duplcate characters in both strings.
// It's guaranteed that string key could always be spelled by rotating the string ring.


class Solution {
public:
    int findRotateSteps(string ring, string key) {
        return find_key(ring, key, 0, 0, 0);
    }
    int find_key(string ring, string key, int flag, int index1, int index2){
        if(index2 >= key.size()){
            return 0;
        }
        if(index1 >= (int)ring.size()){
            index1 = index1 % ring.size();
        }
        if(index1 < 0){
            index1 = (int)ring.size() + index1;
        }
        if(ring[index1] == key[index2]){
            return 1 + find_key(ring, key, 0, index1, index2+1);
        }
        else{
            int res = INT_MAX;
            if(flag == 1)
                res = min(res, find_key(ring, key, 1, index1+1, index2)+1);
            else if(flag == -1)
                res = min(res, find_key(ring, key, -1, index1-1, index2)+1);
            else
                res = min(1+find_key(ring, key, 1, index1+1, index2), 1+find_key(ring,key, -1, index1-1, index2));

            return res;
        }
    }
};



// NOT AC, because don't consider direction, diff direc, diff results.
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int> >cache(ring.size(), vector<int>(key.size(), -1));
        return find_key2(ring, key, 0, 0, 0, cache);
    }
    int find_key2(string ring, string key, int flag, int index1, int index2, vector<vector<int> >& cache){
        if(index2 >= key.size()){
            return 0;
        }

        if(index1 >= (int)ring.size()){
            index1 = index1 % ring.size();
        }
        if(index1 < 0){
            index1 = (int)ring.size() + index1;
        }

        if(cache[index1][index2] != -1){
            return cache[index1][index2];
        }
        if(ring[index1] == key[index2]){
            return cache[index1][index2] = 1 + find_key2(ring, key, 0, index1, index2+1, cache);
        }
        else{
            int res = INT_MAX;
            if(flag == 1)
                res = min(res, find_key2(ring, key, 1, index1+1, index2, cache)+1);
            else if(flag == -1)
                res = min(res, find_key2(ring, key, -1, index1-1, index2, cache)+1);
            else
                res = min(1+find_key2(ring, key, 1, index1+1, index2, cache), 1+find_key2(ring,key, -1, index1-1, index2, cache));

            return cache[index1][index2] = res;
        }
    }
};

// AC
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<vector<int> >>cache(3, vector<vector<int>>(ring.size(), vector<int>(key.size(),-1)));
        return find_key2(ring, key, 0, 0, 0, cache);
    }
    int find_key2(string ring, string key, int flag, int index1, int index2, vector<vector<vector<int> >>& cache) {
        if (index2 >= key.size()) {
            return 0;
        }

        if (index1 >= (int)ring.size()) {
            index1 = index1 % ring.size();
        }
        if (index1 < 0) {
            index1 = (int)ring.size() + index1;
        }

        if (cache[flag][index1][index2] != -1) {
            return cache[flag][index1][index2];
        }
        if (ring[index1] == key[index2]) {
            return cache[flag][index1][index2] = 1 + find_key2(ring, key, 0, index1, index2 + 1, cache);
        }
        else {
            int res = INT_MAX;
            if (flag == 1)
                res = min(res, find_key2(ring, key, 1, index1 + 1, index2, cache) + 1);
            else if (flag == 2)
                res = min(res, find_key2(ring, key, 2, index1 - 1, index2, cache) + 1);
            else
                res = min(1 + find_key2(ring, key, 1, index1 + 1, index2, cache), 1 + find_key2(ring, key, 2, index1 - 1, index2, cache));

            return cache[flag][index1][index2] = res;
        }
    }
};
