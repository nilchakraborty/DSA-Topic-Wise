/*👉🏻 Method 1: Using "struct" to make user-define data type
struct node {
    int data;
    struct node* left;
    struct node* right;
};
👉🏻 Method 2: Using "class" to make user-define data type
class Node {
public:
    int data;
    Node* left;
    Node* right;
};
👉🏻 // Function to add an edge between vertices x and y
void addEdge(int x, int y, vector<vector<int> >& adj){
    adj[x].push_back(y);
    adj[y].push_back(x);
}
*/

/*//Binary Tree Traversal:Inorder Preorder Postorder(Iterative)
// preorder: https://takeuforward.org/data-structure/preorder-traversal-of-binary-tree/
// inorder: https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree/
// postorder: https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree/*/
/*//Binary Tree Traversal:Inorder Preorder Postorder(Recursive)
// Inorder
void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;
  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}
// Preorder
void preOrderTrav(node * curr, vector < int > & preOrder) {
  if (curr == NULL)
    return;
  preOrder.push_back(curr -> data);
  preOrderTrav(curr -> left, preOrder);
  preOrderTrav(curr -> right, preOrder);
}
// Postorder
void postOrderTrav(node * curr, vector < int > & postOrder) {
  if (curr == NULL)
    return;
  postOrderTrav(curr -> left, postOrder);
  postOrderTrav(curr -> right, postOrder);
  postOrder.push_back(curr -> data);
}*/
/*//Morris Inorder Traversal of a Binary tree
https://takeuforward.org/data-structure/morris-inorder-traversal-of-a-binary-tree/*/
/*//Morris Preorder Traversal of a Binary Tree
https://takeuforward.org/data-structure/morris-preorder-traversal-of-a-binary-tree/*/
/*//Level Order Traversal
vector<int> levelOrder(TreeNode* root) {
    vector<int> ans; 
    if(root == NULL) 
        return ans;             
    queue<TreeNode*> q; 
    q.push(root); 
    while(!q.empty()) {
        TreeNode *temp = q.front(); 
        q.pop(); 
        if(temp->left != NULL) 
            q.push(temp->left); 
        if(temp->right != NULL) 
            q.push(temp->right); 
        ans.push_back(temp->val); 
    }
    return ans; 
}*/
/*//Preorder Inorder Postorder Traversals in One Traversal
#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node * left, * right;
};
void allTraversal(node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
  stack < pair < node * , int >> st;
  st.push({root,1});
  if (root == NULL) return;
  while (!st.empty()) {
    auto it = st.top();
    st.pop();
    if (it.second == 1) {
      pre.push_back(it.first -> data);
      it.second++;
      st.push(it);
      if (it.first -> left != NULL) {
        st.push({it.first -> left,1});
      }
    }
    else if (it.second == 2) {
      in .push_back(it.first -> data);
      it.second++;
      st.push(it);
      if (it.first -> right != NULL) {
        st.push({it.first -> right,1});
      }
    }
    else {
      post.push_back(it.first -> data);
    }
  }
}
struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;
  return (node);
}
int main() {
  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right = newNode(3);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  vector < int > pre, in , post;
  allTraversal(root, pre, in , post);
  cout << "The preorder Traversal is : ";
  for (auto nodeVal: pre) {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The inorder Traversal is : ";
  for (auto nodeVal: in ) {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The postorder Traversal is : ";
  for (auto nodeVal: post) {
    cout << nodeVal << " ";
  }
  cout << endl;
  return 0;
}*/
/*//Height / Depth of Binary Tree
int height(node * root) {
  if (root == NULL) return 0;
  return 1 + max(height(root -> left), height(root -> right));
}*/
/*//Check if the Binary Tree is Balanced Binary Tree
bool isBalanced(TreeNode* root) {
    return dfsHeight (root) != -1;
}
int dfsHeight (TreeNode *root) {
    if (root == NULL) return 0;
    int leftHeight = dfsHeight (root -> left);
    if (leftHeight == -1) 
        return -1;
    int rightHeight = dfsHeight (root -> right);
    if (rightHeight == -1) 
        return -1;
    if (abs(leftHeight - rightHeight) > 1)  
        return -1;
    return max (leftHeight, rightHeight) + 1;
}*/
/*//Diameter of Binary Tree
int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    dfsHeight(root, ans);
    return ans;
}*/
/*//Maximum Sum Path
int findMaxPathSum(node * root, int & maxi) {
  if (root == NULL) return 0;
  int leftMaxPath = max(0, findMaxPathSum(root -> left, maxi));
  int rightMaxPath = max(0, findMaxPathSum(root -> right, maxi));
  int val = root -> data;
  maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);
  return max(leftMaxPath, rightMaxPath) + val;
}
int maxPathSum(node * root) {
  int maxi = INT_MIN;
  findMaxPathSum(root, maxi);
  return maxi;
}*/
/*//Check if two trees are identical
bool isSameTree(TreeNode* p, TreeNode* q) {
        return (p == NULL && q == NULL) || 
        (p != NULL && q != NULL && p->val == q->val && 
        isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}*/
