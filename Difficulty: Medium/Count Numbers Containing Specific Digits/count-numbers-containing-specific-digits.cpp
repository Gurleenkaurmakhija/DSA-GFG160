class Solution {
  public:
    int fastPow(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

int countValid(int n, vector<int> &arr) {

    // mark which digits are “good”
    bool good[10] = {};
    for (int d : arr) good[d] = true;

    // count forbidden digits overall (f) 
    // and for the first position (f0)
    int f = 0, f0 = 0;
    for (int d = 0; d < 10; d++) {
        if (!good[d]) {
            f++;
            if (d != 0) f0++;
        }
    }

    // total n-digit numbers = 9 * 10^(n-1)
    int total = 9 * fastPow(10, n - 1);
    
    // numbers with no good digit = f0 * f^(n-1)
    int noneAllowed = (n == 1 ? f0 : f0 * fastPow(f, n - 1));

    // valid = total − noneAllowed
    return total - noneAllowed;
}

};
