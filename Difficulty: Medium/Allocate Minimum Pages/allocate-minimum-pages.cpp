class Solution {
  public:
  int countStudents(vector<int> &arr,int pages){
      int student=1;
      int pageCount=0;
      for(int i=0;i<arr.size();i++){
          if(pageCount+arr[i]<=pages){
              pageCount+=arr[i];
          }
          else{
              student++;
              pageCount=arr[i];
              
          }
      }
      return student;
      
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size())return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(countStudents(arr,mid)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};