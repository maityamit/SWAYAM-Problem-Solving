/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "_A";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string &data) {
        if(data.substr(0,2)=="_A"){
            if(data.size()==2){
                data = "";
            }else{
                data = data.substr(3,data.size()-3);
            }
            return NULL;
        }
        else{
            TreeNode* node = new TreeNode(helper(data));
            node->left = deserialize(data);
            node->right = deserialize(data);
            return node;
        }
    }
    int helper(string &data) {
        int comma = data.find(',');
        int value = stoi(data.substr(0,comma));
        data = data.substr(comma+1,data.size()-comma);
        return value;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));