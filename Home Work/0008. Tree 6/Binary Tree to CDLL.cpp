class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node* prev=NULL;
    Node* am = NULL;
    void helper(Node* root){
        if(!root)   return;
        helper(root->left);
        if(!prev)
            am = root;
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        helper(root->right);
        prev->right = am;
        am->left = prev;
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.
        if(!root)   return NULL;
        helper(root);
        return am;
    }
};