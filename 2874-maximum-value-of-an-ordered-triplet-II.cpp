class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        long long diff = 0;
        long long res = 0;

        for(long long num : nums)
        {
            res = max(res, diff * num);
            diff = max(diff, maxi - num);
            maxi = max(maxi, num);
        }
        return res;   
    }
};
