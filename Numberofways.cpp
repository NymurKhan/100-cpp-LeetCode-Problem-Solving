class Solution {
  public: const int mod = 1e9 + 7;
  long long dp[510][510];
  long long solve(int steps, int n, int ind) {
    /* base case, if we have exhausted all our steps then return 1 only if we are on ind = 0 */
    if (steps == 0) return ind == 0;
    // check if we alredy computed this subproblem
    if (dp[ind][steps] != -1) return dp[ind][steps];
    long long res = 0;
    //check if we can go to right , if possible then go to right
    if (ind + 1 < n) res += solve(steps - 1, n, ind + 1);
    //check if we can go to left , if possible then go to left
    if (ind - 1 >= 0) res += solve(steps - 1, n, ind - 1);
    //stay on same index
    res += solve(steps - 1, n, ind);
    return dp[ind][steps] = res % mod;
  }
  int numWays(int steps, int n) {
    // initialising dp array with -1
    memset(dp, -1, sizeof(dp));
    return (int) solve(steps, n, 0);
  }
};