// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, I'll tell you whether the number is higher or lower.

// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

// -1 : My number is lower
//  1 : My number is higher
//  0 : Congrats! You got it!
// Example:
// n = 10, I pick 6.

// Return 6.


// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	// Pay attentation of My number, "My" here means the unknown number
    int guessNumber(int n) {
        int low = 1, high = n;
        int guess_num = 0;
        while(true){
            // Overflow
        	//guess_num = (low + high) / 2;
        	guess_num = (high-low)/2 + low;
        	int flag = guess(guess_num);
        	if(flag == 0){
        		return guess_num;
        	}
        	else if(flag > 0){
        		low = guess_num + 1;
        	}
        	else{
        		high = guess_num - 1;
        	}

        }
    }
};