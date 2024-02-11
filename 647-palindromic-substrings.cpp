class Solution {
public:
    
    bool isValid(string s, int i, int j, vector<vector<int>> &dp)
    {
        if(i >= j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = isValid(s, i+1, j-1, dp);

        return dp[i][j] = false;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                if(isValid(s, i, j, dp))
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
