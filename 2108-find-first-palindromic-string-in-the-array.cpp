class Solution {
public:
    
    bool isValid(string str, int i, int j)
    {
        while(i < j)
        {
            if(str[i] != str[j]) return false;
            else{
                i++, j--;
            }
        }

        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        string ans = "";

        for(auto it : words)
        {
            string str = it;
            int n = str.size();
            int i = 0, j = n-1;

            if(isValid(str, i, j))
            {
                ans = str;
                break;
            }
            else continue;
        }

        return ans;
    }
};
