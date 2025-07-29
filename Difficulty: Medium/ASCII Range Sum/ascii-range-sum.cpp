class Solution {
  public:
    vector<int> asciirange(string &s) {
    
    // Store positions of each character
    unordered_map<char, vector<int>> pos;
    vector<int> result;

    // Track all occurrences of each character
    for (int i = 0; i < s.size(); i++) {
        pos[s[i]].push_back(i);
    }

    for (auto it : pos) {
        vector<int> idx = it.second;

        // Proceed only if the character 
        // appears more than once
        if (idx.size() >= 2) {
            int first = idx[0];
            int last = idx[idx.size() - 1];
            int sum = 0;

            // Compute ASCII sum of characters strictly 
            // between first and last occurrence
            for (int i = first + 1; i < last; i++) {
                sum += (int)s[i];
            }
            if(sum != 0){
                result.push_back(sum);
            }
        }
    }
    
    return result;
}
};



