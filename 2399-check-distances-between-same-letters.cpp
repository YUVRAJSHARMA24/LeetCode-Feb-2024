class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = distance.size();
        unordered_map<char, int> mp;

        for(int i = 0; i<s.size(); i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                int dist = i - mp[s[i]]-1;
                if(distance[s[i] - 'a'] != dist){
                    return false;
                }
            }
            else{
                mp[s[i]] = i;
            }
        }

        return true;
    }
};
