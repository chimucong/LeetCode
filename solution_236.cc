#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(root == nullptr){
    		return nullptr;
    	}
        vector<pair<TreeNode*, bool>> s;
        vector<pair<TreeNode*, bool>> s1;
        TreeNode* current = root;
        int found = 0;
        [&](){
	        while(current != nullptr || !s.empty()){
	        	while(current != nullptr){
	        		s.emplace_back(current, true); //true: first visited
	        		if(current == p || current == q){
	        			found++;
	        			if(found == 1){
	        				s1 = s;
	        			}else{
	        				return;
	        			}
	        		}
	        		current = current->left;
	        	}
	        	if(s.back().second){
	        		s.back().second = false;
	        		current = s.back().first->right;
	        	}else{
	        		s.pop_back();
	        	}
	        }
        }();
        if(found != 2){
        	return nullptr;
        }
        int i = 0;
        while(s[i].first == s1[i].first){
        	i++;
        }
        return s[i-1].first;
    }
};
int main(){
	return 0;
}