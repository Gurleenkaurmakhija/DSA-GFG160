#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int MOD = 1000000007;
    static const int BASE = 131;

    class RollingHash {
    private:
        vector<int> hash, power;
    public:
        RollingHash(const string &s) {
            int n = s.size();
            hash.resize(n + 1);
            power.resize(n + 1);
            hash[0] = 0;
            power[0] = 1;
            for (int i = 0; i < n; ++i) {
                hash[i + 1] = ((long long)hash[i] * BASE + s[i]) % MOD;
                power[i + 1] = ((long long)power[i] * BASE) % MOD;
            }
        }
        int getHash(int l, int r) const {
            int val = (hash[r + 1] - (long long)hash[l] * power[r - l + 1] % MOD + MOD) % MOD;
            return val;
        }
    };

    bool isPalindrome(int l, int r, RollingHash &fHash, RollingHash &rHash, int n) {
        int h1 = fHash.getHash(l, r);
        int h2 = rHash.getHash(n - 1 - r, n - 1 - l);
        return h1 == h2;
    }

public:
    int maxSum(string &s) {
        int n = s.size();
        RollingHash fHash(s);
        string rev = s;
        reverse(rev.begin(), rev.end());
        RollingHash rHash(rev);

        vector<int> leftMax(n, 1), rightMax(n, 1);

        // Longest odd-length palindrome ending at each index
        for (int i = 0; i < n; ++i) {
            int l = 0, r = min(i, n - 1 - i), best = 1;
            while (l <= r) {
                int m = (l + r) / 2;
                int start = i - m;
                int end = i + m;
                if (isPalindrome(start, end, fHash, rHash, n)) {
                    best = 2 * m + 1;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            int endIdx = i + best / 2;
            if (endIdx < n) leftMax[endIdx] = max(leftMax[endIdx], best);
        }

        // Relax leftMax
        for (int i = n - 2; i >= 0; i--)
            leftMax[i] = max(leftMax[i], leftMax[i + 1] - 2);
        for (int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i], leftMax[i - 1]);

        // Longest odd-length palindrome starting at each index
        for (int i = n - 1; i >= 0; --i) {
            int l = 0, r = min(i, n - 1 - i), best = 1;
            while (l <= r) {
                int m = (l + r) / 2;
                int start = i - m;
                int end = i + m;
                if (isPalindrome(start, end, fHash, rHash, n)) {
                    best = 2 * m + 1;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            int startIdx = i - best / 2;
            if (startIdx >= 0) rightMax[startIdx] = max(rightMax[startIdx], best);
        }

        // Relax rightMax
        for (int i = 1; i < n; i++)
            rightMax[i] = max(rightMax[i], rightMax[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i], rightMax[i + 1]);

        // Compute max sum
        int ans = 0;
        for (int i = 0; i + 1 < n; ++i)
            ans = max(ans, leftMax[i] + rightMax[i + 1]);

        return ans;
    }
};
