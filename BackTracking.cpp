/*// Recursion concept: Base condition, Hypothesis, Induction =>
// print 1 to n using recursion
void print(int n){
    //base condition
    if(n==1){
        cout<<n<<" ";
        return;
    }
    //hypothesis
    print(n - 1);
    //induction
    cout << n << " ";
}
//print n to 1 using recursion
void print(int n){
    //base condition
    if(n==1){
        cout<<n<<" ";
        return;
    }
    //induction
    cout << n << " ";
    //hypothesis
    print(n - 1);
}*/
/*//Implement Pow(x,n) | X raised to the power N
// Time Complexity: O(log n)
double myPow(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
}*/
/*//Generate Parentheses
vector<string> generateParenthesis(int n) {
    vector<string> ret;
    helper(ret, "", n, n);
    return ret;
}
void helper(vector<string> & res, string str, int left, int right){
    if(left == 0 && right == 0){
        res.push_back(str);
        return;
    }
    if(left > 0) helper(res, str + "(", left - 1, right);
    if(right > left) helper(res, str + ")", left, right - 1);
}*/
/*//Power Set: Print all the possible subsequences of the String
void printSubsequence(string input, string output){
    if (input.empty()) {
        cout << output << endl;
        return;
    }
    printSubsequence(input.substr(1), output + input[0]);
    printSubsequence(input.substr(1), output);
}*/
/*//Subset Sum
// Given an array print all the sum of the subset generated from it, in the increasing order.
// Time Complexity: O(2^n)+O(2^n log(2^n)) || Space Complexity: O(2^n)
void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
    if (ind == n) {
    ans.push_back(sum);
    return;
    }
    //element is picked
    subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
    //element is not picked
    subsetSumsHelper(ind + 1, arr, n, ans, sum);
}
vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}*/
/*//Subset – II | Print all the Unique Subsets
// Time Complexity: O( 2^n *(k log (x) )) || Space Complexity:  O(2^n * k)
void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
    if (index == nums.size()) {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
    }
    ds.push_back(nums[index]);
    fun(nums, index + 1, ds, res);
    ds.pop_back();
    fun(nums, index + 1, ds, res);
}
vector < vector < int >> subsetsWithDup(vector < int > & nums) {
    vector < vector < int >> ans;
    set < vector < int >> res;
    vector < int > ds;
    fun(nums, 0, ds, res);
    for (auto it = res.begin(); it != res.end(); it++) {
      ans.push_back( * it);
    }
    return ans;
}*/
/*//Combination Sum
//unique combinations that sum up to target
//Time Complexity: O(2^t * k) || Space Complexity: O(k*x)
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
    if (ind == arr.size()) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }
    // pick up the element 
    if (arr[ind] <= target) {
    ds.push_back(arr[ind]);
    findCombination(ind, target - arr[ind], arr, ans, ds);
    ds.pop_back();
    }
    findCombination(ind + 1, target, arr, ans, ds);
}
vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
    vector < vector < int >> ans;
    vector < int > ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}*/
