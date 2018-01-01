// 276. Paint Fence

// There is a fence with n posts, each post can be painted with one of the k colors.

// You have to paint all the posts such that no more than two adjacent fence posts have the same color.

// Return the total number of ways you can paint the fence.

// Note:
// n and k are non-negative integers.


int numWays(int n, int k) {
    if(n == 0 || k == 0) return 0;
    if(n == 1) return k;
    int same[n];
    int diff[n];

    same[0] = same[1] = k;
    diff[0] = k;
    diff[1] = k * (k-1);

    for(int i=2; i<n; i++){
        same[i] = diff[i-1];
        diff[i] = same[i-1] * (k-1) + diff[i-1] * (k-1);
    }

    return diff[n-1] + same[n-1];
}