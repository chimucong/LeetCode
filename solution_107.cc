#include <vector>
#include <list>
#include <algorithm>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        list<TreeNode *> current;
        if (root != nullptr)
        {
            current.push_back(root);
        }
        while (!current.empty())
        {
            int size = current.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = current.front();
                current.pop_front();
                level.push_back(node->val);
                if (node->left != nullptr)
                {
                    current.push_back(node->left);
                }
                if (node->right != nullptr)
                {
                    current.push_back(node->right);
                }
            }
            result.push_back(std::move(level));
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};