class Solution {
public:
void solve(vector<int>& nums,int i, set<vector<int>>&ans){
    //base case 
    if(i>=nums.size()){
        ans.insert(nums);
        return;
    }
    for(int j =i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        solve(nums,i+1,ans);
        swap(nums[i],nums[j]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        int i =0;
        solve(nums,i,ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
