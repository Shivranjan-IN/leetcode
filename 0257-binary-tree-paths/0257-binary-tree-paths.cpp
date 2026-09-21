#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allpath; // Isko vector<string> banaya
        vector<int> currpath;

        dfs(root, currpath, allpath);
        return allpath;
    }

private:
    // allpath ko vector<string> accept karne ke liye change kiya
    void dfs(TreeNode* node, vector<int>& path, vector<string>& allpath) {
        if(!node) return;
        
        path.push_back(node->val);
        
  
        if(!node->left && !node->right) {
            string s = "";
            for(int i = 0; i < path.size(); i++) {
                s += to_string(path[i]); 
                if(i != path.size() - 1) {
                    s += "->"; 
                }
            }
            allpath.push_back(s);
        } else {
             dfs(node->left, path, allpath);
             dfs(node->right, path, allpath);
        }
 
        path.pop_back(); 
    }     
};