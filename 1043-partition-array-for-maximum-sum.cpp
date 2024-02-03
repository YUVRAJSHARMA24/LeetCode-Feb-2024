class Solution {
public:

    int solve(vector<int> &arr, int k, int ind, int n, vector<int> &dp)
    {
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int res = 0;
        int maxi = -1;
        for(int i = ind; i < n && i - ind + 1 <= k; i++)
        {
            maxi = max(maxi, arr[i]);
            res = max(res, ((i-ind+1)*maxi) + solve(arr, k, i+1, n, dp));
        }

        return dp[ind] = res;
    } 

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, -1);
        return solve(arr, k, 0, n, dp);
    }
};
