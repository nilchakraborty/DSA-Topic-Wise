/*// level order traversal
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root == NULL) return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()) {
//             int size = q.size();
//             vector<int> level;
//             for(int i = 0;i<size;i++) {
//                 TreeNode *node = q.front();
//                 q.pop();
//                 if(node->left != NULL) q.push(node->left);
//                 if(node->right != NULL) q.push(node->right);
//                 level.push_back(node->val);
//             }
//             ans.push_back(level);
//         }
//         return ans;
//     }
// };
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
void printCurrentLevel(node *root, int level);
int height(node *node);
node *newNode(int data);

void printLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
void printCurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}*/
/*// Reverse Level Order traversal
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
void printCurrentLevel(node *root, int level);
int height(node *node);
node *newNode(int data);

void reverseLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for (i = h; i >= 1; i--)
        printCurrentLevel(root, i);
}
void printCurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Level Order traversal of binary tree is \n";
    reverseLevelOrder(root);
    return 0;
}*/
/*// Print Root to Node path
bool getPath(node * root, vector < int > & arr, int x) {
  if (!root)    return false;
  arr.push_back(root -> data);
  if (root -> data == x)    return true;
// if x is found in left or right subtree, return true
  if (getPath(root -> left, arr, x) || getPath(root -> right, arr, x))
    return true;  
  arr.pop_back();
  return false;
}*/
/*// Vertical order traversal
#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector < vector < int >> findVertical(node * root) {
  map < int, map < int, multiset < int >>> nodes; // first int for vertical, second int for level, multiset for sorted order
  queue < pair < node * , pair < int, int >>> todo; // node for root, pair for vertical and level
  todo.push({root,{0, 0}});
  //initial vertical and level
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
  root -> left -> right = newNode(10);
  root -> left -> left -> right = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(3);
  root -> right -> left = newNode(9);
  root -> right -> right = newNode(10);

  vector < vector < int > > verticalTraversal;
  verticalTraversal = findVertical(root);

  cout << "The Vertical Traversal is : " << endl;
  for (auto vertical: verticalTraversal) {
    for (auto nodeVal: vertical) {
      cout << nodeVal << " ";
    }
    cout << endl;
  }
  return 0;
}*/
/*// Height of a tree
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
};
int maxDepth(node* node){
    return node ? 1 + max(maxDepth(node->left), maxDepth(node->right)) : 0;
}
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}
int main()
{
    node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Height of tree is " << maxDepth(root)-1;
    return 0;
}*/
/*// Diameter of a tree
// time complexity = O(n^2) 
int height(Node *node)
{return node == NULL? 0 : 1 + max(height(node->left), height(node->right));}
int diameter(Node *tree){
    if (tree == NULL) return 0;
// firstly calculate left and right height and diameter
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
// time complexity = O(n)
int diameter(Node* root,int* height) {
    if(root == NULL) {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiameter = diameter(root->left, &lh);
    int rdiameter = diameter(root->right, &rh);
    *height = max(lh, rh) + 1;
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}*/
/*// Mirror of a tree
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)
        malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
void mirror(struct Node *node)
{
    if (node == NULL)
        return;
    else
    {
        struct Node *temp;
        mirror(node->left);
        mirror(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
void inOrder(struct Node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Inorder traversal of the constructed"
         << " tree is" << endl;
    inOrder(root);
    mirror(root);
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    inOrder(root);

    return 0;
}*/
/*// Inorder, Preorder, Postorder Traversal of a tree both using recursion
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void printPreorder(struct Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    return 0;
}*/
/*// Inorder, Preorder, Postorder Traversal of a tree both using iteration
vector<int> preInPostTraversal(TreeNode* root){
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if(root == NULL) return;
    while(!st.empty()) {
        auto it = st.top();
        st.pop();
// this is pre order part, increment the count and push the left node
        if(it.second == 1) {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
// this is in order part, increment the count and push the right node
        else if(it.second == 2) {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->val);
        }
    }
}*/
/*// Left View of a tree
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
/*// Right View of Tree
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
/*// Top View of a tree
class Solution{
    public:
    vector<int> topView(Node *root){
        vector<int> ans;
        if(root == NULL) return ans;
        map<int,int> mpp; // first int for line and second int for node data
        queue<pair<Node*, int>> q; // first node* for root and second int for line
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
// when a new line is encountered (mpp.find(line) == mpp.end()), the node's data is stored in the map. This ensures that only the first node encountered at a particular line is included in the view.
            if(mpp.find(line) == mpp.end()) 
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
    }
};
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int key)
{
    Node *node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}
void fillMap(Node *root, int d, int l, map<int, pair<int, int>> &m)
{
    if (root == NULL)
        return;
    if (m.count(d) == 0)
    {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > 1)
    {
        m[d] = make_pair(root->data, l);
    }
    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}
void topView(struct Node *root)
{
    map<int, pair<int, int>> m;
    fillMap(root, 0, 0, m);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second.first << " ";
    }
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    topView(root);
    return 0;
}*/
/*// Bottom View of a tree
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int,int> mpp; // first int for line and second int for node data
        queue<pair<Node*, int>> q; // first node* for root and second int for line
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
//The map mpp is updated regardless of whether a line has been encountered before (mpp[line] = node->data). This ensures that the last node encountered at a particular line will be stored in the map, overwriting any previous values.
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
    }
};
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    int hd;
    Node * left, * right;
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};

void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m)
{
    if (root == NULL)
        return;
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root -> data, curr);
    }
    else
    {
        pair < int, int > p = m[hd];
        if (p.second <= curr)
        {
            m[hd].second = curr;
            m[hd].first = root -> data;
        }
    }
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m);
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
}

void printBottomView(Node * root)
{
    map < int, pair < int, int > > m;

    printBottomViewUtil(root, 0, 0, m);
    map < int, pair < int, int > > ::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
}

int main()
{
    Node * root = new Node(20);
    root -> left = new Node(8);
    root -> right = new Node(22);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(25);
    root -> left -> right -> left = new Node(10);
    root -> left -> right -> right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    printBottomView(root);
    return 0;
}*/
/*// Zig-Zag traversal of a binary tree
vector < vector < int >> zigzagLevelOrder(Node * root) {
  vector < vector < int >> result;
  if (root == NULL) return result;
  
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
/*// Check if a tree is balanced or not
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
int height(node *node);
bool isBalanced(node *root)
{
    int lh, rh;
    if (!root)
        return 1;
    lh = height(root->left);
    rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}
