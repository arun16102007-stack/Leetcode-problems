class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& arr,int t,int i,vector<int>& curr){
        if(t==0){
            ans.push_back(curr);
            return;
        }
        if(t<0 || i==arr.size()){
            return;
        }
        curr.push_back(arr[i]);
        solve(arr,t-arr[i],i,curr);
        curr.pop_back();
        solve(arr,t,i+1,curr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(candidates,target,0,curr);
        return ans;
    }
};