/*//Zig-Zag traversal of a binary tree
vector < vector < int >> zigzagLevelOrder(Node * root) {
  vector < vector < int >> result;
  if (root == NULL) {
    return result;
  }
  queue < Node * > nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;
  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector < int > row(size);
    for (int i = 0; i < size; i++) {
      Node * node = nodesQueue.front();
      nodesQueue.pop();
      // find position to fill node's value
      int index = (leftToRight) ? i : (size - 1 - i);
      row[index] = node -> val;
      if (node -> left) {
        nodesQueue.push(node -> left);
      }
      if (node -> right) {
        nodesQueue.push(node -> right);
      }
    }
    // after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
}*/
/*//Boundary traversal of a Binary tree
#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node * left, * right;
};
bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}
void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}
void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}
vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;
  if (!isLeaf(root)) res.push_back(root -> data);
  addLeftBoundary(root, res);
  // add leaf nodes
  addLeaves(root, res);
  addRightBoundary(root, res);
  return res;
}
struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;
  return (node);
}
int main() {
  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);
  vector < int > boundaryTraversal;
  boundaryTraversal = printBoundary(root);
  cout << "The Boundary Traversal is : ";
  for (int i = 0; i < boundaryTraversal.size(); i++) {
    cout << boundaryTraversal[i] << " ";
  }
  return 0;
}*/
/*//Vertical Order Traversal
vector < vector < int >> findVertical(node * root) {
  map < int, map < int, multiset < int >>> nodes;
  queue < pair < node * , pair < int, int >>> todo;
  todo.push({root,{0,0}}); //initial vertical and level
  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    node * temp = p.first;
    //x -> vertical , y->level
    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(temp -> data); //inserting to multiset
    if (temp -> left) {
      todo.push({temp -> left,{x - 1,y + 1}});
    }
    if (temp -> right) {
      todo.push({temp -> right,{x + 1,y + 1}});
    }
  }
  vector < vector < int >> ans;
  for (auto p: nodes) {
    vector < int > col;
    for (auto q: p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}*/
/*//Left View of a tree
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res){
        if(root==NULL) return ;
//If vector size is equal to the level then push_back its node value to the vector data structure.
        if(res.size()==level) res.push_back(root->val); 
        recursion(root->left, level+1, res);
        recursion(root->right, level+1, res);
    }
    vector<int> leftSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};*/