int max(int a, int b)
{
    return(a >= b) ? a : b;
}
int height(node *node)
{
    if (!node)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}*/
/*// Diagnol Traversal of a Binary tree
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void diagonalPrint(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!temp)
        {
            if (q.empty())
                return;
            cout << endl;
            q.push(NULL);
        }
        else
        {
            while (temp)
            {
                cout << temp->data << " ";
                if (temp->left)
                    q.push(temp->left);
                temp = temp->right;
            }
        }
    }
}
int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    diagonalPrint(root);
}*/
/*// Boundary traversal of a Binary tree
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
/*// Construct Binary Tree from String with Bracket Representation
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int element)
    {
        data = element;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
Node *constructTree(string s)
{
    Node *root = new Node(s[0] - '0');
    stack<Node *> stk;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(root);
        }
        else if (s[i] == ')')
        {
            root = stk.top();
            stk.pop();
        }
        else
        {
            if (root->left == NULL)
            {
                Node *left = new Node(s[i] - '0');
                root->left = left;
                root = root->left;
            }
            else if (root->right == NULL)
            {
                Node *right = new Node(s[i] - '0');
                root->right = right;
            }
        }
    }
    return root;
}
int main()
{
    string s = "4(2(3)(1))(6(5))";
    Node* root = constructTree(s);
    preOrder(root);

    return 0;
}*/
/*// Convert Binary tree into Doubly Linked List
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *bintree2listUtil(node *root, node **head, node **tail)
{
    if (root == NULL)
        return NULL;

    node *left = root->left;
    node *right = root->right;

    bintree2listUtil(root->left, head, tail);

    if (*head == NULL)
    {
        *head = root;
    }

    root->left = *tail;

    if (*tail != NULL)
    {
        (*tail)->right = root;
    }

    *tail = root;

    bintree2listUtil(root->right, head, tail);

    return root;
}
node *bintree2list(node *root)
{
    if (root == NULL)
        return root;

    node *head = NULL;
    node *tail = NULL;

    bintree2listUtil(root, &head, &tail);

    return head;
}
node *newNode(int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
void printList(node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}
int main()
{
    node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    node *head = bintree2list(root);
    printList(head);

    return 0;
}*/
/*// Convert Binary tree into Sum tree
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
int toSumTree(node *Node)
{
    if (!Node)
        return 0;
    int old_val = Node->data;
    Node->data = toSumTree(Node->left) + toSumTree(Node->right);
    return Node->data + old_val;
}
void printInorder(node *Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout << " " << Node->data;
    printInorder(Node->right);
}
node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
int main()
{
    node *root = NULL;
    int x;
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    toSumTree(root);
    cout << "Inorder Traversal of the resultant tree is: \n";
    printInorder(root);
    return 0;
}*/
/*// Children Sum Property
void reorder(node * root) {
  if (root == NULL) return;
  int child = 0;
// add left and right data to child
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }
// if child is greater than root then make child equal to root
  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }
// if child is less than root then make root equal to child
  else if (child > root -> data) {
    root -> data = child;
  }
// recursively call left and right
  reorder(root -> left);
  reorder(root -> right);
// again calculate the total of left and right
  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}*/
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
node * buildTree(vector < int > & postorder, vector < int > & inorder) {
    map < int, int > mp;
    for (int i = inStart; i <= inEnd; i++)
        mp[inorder[i]] = i;
    return constructTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
}
node * constructTree(vector < int > & postorder, int postStart, int postEnd, vector < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
    if (postStart > postEnd || inStart > inEnd) return NULL;
    node * root = newNode(postorder[postEnd]);
    int elem = mp[root -> data];
    int nElem = elem - inStart;
    root -> left = constructTree(postorder, postStart, postStart + nElem - 1, inorder, inStart, elem - 1, mp);
    root -> right = constructTree(postorder, postStart + nElem, postEnd - 1, inorder, elem + 1, inEnd, mp);
    return root;
}*/
/*// Find minimum swaps required to convert a Binary tree into BST
#include <bits/stdc++.h>
using namespace std;
void inorder(int a[], std::vector<int> &v,
             int n, int index)
{
    if (index >= n)
        return;
    inorder(a, v, n, 2 * index + 1);
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}
int minSwaps(std::vector<int> &v)
{
    std::vector<pair<int, int>> t(v.size());
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
        t[i].first = v[i], t[i].second = i;

    sort(t.begin(), t.end());
    for (int i = 0; i < t.size(); i++)
    {
        if (i == t[i].second)
            continue;
        else
        {
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }

        if (i != t[i].second)
            --i;
        ans++;
    }
    return ans;
}
int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}*/
/*// Check if Binary tree is Sum tree or not
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int sum(struct node *root)
{
    if (!root)
        return 0;
    return sum(root->left) + root->data + sum(root->right);
}
int isSumTree(struct node *node)
{
    int ls, rs;
    if (!node || (!node->left && !node->right))
        return 1;
    ls = sum(node->left);
    rs = sum(node->right);
    if ((node->data == ls + rs) && isSumTree(node->left) && isSumTree(node->right))
        return 1;
    return 0;
}
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(
        sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
int main()
{
    struct node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";

    getchar();
    return 0;
}*/
/*// Check if all leaf nodes are at same level or not
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
bool checkUtil(struct Node *root, int level, int *leaflevel)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
    {
        if (*leaflevel == 0)
        {
            *leaflevel = level;
            return true;
        }
        return (level == *leaflevel);
    }
    return checkUtil(root->left, level + 1, leaflevel) &&
           checkUtil(root->right, level + 1, leaflevel);
}
bool check(struct Node *root)
{
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, &leafLevel);
}
int main()
{
    struct Node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";
    getchar();
    return 0;
}*/
/*// Check if a Binary Tree contains duplicate subtrees of size 2 or more [ IMP ]
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char key;
    Node *left, *right;
};
Node *newNode(char key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

unordered_set<string> subtrees;

// Function that returns true if
// tree contains a duplicate subtree
// of size 2 or more
bool dupSubUtil(Node *root)
{

    // To store subtrees
    set<string> subtrees;

    // Used to traverse tree
    queue<Node *> bfs;
    bfs.push(root);

    while (!bfs.empty())
    {
        Node *n = bfs.front();
        bfs.pop();

        // To store the left and the right
        // children of the current node
        char l = ' ', r = ' ';

        // If the node has a left child
        if (n->left != NULL)
        {
            l = n->left->key;

            // Push left node's data
            bfs.push(n->left);
        }

        // If the node has a right child
        if (n->right != NULL)
        {
            r = n->right->key;

            // Push right node's data
            bfs.push(n->right);
        }

        string subt;
        subt += n->key;
        subt += l;
        subt += r;

        if (l != ' ' || r != ' ')
        {

            // If this subtree count is greater than 0
            // that means duplicate exists
            if (!subtrees.insert(subt).second)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    Node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    root->right->right->right = newNode('E');
    root->right->right->left = newNode('D');

    cout << (dupSubUtil(root) ? "Yes" : "No");

    return 0;
}*/
/*// Check if 2 trees are mirror or not
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
int areMirror(Node *a, Node *b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    return a->data == b->data &&
           areMirror(a->left, b->right) &&
           areMirror(a->right, b->left);
}
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int main()
{
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left = newNode(4);
    a->left->right = newNode(5);

    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4);

    areMirror(a, b) ? cout << "Yes" : cout << "No";

    return 0;
}*/
/*// Sum of Nodes on the Longest path from root to leaf node
int maxPathSum(TreeNode* root){
    int maxi=INT_MIN;
    maxPathSumUtil(root,maxi);
    return maxi;
}
int maxPathSumUtil(TreeNode* root,int &maxi){
    if(!root) return 0;
    int left=max(0,maxPathSumUtil(root->left,maxi));
    int right=max(0,maxPathSumUtil(root->right,maxi));
    maxi=max(maxi,left+right+root->val);
    return max(left,right)+root->val;
}*/
// Check if given graph is tree or not.  [ IMP ]
/*// Find Largest subtree sum in a tree
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
int findLargestSubtreeSumUtil(Node *root, int &ans)
{
    if (!root)
        return 0;
    int currSum = root->key +
                  findLargestSubtreeSumUtil(root->left, ans) +
                  findLargestSubtreeSumUtil(root->right, ans);
    ans = max(ans, currSum);
    return currSum;
}
int findLargestSubtreeSum(Node *root)
{
    if (!root)
        return 0;
    int ans = INT_MIN;
    findLargestSubtreeSumUtil(root, ans);
    return ans;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);

    cout << findLargestSubtreeSum(root);
    return 0;
}*/
/*// Maximum Sum of nodes in Binary tree such that no two are adjacent
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int sumOfGrandChildren(node *node);
int getMaxSum(node *node);
int getMaxSumUtil(node *node, map<struct node *, int> &mp);

int sumOfGrandChildren(node *node, map<struct node *, int> &mp)
{
    int sum = 0;
    if (node->left)
        sum += getMaxSumUtil(node->left->left, mp) +
               getMaxSumUtil(node->left->right, mp);
    if (node->right)
        sum += getMaxSumUtil(node->right->left, mp) +
               getMaxSumUtil(node->right->right, mp);
    return sum;
}
int getMaxSumUtil(node *node, map<struct node *, int> &mp)
{
    if (!node)
        return 0;
    if (mp.find(node) != mp.end())
        return mp[node];
    int incl = node->data + sumOfGrandChildren(node, mp);
    int excl = getMaxSumUtil(node->left, mp) +
               getMaxSumUtil(node->right, mp);
    mp[node] = max(incl, excl);
    return mp[node];
}
int getMaxSum(node *node)
{
    if (node == NULL)
        return 0;
    map<struct node *, int> mp;
    return getMaxSumUtil(node, mp);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);

    cout << getMaxSum(root) << endl;
    return 0;
}*/
/*// Print all "K" Sum paths in a Binary tree
#include <bits/stdc++.h>
using namespace std;
void printVector(const vector<int> &v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void printKPathUtil(Node *root, vector<int> &path, int k)
{
    if (!root)
        return;
    path.push_back(root->data);
    printKPathUtil(root->left, path, k);
    printKPathUtil(root->right, path, k);
    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--)
    {
        f += path[j];
        if (f == k)
            printVector(path, j);
    }
    path.pop_back();
}
void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    printKPath(root, k);
    return 0;
}*/
/*// Find LCA in a Binary
treeTreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) {
        return root;
    }
    return (left != NULL) ? left : right;
}*/
/*// Find distance between 2 nodes in a Binary tree
#include <iostream>
using namespace std;
struct Node
{
    struct Node *left, *right;
    int key;
};
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
int findLevel(Node *root, int k, int level)
{
    if (!root)
        return -1;
    if (root->key == k)
        return level;

    int l = findLevel(root->left, k, level + 1);
    return (l != -1) ? l : findLevel(root->right, k, level + 1);
}
Node *findDistUtil(Node *root, int n1, int n2, int &d1,
                   int &d2, int &dist, int lvl)
{
    if (!root)
        return NULL;
    if (root->key == n1)
    {
        d1 = lvl;
        return root;
    }
    if (root->key == n2)
    {
        d2 = lvl;
        return root;
    }
    Node *left_lca = findDistUtil(root->left, n1, n2,
                                  d1, d2, dist, lvl + 1);
    Node *right_lca = findDistUtil(root->right, n1, n2,
                                   d1, d2, dist, lvl + 1);
    if (left_lca && right_lca)
    {
        dist = d1 + d2 - 2 * lvl;
        return root;
    }
    return (left_lca != NULL) ? left_lca : right_lca;
}
int findDistance(Node *root, int n1, int n2)
{
    int d1 = -1, d2 = -1, dist;
    Node *lca = findDistUtil(root, n1, n2, d1, d2,
                             dist, 1);
    if (d1 != -1 && d2 != -1)
        return dist;
    if (d1 != -1)
    {
        dist = findLevel(lca, n2, 0);
        return dist;
    }
    if (d2 != -1)
    {
        dist = findLevel(lca, n1, 0);
        return dist;
    }
    return -1;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}*/
