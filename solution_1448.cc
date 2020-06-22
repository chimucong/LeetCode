#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        count = 0;
        int max = std::numeric_limits<int>::min();
        helper(root, max);
        return count;
    }
private:
	int count;
	void helper(TreeNode* node, int max){
		if(node == nullptr){
			return;
		}
		if(node->val >= max){
			count++;
		}
		max = std::max<int>(max, node->val);
		helper(node->left, max);
		helper(node->right, max);
	}
};