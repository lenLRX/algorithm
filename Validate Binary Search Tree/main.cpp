//98. Validate Binary Search Tree
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <cstdlib>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
#include <vector>
using namespace std;
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		vector<int> vec;
		postT(root, vec);
		for (int i = 1; i < vec.size(); i++){
			if (vec[i - 1] >= vec[i])
				return false;
		}
		return true;
	}
	void postT(TreeNode* node, vector<int>& vec){
		if (node->left){
			postT(node->left, vec);
		}
		vec.push_back(node->val);
		if (node->right){
			postT(node->right, vec);
		}


	}
};