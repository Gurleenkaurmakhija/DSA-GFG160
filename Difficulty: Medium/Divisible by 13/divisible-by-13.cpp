class Solution {
  public:
  bool divby13(string& s) {
    // Stores running remainder
    int rem = 0;

    // Process each digit and compute remainder modulo 13
    for (char ch : s) {
        rem = (rem * 10 + (ch - '0')) % 13;
    }
    
    // Final check for divisibility
    return rem == 0;
}


};