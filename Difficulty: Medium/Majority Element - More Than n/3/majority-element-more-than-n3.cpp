class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        vector<int>ans;
        int c1=0,c2=0,ele1=INT_MIN,ele2=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(c1==0 && ele2!=arr[i]){
                ele1=arr[i];
                c1=1;
            }else if(c2==0&& ele1!=arr[i]){
                ele2=arr[i];
                c2++;
            }
            else if(arr[i]==ele1)c1++;
            else if(arr[i]==ele2)c2++;
            else{
                c1--;
                c2--;
            }
        }
        
        c1=0;c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==ele1)c1++;
            if(arr[i]==ele2)c2++;
            
        }
        int mini=(int)(n/3)+1;
        if(c1>=mini)ans.push_back(ele1);
        if(c2>=mini)ans.push_back(ele2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};