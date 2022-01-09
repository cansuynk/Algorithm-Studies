#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createTree(int val){
    TreeNode* root = new TreeNode();
    
    root->val = val;
    return root;
    
}

TreeNode* insertNode(TreeNode *root, int val){
    
    if(root == NULL){ //if tree empty
        root = createTree(val);
        return root;
    }
    
    TreeNode *node = root;
    TreeNode *temp = root;
    
    while(node!=NULL){
        if(node->val>=val){
            temp = node;
            node = node -> left;
        }
        else{
            temp = node;
            node = node -> right;
        }
    }
    
    node = new TreeNode();
    node->val = val;
    
    if(temp->val>=val){
        temp->left = node;
    }else{
        temp->right = node;
    }
    
    return root;
}

vector<int> arr;
//inorder
void traverse(TreeNode *root){
    
    if(root != NULL){
        traverse(root->left);
        cout << root-> val << " ";
        arr.push_back(root-> val);
        traverse(root->right);
    }
    
}


bool isValidBST(TreeNode* root) {
    traverse(root);
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

bool isSym(TreeNode* temp, TreeNode* temp2) {
    /*
    traverse(root);
    int size = arr.size();
    
    for(int i=0; i<size/2; i++){
        if(arr[i]!=arr[size-i-1])
            return false;
    }
    */
    if(temp==NULL && temp2 ==NULL){
        return true;
    }
    else if(temp==NULL || temp2 ==NULL){
        return false;
    }
    if(temp->val != temp2->val){
        return false;
    }
    
    return isSym(temp-> left, temp2->right) && isSym(temp->right, temp2->left);
}

vector<vector<int>> levelOrder(TreeNode* root){
    
    vector<vector<int>> ar;
    
    if(!root)
        return ar;
    
    queue <TreeNode*>q;
    
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0; i<size; i++){
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        ar.push_back(level);
    }
    return ar;
}

TreeNode* hb_rec(vector<int>& nums, int m, int n){
    //nums[0..m...n..]
    
    if(m>n){
        return NULL;
    }
    
    int mid = m + (n-m)/2;
    TreeNode *root = new TreeNode(nums[mid]);
    root -> left = hb_rec(nums, m, mid-1);
    root -> right = hb_rec(nums, mid+1, n);     
    
    return root;
    
}

//height-balanced binary tree
TreeNode* hb(vector<int>& nums){
    return hb_rec(nums, 0, nums.size()-1);
}

int main()
{
    
   
  
    //////////Building and linking tree manually//////////
    /*
    TreeNode *x = new TreeNode();
    x->val = 1;
    
    TreeNode *y = new TreeNode();
    y->val = 2;
    
    TreeNode *z = new TreeNode();
    z->val = 2;
    
    TreeNode *k = new TreeNode();
    k->val = 3;
    
    TreeNode *l = new TreeNode();
    l->val = 3;
    
    TreeNode *m = new TreeNode();
    m->val = 4;
    
    TreeNode *n = new TreeNode();
    n->val = 4;
    
    x->left = y;
    x->right = z;
    
    y->left = k;
    y->right = m;
    
    z->left = n;
    z->right = l;
    
    */
    
    
    /*
    TreeNode *x = new TreeNode();
    x->val = 1;
    
    TreeNode *y = new TreeNode();
    y->val = 2;
    
    TreeNode *z = new TreeNode();
    z->val = 2;
    
    TreeNode *k = new TreeNode();
    k->val = 2;
    
    TreeNode *l = new TreeNode();
    l->val = 2;
    
    x->left = y;
    x->right = z;
    
    y->left = k;
    z->left = l;
    */
    
    
    TreeNode *x = new TreeNode();
    x->val = 1;
    
    TreeNode *y = new TreeNode();
    y->val = 3;
    
    TreeNode *z = new TreeNode();
    z->val = 3;
    
    TreeNode *k = new TreeNode();
    k->val = 4;
    
    TreeNode *l = new TreeNode();
    l->val = 5;
    
    TreeNode *m = new TreeNode();
    m->val = 4;
    
    TreeNode *o = new TreeNode();
    o->val = 6;
    
    x->left = y;
    x->right = z;
    
    y->left = k;
    y->right = l;
    
    z->right = m;
    
    k->left = o;
    
    
    
    //cout << (isValidBST(x) ? "True" : "False") << endl;
    
    
    //cout << (isSym(x->left, x->right) ? "True" : "False") << endl;
    
    /*
    vector <vector<int>> ar = levelOrder(x);

    for(int i=0; i<ar.size(); i++){
        for(int j=0; j<ar[i].size(); j++){
            cout << ar[i][j];
        }
        cout << " ";
    }
    */
    
    vector <int>nums = {-10,-3,0,5,9};
    
    TreeNode *root = hb(nums);
    traverse(root);

    return 0;
}