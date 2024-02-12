class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele, cnt = 0;

        for(int i = 0; i<n; i++)
        {
            if(cnt == 0)
            {
                cnt++;
                ele = nums[i];
            }
            else if(cnt == nums[i]) cnt++;
            else cnt--;
        }

        int cnt1 = 0;
        for(int i = 0; i<n; i++)
        {
            if(ele == nums[i]) cnt1++;
        }

        return cnt1 > n/2 ? ele : -1;
    }
};
