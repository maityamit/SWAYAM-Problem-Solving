

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
        if(root==NULL) return ans;
        queue<Node*> pending;
        vector<int> temp;
        pending.push(root);
        pending.push(NULL);
        while(pending.size()!=0){
            Node* tempTree = pending.front();
            pending.pop();
            if(tempTree==NULL){
                ans.push_back(temp[0]);
                temp.clear();
                if(pending.size()==0){
                    return ans;
                }
                pending.push(NULL);
                continue;
            }
            temp.push_back(tempTree->data);
            if(tempTree->left) pending.push(tempTree->left);
            if(tempTree->right) pending.push(tempTree->right);
        }
        return ans;
   
}