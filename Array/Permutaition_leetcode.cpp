class Solution {
    void solve(vector<int>& nums,int i, set<vector<int>>&ans){
        //base case 
        if(i>=nums.size()){
            ans.insert(nums);
            return;
        }
        //recusive case
        for(int j =i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>>ans;
        set<vector<int>>ans;
        int i =0;
        solve(nums,i,ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