/*//Combination Sum II – Find all unique combinations
//Time Complexity: O(2^n * k) || Space Complexity: O(k*x)
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}*/
/*//Letter Combination of a Phone Number
void solve(string digit, string output, int index, vector<string> &ans, string mapping[]){
    if (index >= digit.length()){
        ans.push_back(output);
        return;
    }
    int number = digit[index] - '0';
    string value = mapping[number];
    for (int i = 0; i < value.length(); i++){
        output.push_back(value[i]);
        solve(digit, output, index + 1, ans, mapping);
        output.pop_back();
    }
}
vector<string> letterCombinations(string digits){
    vector<string> ans;
    if (digits.length() == 0)
        return ans;
    string output = "";
    int index = 0;
    string mapping[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    solve(digits, output, index, ans, mapping);
    return ans;
}*/
/*//Palindrome Partitioning
Time Complexity: O( (2^n) *k*(n/2) ) || Space Complexity: O(k * x)
vector < vector < string >> partition(string s) {
    vector < vector < string > > res;
    vector < string > path;
    partitionHelper(0, s, path, res);
    return res;
}
void partitionHelper(int index, string s, vector < string > & path,vector < vector < string > > & res) {
    if (index == s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = index; i < s.size(); ++i) {
        if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        partitionHelper(i + 1, s, path, res);
        path.pop_back();
        }
    }
}
bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
}*/
/*//Word Search
//Time Complexity: O(m*n*4^k) || Space Complexity: O(k)
#include<bits/stdc++.h>
using namespace std;
bool searchNext(vector<vector<char>> &board, string word, int row, int col, int index, int m, int n) {
    if (index == word.length())
        return true;
    if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[index] or board[row][col] == '!')
        return false;
    char c = board[row][col];
    board[row][col] = '!';
    bool top = searchNext(board, word, row - 1, col, index + 1, m, n);
    bool right = searchNext(board, word, row, col + 1, index + 1, m, n);
    bool bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
    bool left = searchNext(board, word, row, col - 1, index + 1, m, n);
    board[row][col] = c;
    return top || right || bottom || left;
}
bool exist(vector<vector<char>> board, string word) {
    int m = board.size(), n = board[0].size();
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[index]) {
                if (searchNext(board, word, i, j, index, m, n))
                    return true;
            }
        }
    }
    return false;
}
int main() {
    vector<vector<char>> board {{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};
    string word = "ABCCED";
    bool res = exist(board, word);
    if(res==1)
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}*/
/*//N Queen Problem
// time Complexity: O(N! * N) || space : O(N)
void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
    if (col == n) {
    ans.push_back(board);
    return;
    }
    for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
        board[row][col] = 'Q';
        leftrow[row] = 1;
        lowerDiagonal[row + col] = 1;
        upperDiagonal[n - 1 + col - row] = 1;
        solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        board[row][col] = '.';
        leftrow[row] = 0;
        lowerDiagonal[row + col] = 0;
        upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}
vector < vector < string >> solveNQueens(int n) {
    vector < vector < string >> ans;
    vector < string > board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
    board[i] = s;
    }
    vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
    return ans;
}*/
/*//Rate in a Maze
void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,vector < vector < int >> & vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        vis[i][j] = 1;
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        vis[i][j] = 0;
        }
    }
}
vector < string > findPath(vector < vector < int >> & m, int n) {
    vector < string > ans;
    vector < vector < int >> vis(n, vector < int > (n, 0));
    int di[] = {+1,0,0,-1};
    int dj[] = {0,-1,1,0};
    if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
    return ans;
}*/
/*//M Coloring Problem
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }
  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }
  }
  return false;
}
bool graphColoring(bool graph[101][101], int m, int N) {
  int color[N] = {
    0
  };
  if (solve(0, color, m, N, graph)) return true;
  return false;
}*/
/*//Sudoku Solver
#include<bits/stdc++.h>
using namespace std;
bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;
    if (board[row][i] == c)
      return false;
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}
bool solveSudoku(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;
            if (solveSudoku(board))
              return true;
            else
              board[i][j] = '.';
          }
        }
        return false;
      }
    }
  }
  return true;
}
int main() {
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
    solveSudoku(board);
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}*/
/*// The Knight’s tour problem
#include <bits/stdc++.h>
using namespace std;
#define N 8
int solveKTUtil(int x, int y, int movei, int sol[N][N],int xMove[], int yMove[]);
int isSafe(int x, int y, int sol[N][N]){
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}
void printSolution(int sol[N][N]){
    for (int x = 0; x < N; x++){
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}
int solveKT(){
    int sol[N][N];
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    sol[0][0] = 0;
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0){
        cout << "Solution does not exist";
        return 0;
    }
    else
        printSolution(sol);
    return 1;
}
int solveKTUtil(int x, int y, int movei, int sol[N][N],int xMove[N], int yMove[N]){
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;
    for (k = 0; k < 8; k++){
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)){
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,xMove, yMove) == 1)
                return 1;
            else
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}
int main()
{
    solveKT();
    return 0;
}*/