/*// Kth Ancestor of node in a Binary tree
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
void generateArray(Node *root, int ancestors[])
{
    ancestors[root->data] = -1;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left)
        {
            ancestors[temp->left->data] = temp->data;
            q.push(temp->left);
        }

        if (temp->right)
        {
            ancestors[temp->right->data] = temp->data;
            q.push(temp->right);
        }
    }
}
int kthAncestor(Node *root, int n, int k, int node)
{
    int ancestors[n + 1] = {0};
    generateArray(root, ancestors);
    int count = 0;

    while (node != -1)
    {
        node = ancestors[node];
        count++;

        if (count == k)
            break;
    }
    return node;
}
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;
    cout << kthAncestor(root, 5, k, node);
    return 0;
}*/
/*// Find all Duplicate subtrees in a Binary tree [ IMP ]
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
string inorder(Node *node, unordered_map<string, int> &m)
{
    if (!node)
        return "";
    string str = "(";
    str += inorder(node->left, m);
    str += to_string(node->data);
    str += inorder(node->right, m);
    str += ")";
    if (m[str] == 1)
        cout << node->data << " ";
    m[str]++;
    return str;
}
void printAllDups(Node *root)
{
    unordered_map<string, int> m;
    inorder(root, m);
}
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int main()
{
    Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);
    printAllDups(root);
    return 0;
}*/
/*// Tree Isomorphism Problem
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return (temp);
}
bool isIsomorphic(node *n1, node *n2)
{
    if (!n1 && !n2)
        return true;
    if (!n1 || !n2)
        return false;
    if (n1->data != n2->data)
        return false;
    return (isIsomorphic(n1->left, n2->left) &&
            isIsomorphic(n1->right, n2->right)) ||
           (isIsomorphic(n1->left, n2->right) &&
            isIsomorphic(n1->right, n2->left));
}
int main()
{
    struct node *n1 = newNode(1);
    n1->left = newNode(2);
    n1->right = newNode(3);
    n1->left->left = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);

    struct node *n2 = newNode(1);
    n2->left = newNode(3);
    n2->right = newNode(2);
    n2->right->left = newNode(4);
    n2->right->right = newNode(5);
    n2->left->right = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);

    if (isIsomorphic(n1, n2) == true)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}*/
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
/*// Maximum Width
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
        q.push({temp -> left,cur_id * 2 + 1});
      if (temp -> right)
        q.push({temp -> right,cur_id * 2 + 2});
    }
    ans = max(ans, rightMost - leftMost + 1);
  }
  return ans;
}*/
/*// Count total Nodes in a Complete Binary Tree
int findHeightLeft(TreeNode* root){
    int hgt=0;
    while(node){
        hgt++;
        node=node->left;
    }
    return hgt;
}
int findHeightRight(TreeNode* root){
    int hgt=0;
    while(node){
        hgt++;
        node=node->right;
    }
    return hgt;
}
int countNodes(TreeNode* root) {
    if(!root) return 0;
    int lh=findHeightLeft(root);
    int rh=findHeightRight(root);
    if(lh==rh) return pow(2,lh)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
}*/
