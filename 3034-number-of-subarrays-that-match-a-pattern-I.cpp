class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            int cnt = 0;
            if(i+m >= n) break;
            for(int j = 0; j<m; j++)
            {
                if(pattern[j]==0 && nums[i+j+1]==nums[i+j]) cnt++; 
                else if(pattern[j]==1 && nums[i+j+1]> nums[i+j]) cnt++;
                else if(pattern[j]==-1 && nums[i+j+1]<nums[i+j]) cnt++;
            }

            if(cnt == m) ans++;
        }

        return ans;
    }
};
