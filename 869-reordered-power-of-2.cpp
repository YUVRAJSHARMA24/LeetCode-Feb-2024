class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        sort(str.begin(), str.end());

        for(int i = 0; i<31; i++)
        {
            int power = pow(2, i);
            string temp = to_string(power);
            sort(temp.begin(), temp.end());
            if(temp == str) return true;
        }

        return false;
    }
};
