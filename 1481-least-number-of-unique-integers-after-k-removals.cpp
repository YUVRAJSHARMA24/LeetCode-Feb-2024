class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto it : arr) mp[it]++;

        vector<int> freq;
        for(auto it : mp)
            freq.push_back(it.second);
        
        sort(freq.begin(), freq.end());
        int cnt = 0;
        for(int i = 0; i<freq.size(); i++)
        {
            if(k > freq[i])
            {
                k -= freq[i];
                freq[i] = 0;
            }
            else
            {
                freq[i] -= k;
                k = 0;
            }

            if(freq[i] != 0) cnt++;
        }

        return cnt;
        
    }
};
