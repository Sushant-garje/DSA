class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> RTI;
        RTI['I'] = 1;
        RTI['V'] = 5;
        RTI['X'] = 10;
        RTI['L'] = 50;
        RTI['C'] = 100;
        RTI['D'] = 500;
        RTI['M'] = 1000;

        int ans =0;
        for (int i = 0; i < s.size(); i++) {
            int curr = RTI[s[i]];

            if (i + 1 < s.size() && curr < RTI[s[i + 1]]) {
                ans += RTI[s[i + 1]] - curr;
                i++; 
            } else {
                ans += curr;
            }
        }
        return ans;
    }
};