
// 672. Bulb Switcher II

// There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.

// Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

// Flip all the lights.
// Flip lights with even numbers.
// Flip lights with odd numbers.
// Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
// Example 1:
// Input: n = 1, m = 1.
// Output: 2
// Explanation: Status can be: [on], [off]
// Example 2:
// Input: n = 2, m = 1.
// Output: 3
// Explanation: Status can be: [on, off], [off, on], [off, off]
// Example 3:
// Input: n = 3, m = 1.
// Output: 4
// Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].
// Note: n and m both fit in range [0, 1000].

// // This method is correct but is over memory limit


// // class Solution {
// // public:
// //     int flipLights(int n, int m) {
// //         vector<vector<int> > res;
// //         vector<int> v;
// //         comb(res, v, m, 1, 4);
// //         vector<bool> bulb(n, true);
// //         set<vector<bool> > s;
// //         for(auto v_i : res){
// //             for(auto i : v_i){
// //                 if(i == 1){
// //                     bulb.flip();
// //                 }
// //                 else if(i==2){ 
// //                     for(int k=2; k<=n; k+=2){
// //                         bulb[k-1] = !bulb[k-1];
// //                     }
// //                 }
// //                 else if(i==3){ 
// //                     for(int k=1; k<=n; k+=2){
// //                         bulb[k-1] = !bulb[k-1];
// //                     }
// //                 }
// //                 else{
// //                     for(int k=0; 3*k+1<= n; k++){ // 3*k+1-1, index begins with 0
// //                         bulb[3*k] = !bulb[3*k];
// //                     }
// //                 }
// //             }
// //             s.insert(bulb);
            
// //             for(int i = 0; i<n; i++){
// //                 bulb[i] = true;
// //             }
// //         }
// //         return s.size();
// //     }
// //     void comb(vector<vector<int> >& res, vector<int>& v, int m, int L, int R){
// //         for(int i=L; i<=R; i++){
// //             if(!m){ // terminate
// //                 res.push_back(v);
// //                 return;
// //             }
// //             else{
// //                 v.push_back(i);
// //                 comb(res, v, m-1, L, R);
// //                 v.pop_back();
// //             }
// //         }
// //     }
// // };

// // This method is time limit

// class Solution {
// public:
//     int flipLights(int n, int m) {
//         set<vector<bool> > s;
//         vector<int> v;
//         comb(s, v, n, m, 1, 4);
//         return s.size();
//     }
//     void comb(set<vector<bool> >& s, vector<int>& v, int n, int m, int L, int R){
//         for(int i=L; i<=R; i++){
//             if(!m){
//                 s.insert(operate_bulb(n,v));
//                 return;
//             }
//             else{
//                 v.push_back(i);
//                 comb(s, v, n, m-1, L, R);
//                 v.pop_back();
//             }
//         }
//     }
//     inline vector<bool> operate_bulb(int n, vector<int>& v){
//         vector<bool> bulbs(n, true);
//         vector<int> odd_even(5, 1);
//         for(auto i : v){
//             odd_even[i] *= -1;
//         }
//         vector<int> simplified_v;
//         for(int i=1; i<5; i++){
//             if(odd_even[i] == -1){
//                 simplified_v.push_back(i);
//             }
//         }
//         for(auto i : simplified_v){
//             if(i==1){
//                 bulbs.flip();
//             }
//             else if(i==2){
//                 for(int k=2; k<=n; k+=2){
//                     bulbs[k-1] = !bulbs[k-1];
//                 }
//             }
//             else if(i==3){
//                 for(int k=1; k<=n; k+=2){
//                     bulbs[k-1] = !bulbs[k-1];
//                 }
//             }
//             else{
//                 for(int k=0; 3*k+1<=n; k++){
//                     bulbs[3*k] = !bulbs[3*k];
//                 }
//             }
//         }
//         return bulbs;
//     }
// };


class Solution {
public:
    int flipLights(int n, int m) {
        if (m == 0 || n == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return m == 1? 3:4;
        if (m == 1) return 4;
        return m == 2? 7:8;
    }
};