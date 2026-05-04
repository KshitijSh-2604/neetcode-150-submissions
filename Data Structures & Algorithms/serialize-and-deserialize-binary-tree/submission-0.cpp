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

class Codec {
public:
    void dfsSerialize(TreeNode* node, string& res) {
        if (!node)
        {
            res += "N,";
            return;
        }
        res += to_string(node->val) + ",";
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }
    string serialize(TreeNode* root) {
        string res;
        dfsSerialize(root, res);
        return res;
    }
    TreeNode* dfsDeserialize(const string& data, int& i) {
        if (data[i] == 'N')
        {
            i += 2; // skip "N,"
            return nullptr;
        }
        int sign = 1;
        if (data[i] == '-')
        {
            sign = -1;
            i++;
        }
        int num = 0;
        while (i<data.size() && data[i]!=',')
        {
            num = num*10 + (data[i]-'0');
            i++;
        }
        i++;
        TreeNode* node = new TreeNode(sign*num);
        node->left = dfsDeserialize(data, i);
        node->right = dfsDeserialize(data, i);
        return node;
    }
    TreeNode* deserialize(string data) {
        int i = 0;
        return dfsDeserialize(data, i);
    }
};
