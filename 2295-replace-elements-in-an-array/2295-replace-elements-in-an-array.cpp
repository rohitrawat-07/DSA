class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        unordered_map<int , int> m;
       for(int i = 0; i < nums.size(); i++){
        m[nums[i]] = i;
       }
       for(int i = 0; i < op.size(); i++){
         if(m.count(op[i][0])){
            int x = m[op[i][0]];
            m[op[i][1]] = x;
            m.erase(op[i][0]);
         }
       }
      for(auto it: m){
        nums[it.second] = it.first;
      }
      return nums;
    }
};