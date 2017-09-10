// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

// Below is one possible representation of s1 = "great":

//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two children.

// For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that "rgeat" is a scrambled string of "great".

// Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that "rgtae" is a scrambled string of "great".

// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.


// Solution 1, recursive compare two strings
// Time complexity: O(3^n)
// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         if(s1.empty() || s2.empty()){
//           return false;
//         }
//         if(s1.size() != s2.size()){
//           return false;
//         }
//         return rec(s1, s2);
//     }

//     bool rec(string s1, string s2){
//       int len = s1.size();
//       if(len == 1){
//         return s1 == s2;
//       }

//       // s1's left compares with s2's left
//       // s1's left compares with s2's right
//       for(int i=1; i<len; i++){
//         if(rec(s1.substr(0,i), s2.substr(0,i)) && rec(s1.substr(i,len), s2.substr(i,len))){
//           return true;
//         }
//         if(rec(s1.substr(0,i), s2.substr(len-i, len)) && rec(s1.substr(i,len), s2.substr(0, len-i))){
//           return true;
//         }
//       }
//       return false;
//     }
// };


// Solution 2, recusive compare two strings with sorting pruning
// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         if(s1.empty() || s2.empty()){
//             return false;
//         }
//         if(s1.size() != s2.size()){
//           return false;
//         }
//         string s1_temp = s1;
//         string s2_temp = s2;
//         sort(s1_temp.begin(), s1_temp.end());
//         sort(s2_temp.begin(), s2_temp.end());
//         if(s1_temp.compare(s2_temp) != 0){
//           return false;
//         }
//         return rec(s1,s2);
//     }
//     bool rec(string s1, string s2){
//       int len = s1.size();
//       if(len == 1){
//         return s1 == s2;
//       }

//       // s1's left compares with s2's left
//       // s1's left compares with s2's right
//       for(int i=1; i<len; i++){
//         if(rec(s1.substr(0,i), s2.substr(0,i)) && rec(s1.substr(i,len), s2.substr(i,len))){
//           return true;
//         }
//         if(rec(s1.substr(0,i), s2.substr(len-i, len)) && rec(s1.substr(i,len), s2.substr(0, len-i))){
//           return true;
//         }
//       }
//       return false;
//     }
// };


// Solution 3 recursion with memory
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.empty() || s2.empty()){
          return false;
        }
        if(s1.size() != s2.size()){
          return false;
        }
        int len = s1.size();
        int ***mem = new int **[len];
        for(int i=0; i<len; i++){
          mem[i] = new int *[len];
          for(int j=0; j<len; j++){
            mem[i][j] = new int[len];
          }
        }
      
        for(int i=0; i<len; i++){
          for(int j=0; j<len; j++){
            for(int k=0; k<len; k++){
              mem[i][j][k] = -1;
            }
          }
        }
        return rec_with_mem(s1,0,s2,0,len,mem);
    }

    bool rec_with_mem(string s1, int index1, string s2, int index2, int len, int*** mem){
      if(len == 1){
        return s1.at(index1) == s2.at(index2);
      }

      int ret = mem[index1][index2][len-1];
      if(ret != -1){
        return ret == 1?true:false;
      }

      ret = 0;

      for(int i=1; i<len; i++){
        if(rec_with_mem(s1,index1,s2,index2, i, mem)&&rec_with_mem(s1, index1+i, s2, index2+i, len-i, mem)){
          ret = 1;
          break;
        }
        if(rec_with_mem(s1, index1, s2, index2+len-i, i, mem) &&
          rec_with_mem(s1, index1+i, s2, index2, len-i,mem)){
          ret = 1;
          break;
        }
      }
      mem[index1][index2][len-1] = ret;
      return ret == 1?true:false;
    }
};