class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        int res = 0;
        int maxSum = 0;

        // Find maximum sum across all rows
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++)
                sum += mat[i][j];
            maxSum = max(sum, maxSum);
        }

        // Find maximum sum across all columns
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += mat[i][j];
            maxSum = max(sum, maxSum);
        }

        // Sum of operations across all rows
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += mat[i][j];
            }
            res += (maxSum - sum);
        }
        return res;
    }
};