int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ans = -1;
    while(root!=NULL){
        if(root->data>=input) ans=root->data,root=root->left;
        else root=root->right;
    }
    return ans;

    // Your code here
}