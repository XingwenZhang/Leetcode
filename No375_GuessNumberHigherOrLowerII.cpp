// 375. Guess Number Higher or Lower II

// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

// However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

// Example:

// n = 10, I pick 8.

// First round:  You guess 5, I tell you that it's higher. You pay $5.
// Second round: You guess 7, I tell you that it's higher. You pay $7.
// Third round:  You guess 9, I tell you that it's lower. You pay $9.

// Game over. 8 is the number I picked.

// You end up paying $5 + $7 + $9 = $21.
// Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > cache(n+1, vector<int>(n+1, 0));
        return money_util(1, n, cache);
    }
    int money_util(int left, int right, vector<vector<int> >& cache){ // left to right min money that guarantee a win
        if(left >= right){
            return 0;
        }
        if(cache[left][right] != 0){
            return cache[left][right];
        }
        int res = INT_MAX;
        for(int i=left; i<=right; i++){
            res = min(res, i + max(money_util(left, i-1, cache), money_util(i+1, right, cache))); // target is at left part or right part
        }
        return cache[left][right] = res;
    }
};