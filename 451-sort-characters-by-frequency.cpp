class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto i : s) mp[i]++;
        
        priority_queue<pair<int, char>>pq;
        for(auto j : mp) pq.push({j.second, j.first});
        
        s = "";
        while(!pq.empty()){
            s += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        
        return s;
    }
};
