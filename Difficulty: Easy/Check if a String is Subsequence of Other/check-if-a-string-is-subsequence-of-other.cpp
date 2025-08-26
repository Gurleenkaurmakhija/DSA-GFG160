class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        int n = s1.length(), m = s2.length();

        // For s1 to be subsequence, its length must
        // smaller than s2
        if (n > m)
            return false;

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s1[i] == s2[j])
                i++;
            j++;
        }

        return i == n;
    }
};