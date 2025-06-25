class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int>&arr,int st,int mid,int end){
        int i=st;
        int j=mid+1;
        vector<int>temp;
        int inv=0;
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                inv+=mid-i+1;
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(arr[j]);
            j++;
        }
        for(int idx=0;idx<temp.size();idx++){
            arr[st+idx]=temp[idx];
        }
        return inv;
    }
    
    int mergeSort(vector<int>&arr,int st,int end){
        if(st>=end) return 0;
        
        int mid=st+(end-st)/2;
        int leftInv=mergeSort(arr,st,mid);
        int rightInv=mergeSort(arr,mid+1,end);
        int inv=merge(arr,st,mid,end);
        return leftInv+rightInv+inv;
        
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return mergeSort(arr,0,arr.size()-1);
    }
};