class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lowestCommonAncestor(Node* root, int p, int q) {
        if(root==NULL || root->data==p || root->data==q) return root;
        Node* l = lowestCommonAncestor(root->left,p,q);
        Node* r = lowestCommonAncestor(root->right,p,q);
        if(l==NULL) return r;
        else if(r==NULL) return l;
        else return root;
    }
    int dist(Node* root,int target){
        if(root==NULL) return 1e9;
        if(root->data==target) return 0;
        return min(1+dist(root->left,target),1+dist(root->right,target));
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lca = lowestCommonAncestor(root,a,b);
        return dist(lca,a)+dist(lca,b);
    }
};