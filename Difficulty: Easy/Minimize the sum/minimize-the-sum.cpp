// User function Template for C++

class Solution {
  public:
    int minimizeSum(int n, vector<int> arr) {
        // code here
        int sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        while(pq.size()>1){
            int temp=0;
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            temp=a+b;
            sum+=temp;
            pq.push(temp);
            
        }
        return sum;
    }
};