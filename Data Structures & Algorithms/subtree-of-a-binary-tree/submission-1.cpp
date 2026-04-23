/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr)
        {
            return "$#";
        }
        return "$" + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }
    vector<int> buildLPS(string& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int len=0, i=1;
        while (i < n)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len-1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool kmpSearch(string& text, string& pattern) {
        vector<int> lps = buildLPS(pattern);
        int i=0, j=0;
        while (i < text.size())
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }
            if (j == pattern.size())
            {
                return true;
            }
            else if (i<text.size() && text[i]!=pattern[j])
            {
                if (j != 0)
                {
                    j = lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string text = serialize(root);
        string pattern = serialize(subRoot);
        return kmpSearch(text, pattern);
    }
};
