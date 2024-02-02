class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i = 1; i<9; i++)
        {
            q.push(i);
        }

        vector<int> ans;
        while(!q.empty())
        {
            int num = q.front();
            q.pop();

            if(num >= low && num <= high)
            {
                ans.push_back(num);
            }

            int last = num % 10;
            if(last + 1 <= 9)
            {
                q.push((num * 10) + last + 1);
            }
        }

        return ans;
    }
};
