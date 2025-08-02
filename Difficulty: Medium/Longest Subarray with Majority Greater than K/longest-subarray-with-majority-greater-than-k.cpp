class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k){
    int n = arr.size();
    unordered_map<int, int> mp;
    int ans = 0, sum = 0;

    for (int i = 0; i < n; ++i)
    {
        // Treat elements <= k as -1, elements > k as +1
        if (arr[i] <= k) sum-- ;
        else sum++ ;

        // If overall sum is positive, entire prefix is valid
        if (sum > 0) ans = i + 1;
        else
        {
            // Check if there was a prefix with sum = current_sum - 1
            if (mp.find(sum - 1) != mp.end()) {
                ans = max(ans, i - mp[sum - 1]);
            }
        }

        // Store the first occurrence of each prefix sum
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return ans;
}

};