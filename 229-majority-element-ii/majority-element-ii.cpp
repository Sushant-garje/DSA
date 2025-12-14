class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int > ans = {};
        int k = nums.size()/3;
        unordered_map<int,int> map ;
        for(int i =0;i<nums.size();i++){          
                map[nums[i]]++;     
        }
        for (auto i = map.begin(); i != map.end(); i++){
            if(i->second>k) ans.push_back(i->first);
        }
        // cout << i->first << "       " << i->second << endl;
        return ans;
        
    }
};