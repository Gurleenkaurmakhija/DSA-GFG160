/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

/* The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:

    // Here mini and maxi defines the range of
    // the subtree root. If the range consists
    // only of 1 value (root value), it means
    // no other value cannot be added to this.
    bool dfs(Node* root, int mini, int maxi) {

        // Base Case
        if (root == nullptr)
            return false;

        // If leaf node and no range left
        if (root->left == nullptr && root->right == nullptr && mini == maxi) {
            return true;
        }

        return dfs(root->left, mini, root->data - 1) ||
               dfs(root->right, root->data + 1, maxi);
    }

    bool isDeadEnd(Node* root) { return dfs(root, 1, INT_MAX); }
};