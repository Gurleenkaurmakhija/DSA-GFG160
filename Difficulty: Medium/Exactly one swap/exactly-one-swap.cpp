class Solution {
  public:
    int countStrings(string &s) {
    int n = s.length();

    // Vector to count occurrences of each character (assuming lowercase letters)
    vector<int> map(26, 0);

    // Variable to store the total number of distinct strings
    int ans = 0;

    // Count pairs (i, j) where swapping s[i] and s[j] gives a new string
    for (int i = 0; i < n; i++) {
        ans += (i - map[s[i] - 'a']); 
        map[s[i] - 'a']++;
    }

    // If there's any duplicate character, one extra swap can result
    // in same string So, one more distinct outcome is possible
    for (int i = 0; i < 26; i++) {
        if (map[i] > 1) {
            ans++;
            break;
        }
    }

    // Return the total number of distinct strings possible
    return ans;

    }
};