/*//Right View of Tree
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res){
        if(root==NULL) return ;
// If vector size is equal to the level then push_back its node value to the vector data structure.
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};*/
/*//Top View of a tree
vector<int> topView(Node *root){
    vector<int> ans; 
    if(root == NULL) return ans; 
    map<int,int> mpp; 
    queue<pair<Node*, int>> q; 
    q.push({root, 0}); 
    while(!q.empty()) {
        auto it = q.front(); 
        q.pop(); 
        Node* node = it.first; 
        int line = it.second; 
        if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
        
        if(node->left != NULL) {
            q.push({node->left, line-1}); 
        }
        if(node->right != NULL) {
            q.push({node->right, line + 1}); 
        }
        
    }
    for(auto it : mpp) {
        ans.push_back(it.second); 
    }
    return ans; 
}*/
/*//Bottom View of a tree
vector <int> bottomView(Node *root) {
    vector<int> ans; 
    if(root == NULL) return ans; 
    map<int,int> mpp; 
    queue<pair<Node*, int>> q; 
    q.push({root, 0}); 
    while(!q.empty()) {
        auto it = q.front(); 
        q.pop(); 
        Node* node = it.first; 
        int line = it.second; 
        mpp[line] = node->data; 
        
        if(node->left != NULL) {
            q.push({node->left, line-1}); 
        }
        if(node->right != NULL) {
            q.push({node->right, line + 1}); 
        }
        
    }
    
    for(auto it : mpp) {
        ans.push_back(it.second); 
    }
    return ans;  
}*/
/*//Check for Symmetrical Binary Tree
bool isSymmetricUtil(TreeNode *root1, TreeNode* root2) {
    if(!root1) return !root2;
    if(!root2) return !root1;
    return (root1->val == root2->val) && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left);
}
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return isSymmetricUtil(root->left, root->right);
}*/
/*//Print Root to Node Path in a Binary Tree
bool getPath(node * root, vector < int > & arr, int x) {
    if (!root)
        return false;
    arr.push_back(root -> data);
    if (root -> data == x)
        return true;
    if (getPath(root -> left, arr, x) ||
        getPath(root -> right, arr, x))
        return true;
    arr.pop_back();
    return false;
}*/
/*//LCA of Binary Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL||root==p||root==q) return root;
    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    TreeNode* right=lowestCommonAncestor(root->right,p,q);
    if(!left) return right;
    else if(!right) return left;
    else return root;
}*/
/*//Maximum Width
// time complexity O(n) and space complexity O(n)
int widthOfBinaryTree(node * root) {
  if (!root)
    return 0;
  int ans = 0;
  queue < pair < node * , int >> q;
  q.push({root,0});
  while (!q.empty()) {
    int size = q.size();
    int curMin = q.front().second;
    int leftMost, rightMost;
    for (int i = 0; i < size; i++) {
      int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      node * temp = q.front().first;
      q.pop();
// is responsible for tracking the leftmost and rightmost indices of the nodes at each level of the binary tree.
      if (i == 0) leftMost = cur_id;
      if (i == size - 1) rightMost = cur_id;
      if (temp -> left)
        q.push({temp -> left,(long long)cur_id * 2 + 1});
      if (temp -> right)
        q.push({temp -> right,(long long)cur_id * 2 + 2});
    }
    ans = max(ans, rightMost - leftMost + 1);
  }
  return ans;
}*/
/*//Check for Children Sum Property in a Binary Tree
void reorder(node * root) {
    if (root == NULL) return;
    int child = 0;
    if (root -> left) {
        child += root -> left -> data;
    }
    if (root -> right) {
        child += root -> right -> data;
    }
    if (child < root -> data) {
        if (root -> left) root -> left -> data = root -> data;
        else if (root -> right) root -> right -> data = root -> data;
    }
    reorder(root -> left);
    reorder(root -> right);
    int tot = 0;
    if (root -> left) tot += root -> left -> data;
    if (root -> right) tot += root -> right -> data;
    if (root -> left || root -> right) root -> data = tot;
}*/
/*//All Nodes Distance K in Binary Tree
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/*/
/*// Construct Binary tree from Inorder and preorder traversal
#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node * left, * right;
};
struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;
  return (node);
}
node * constructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int,int> &mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;
  node * root = newNode(preorder[preStart]);
  int elem = mp[root -> data];
  int nElem = elem - inStart;
  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
  inStart, elem - 1, mp);
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);
  return root;
}
node * buildTree(vector < int > & preorder, vector < int > & inorder) {
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;
  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }
  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}
int main() {
  vector<int> preorder{10,20,40,50,30,60};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(preorder, inorder);
  return 0;
}*/
/*// Construct Binary tree from Inorder and postorder traversal
node * constructTree(vector < int > & postorder, int postStart, int postEnd, 
vector < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (postStart > postEnd || inStart > inEnd) return NULL;
  node * root = newNode(postorder[postEnd]);
  int elem = mp[root -> data];
  int nElem = elem - inStart;
  root -> left = constructTree(postorder, postStart, postStart + nElem - 1, 
  inorder, inStart, elem - 1, mp);
  root -> right = constructTree(postorder, postStart + nElem, postEnd-1, inorder,
  elem + 1, inEnd, mp);
  return root;
}
node * buildTree(vector < int > & postorder, vector < int > & inorder) {
    int postStart = 0, postEnd = postorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;
    map < int, int > mp;
    for (int i = inStart; i <= inEnd; i++) {
        mp[inorder[i]] = i;
}*/
/*//Serialize And Deserialize a Binary Tree
https://takeuforward.org/data-structure/serialize-and-deserialize-a-binary-tree/*/
/*// Flatten Binary Tree to LinkedList
#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node * left, * right;
};
class Solution {
  node * prev = NULL;
  public:
    void flatten(node * root) {
      if (root == NULL) return;
      flatten(root -> right);
      flatten(root -> left);
      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }
};
struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;
  return (node);
}
int main() {
  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> right = newNode(4);
  root -> right = newNode(5);
  root -> right -> right = newNode(6);
  root -> right -> right -> left = newNode(7);
  Solution obj;
  obj.flatten(root);
  while(root->right!=NULL){
      cout<<root->data<<"->";
      root=root->right;
  }
cout<<root->data;
  return 0;
}*/
