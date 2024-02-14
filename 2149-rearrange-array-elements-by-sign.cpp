class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int pos = 0, neg = 1;
        for(auto it : nums)
        {
            if(it > 0)
            {
                ans[pos] = it;
                pos += 2;
            }
            if(it < 0)
            {
                ans[neg] = it;
                neg += 2;
            }
        }
        
        return ans;
    }
};
