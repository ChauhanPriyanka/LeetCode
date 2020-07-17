// C/C++ program to find maximum path sum in Binary Tree 
#include<iostream>
#include<algorithm>
using namespace std; 
  
// A binary tree node 
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
// A utility function to allocate a new node 
struct Node* newNode(int data) 
{ 
    struct Node* newNode = new Node; 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return (newNode); 
} 
  
// This function returns overall maximum path sum in 'res' 
// And returns max path sum going through root. 
int findMaxUtil(Node* root, int &res) 
{ 
    //Base Case 
    if (root == NULL) 
        return 0; 
  
    // l and r store maximum path sum going through left and 
    // right child of root respectively 
    int l = findMaxUtil(root->left,res); 
    int r = findMaxUtil(root->right,res); 
  
    // Max path for parent call of root. This path must 
    // include at-most one child of root 
    int max_single = max(max(l, r) + root->data, root->data); 
  
    // Max Top represents the sum when the Node under 
    // consideration is the root of the maxsum path and no 
    // ancestors of root are there in max sum path 
    int max_top = max(max_single, l + r + root->data); 
  
    res = max(res, max_top); // Store the Maximum Result. 
  
    return max_single; 
} 
  
// Returns maximum path sum in tree with given root 
int findMaxSum(Node *root) 
{ 
    // Initialize result 
    int res = INT_MIN; 
  
    // Compute and return result 
    findMaxUtil(root, res); 
    return res; 
} 
 
int maxDepth(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  

int countNodes(Node* root) {
    if(!root) return 0;
    Node *temp = root;
    int height = 0, count = 0, level;
    while(temp) {
        temp = temp->left;
        height ++;
    }
    temp = root;
    level = height - 2;
    while(level >= 0) {
        Node *left = temp->left;
        for(int i = 0;i < level;i ++) {
            left = left->right;
        }
        if(left) {
            temp = temp->right;
            count += (1 << level);
        } else temp = temp->left;
        level --;
    }
    if(temp) count ++;
    return (1 << (height - 1)) + count - 1;
}

// Driver program 
int main4(void) 
{ 
    struct Node *root = newNode(10); 
    root->left        = newNode(23); 
    root->right       = newNode(10); 
    root->left->left  = newNode(20); 
    root->left->right = newNode(1); 
    root->right->right = newNode(-25); 
    root->right->right->left   = newNode(3); 
    root->right->right->right  = newNode(4); 
    //cout << "Max path sum is " << findMaxSum(root); 
	// cout << "Max path sum is " << maxDepth(root); 
	cout<<"Count node in complete binary tree" <<countNodes(root);
    return 0; 
} 