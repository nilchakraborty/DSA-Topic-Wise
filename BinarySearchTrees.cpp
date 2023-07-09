/*//Fina a value in a BST
TreeNode* searchBST(TreeNode* root, int val){
    while(root!= NULL && root->val != val){
        root = (root->val > val) ? root->left : root->right;
    }
    return root;
}*/
/*//Find min and max value in a BST
int minValue(struct node *node)
{
    struct node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return (current->data);
}*/
/*//Floor and Ceil from a BST
void floorCeilBSTHelper(Node* root, int key, int& floor,int& ceil){
    while (root) {
        if (root->data == key) {
            ceil = root->data;
            floor = root->data;
            return;
        }
        if (key > root->data) {
            floor = root->data;
            root = root->right;
        }
        else {
            ceil = root->data;
            root = root->left;
        }
    }
    return;
}
void floorCeilBST(Node* root, int key){
    int floor = -1, ceil = -1;
    floorCeilBSTHelper(root, key, floor, ceil);
    cout << key << ' ' << floor << ' ' << ceil << '\n';
}*/
/*//Insert into a BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    if(root->val > val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}*/
/*//Delete a node from BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root)
        if(key<root->val) root->left = deleteNode(root->left, key);
        else if(key>root->val) root->right = deleteNode(root->right, key);
        else{
        if(!root->left && !root->right) return NULL;
        if(!root->left || !root->right) return root->left?root->left:root->right;
        TreeNode* tmp=root->left;
        while(tmp->right!=NULL) tmp=tmp->right;
        root->val=tmp->val;
        root->left=deleteNode(root->left, tmp->val);
        }
    return root;
}*/
/*//Kth largest/smallest element in BST
node* kthlargest(node* root,int& k){
	if(root==NULL)
	return NULL;
	node* right=kthlargest(root->right,k);
	if(right!=NULL)
	return right;
	k--;
	if(k==0)
	return root;
	return kthlargest(root->left,k);
}
node* kthsmallest(node* root,int &k){
	if(root==NULL)
	return NULL;
	node* left=kthsmallest(root->left,k);
	if(left!=NULL)
	return left;
	k--;
	if(k==0)
	return root;
	return kthsmallest(root->right,k);
}*/
/*//Check if a tree is a BST or BT
long long mn = LLONG_MIN;
long long mx = LLONG_MAX;
bool check (TreeNode* root, long long mn, long long mx){
    if (root == nullptr)
        return true;
    if (root->val <= mn || root->val >= mx)
        return false;
    return (check(root->left, mn, root->val) && check(root->right, root->val, mx));
}
bool isValidBST(TreeNode* root) {
    return check(root, mn, mx);
}*/
/*//LCA of BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL||root==p||root==q) return root;
    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    TreeNode* right=lowestCommonAncestor(root->right,p,q);
    if(!left) return right;
    else if(!right) return left;
    else return root;
}*/
/*//Construct Binary Search Tree from Preorder Traversal
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}
TreeNode* build(vector<int>& preorder, int& i, int bound) {
    if (i == preorder.size() || preorder[i] > bound) return NULL;
    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, bound);
    return root;
}*/
/*//Find inorder successor/predecessor in a BST
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* succ = NULL;
    while(root!=NULL){
        if(root->val > p->val){
            succ = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return succ;
}*/
/*//Merge 2 BST
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
int *merge(int arr1[], int tarr2[], int m, int n);
void storeInorder(node *node, int inorder[], int *index_ptr);
node *sortedArrayToBST(int arr[], int start, int end);
node *mergeTrees(node *root1, node *root2, int m, int n)
{
    int *arr1 = new int[m];
    int i = 0;
    storeInorder(root1, arr1, &i);
    int *arr2 = new int[n];
    int j = 0;
    storeInorder(root2, arr2, &j);
    int *mergedArr = merge(arr1, arr2, m, n);
    return sortedArrayToBST(mergedArr, 0, m + n - 1);
}
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}
void printInorder(node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
int *merge(int arr1[], int arr2[], int m, int n)
{
    int *mergedArr = new int[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }

    return mergedArr;
}
void storeInorder(node *node, int inorder[], int *index_ptr)
{
    if (node == NULL)
        return;
    storeInorder(node->left, inorder, index_ptr);

    inorder[*index_ptr] = node->data;
    (*index_ptr)++;
    storeInorder(node->right, inorder, index_ptr);
}
node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    node *root = newNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}
int main()
{
    node *root1 = newNode(100);
    root1->left = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);
    node *root2 = newNode(80);
    root2->left = newNode(40);
    root2->right = newNode(120);

    node *mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);
    return 0;
}*/
/*//Two Sum in BST
set<int> s;
bool findTarget(TreeNode* root, int k) {
    if(!root) return false;
    if(s.find(k-root->val)!=s.end()) return true;
    s.insert(root->val);
    return findTarget(root->left,k)||findTarget(root->right,k);
}*/
/*//Recover Binary Search Tree
https://leetcode.com/problems/recover-binary-search-tree/*/
/*//Largest BST in a Binary Tree
NodeValue largestBSTSubtreeHelper(TreeNode* root) {
    if (!root) {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);
    if (left.maxNode < root->val && root->val < right.minNode) {// It is a BST.
        return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
    }
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBSTSubtree(TreeNode* root) {
    return largestBSTSubtreeHelper(root).maxSize;
}*/
