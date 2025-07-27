// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int col0=1;
        int m=mat.size();
        int n=mat[0].size();
        // data structure to trace zeros in n columns--->first row
        // data structure to trace zeoro in m rows--->first column
        
        //int col[n]={0}; -->mat[0][...] //first row
        //int row[m]={0}; -->mat[...][0] //first column
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    //markrow
                     mat[i][0]=0;
                    //mark column
                    //not first column
                    if(j!=0){
                         mat[0][j]=0;
                    }else col0=0;
                }

            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j]=0;
                }
            }
        }
        
        //first mark first row
        
      if(mat[0][0]==0){
          for(int j=1;j<n;j++){
              mat[0][j]=0;
          }
      }
       //second check for column
      if(col0==0){
          for(int i=0;i<m;i++){
              mat[i][0]=0;
          }      }
        
       
        
    }
};



//tc sc=o(k)
//  //imp pair
//         vector<pair<int,int>> ans;
//         int m=mat.sizev();
//         int n=mat[0].size();
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(mat[i][j]==0){
//                     //imp {i,j}
//                     ans.push_back({i,j});
                   
//                 }
//             }
//         }
        
//       for(auto& p:ans){
//           int key=p.first;
//           int value=p.second;
//           for(int j=0;j<n;j++){
//               mat[key][j]=0;
//           }
//           for(int i=0;i<m;i++){
//               mat[i][value]=0;
//           }
           
//       }