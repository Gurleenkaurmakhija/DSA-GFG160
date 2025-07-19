class Solution {
  public:
    int fact(int n) {
    int res = 1;
   
    // Calculate factorial using a loop
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

// Function to count distinct vowels
// and their frequencies
int vowelCount(string &s) {
    unordered_map<char, int> freq;
    string vowels = "aeiou";
    
    // Count frequency of each vowel in the string
    for (char c : s) {
        if (vowels.find(c) != string::npos) {
            freq[c]++;
        }
    }
    if (freq.empty()) return 0;
    int choices = 1;
    
    // Calculate choices based on frequency of vowels
    for (auto entry : freq) {
        choices *= entry.second;
    }
    int dist = freq.size();
    
    // Calculate result as choices multiplied
    // by factorial of distinct vowels
    int res = choices * fact(dist);
    return res;
}

};