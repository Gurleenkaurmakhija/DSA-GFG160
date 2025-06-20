class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
    
    // Sort the arr to make consecutive grouping easier
    sort(arr.begin(), arr.end());

    // Traverse the sorted arr
    for (int i = 0; i < arr.size(); i++) {
        // Skip if the card is already used
        if (arr[i] == -1) continue;

        // To track how many cards we added to the current group
        int count = 0;          
        
        // Starting value of current group
        int curr = arr[i];       

        // Try to form a group of size 'k'
        for (int j = i; j < arr.size(); j++) {
            if (arr[j] == curr) {
                count++;
                // Move to next consecutive card
                curr++;           
                // Mark this card as used
                arr[j] = -1;     
            }
            if (count == k) break;
        }

        // If we couldn't form a full group of size k, return false
        if (count != k) return false;
    }

    // All cards successfully grouped
    return true;

    }
};