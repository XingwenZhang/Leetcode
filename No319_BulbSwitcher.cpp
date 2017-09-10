// 319. Bulb Switcher

// There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

// Example:

// Given n = 3. 

// At first, the three bulbs are [off, off, off].
// After first round, the three bulbs are [on, on, on].
// After second round, the three bulbs are [on, off, on].
// After third round, the three bulbs are [on, off, off]. 

// So you should return 1, because there is only one bulb is on.


// bulb is finally on iff it is toggled odd times
// bulb is toggled if can divide the i rounds, for example, No.8 bulb is toggled when 1, 2, 4, 8 rounds.
// So if the number of bulb has odd divisors then it will be on. 
// These numbers are squere, like 9: 1, 3, 9; because 3*3, two same divisors
// Convert to find the number of square numbers from 1 to n.
// sqrt(n) is the biggest root of range(1,n). So there are 1-sqrt(n) square numbers.
// Then the results should be sqrt(n)-1+1;

class Solution {
public:
    int bulbSwitch(int n) {
        return int(sqrt(n));
    }
};