class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int, int>>> mp;

        for(auto it : meetings)
        {
            int person1 = it[0];
            int person2 = it[1];
            int time = it[2];

            mp[time].push_back({person1, person2});
        }

        vector<bool> vis(n, false);
        vis[0] = true;
        vis[firstPerson] = true;

        for(auto &it : mp)
        {
            int time = it.first;
            vector<pair<int, int>> p = it.second;

            unordered_map<int, vector<int>>adj;
            queue<int>q;
            set<int> s;

            for(auto &[person1, person2] : p)
            {
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                if(vis[person1] == true && s.find(person1) == s.end()){
                    q.push(person1);
                    s.insert(person1);
                }

                
                if(vis[person2] == true && s.find(person2) == s.end()){
                    q.push(person2);
                    s.insert(person2);
                }
            }

            while(!q.empty())
            {
                int person = q.front();
                q.pop();

                for(auto &next : adj[person])
                {
                    if(vis[next] == false)
                    {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i<n; i++)
        {
            if(vis[i] == true){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
