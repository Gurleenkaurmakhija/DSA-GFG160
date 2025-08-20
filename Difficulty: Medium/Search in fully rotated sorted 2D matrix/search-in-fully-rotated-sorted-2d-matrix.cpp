class Solution {
  public:
   bool searchMatrix(vector<vector<int>> &mat, int x){
    int n = mat.size();      
    int m = mat[0].size();  

    // traverse each element in the matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            
            // check if the current element
            // matches x
            if (mat[i][j] == x) {
                return true;  
            }
        }
    }
    
    // x not found in the entire matrix
    return false;  
}


};
