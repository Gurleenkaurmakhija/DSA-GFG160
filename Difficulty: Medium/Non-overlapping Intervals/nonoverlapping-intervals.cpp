class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int count =0;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]>intervals[i][0]){
                count++;
                if(intervals[i][1]>ans.back()[1]){
                    continue;
                }else{
                    ans.pop_back();
                    ans.push_back(intervals[i]);
                }
           
            } 
            else{
                ans.push_back(intervals[i]);
            
            }
        }
        return count;
        
        
    }
};
