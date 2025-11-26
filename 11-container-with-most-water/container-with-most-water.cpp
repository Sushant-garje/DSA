class Solution {
public:
    int maxArea(vector<int>& height) {
        int st =0;
        int en =height.size()-1;

        int maxi = 0;
        while(st<=en){
            int h = min (height[st],height[en]);
            int w = en-st;
            int ans = h*w;
            maxi = max(maxi,ans);
            if(height[st]>height[en]){
                en--;
            }
            else{
                st++;
            }

        }

        return maxi;
        
    }
};