class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> numpad;
        numpad['2'] = "abc";
        numpad['3'] = "def";
        numpad['4'] = "ghi";
        numpad['5'] = "jkl";
        numpad['6'] = "mno";
        numpad['7'] = "pqrs";
        numpad['8'] = "tuv";
        numpad['9'] = "wxyz";
        
        vector<string> ans;
        combi(digits,numpad,ans,"",0);
        return ans;

        
    }
    void combi(string &digits,unordered_map<char,string> &numpad,vector<string> &ans,string curr,int idx){
        if(idx>=digits.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<numpad[digits[idx]].size();i++){
            curr.push_back(numpad[digits[idx]][i]);
            combi(digits,numpad,ans,curr,idx+1);
            curr.pop_back();
        }

    }
};