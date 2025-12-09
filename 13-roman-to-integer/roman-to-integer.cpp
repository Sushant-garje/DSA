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
        for(int i=0;i<s.size();i++){
            // cout<<i<<" "<<ans<<endl;
            // cout<<ans<<endl;
            char a = s[i];
            char b = s[i+1];
            if(RTI[a]<RTI[b]){
                ans = ans+RTI[b]-RTI[a];
                i++;
                continue;

                
                
            }
            

            

            ans = ans+RTI[a];
            cout<<i<<" "<<ans<<endl;
        }
        cout<<ans;
        return ans;
    }
};