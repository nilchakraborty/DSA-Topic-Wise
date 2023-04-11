/*//Sieve of Eratosthenes
//(to print all prime numbers in given range)
//time complexity O(N log (log N))
#include <bits/stdc++.h>
using namespace std;
void Sieve(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}
int main()
{
	Sieve(500);
	return 0;
}
Time Complexity: O(n log log n)
Space Complexity: O(n)*/
/*// Prime Factorization using Sieve
void primefactor( (int n) {
	int spf[n + 1] = {0};
	for (int i = 2; i <= n; i++){
		spf[i] = i;
	}
	for (int i = 2; i <= n; i++){
		if (spf[i] == i){
			for (int j = i * i; j <= n; j += i){
				if (spf[j] == j){
					spf[j] = i;
				}
			}
		}
	}
	while (n != 1){
		cout << spf[n] << "";
		n = n / spf[n];
	}
}
Time Complexity for factorization: O(log n)
Space Complexity: O(n)*/
/*// Disjoint Set
//to find the number of connected components in a graph
//time complexity O(alpha(n))
#include <iostream>
using namespace std;
class DisjSet {
    vector<int> parent, rank;
public:
    DisjSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y) {
        int xset = find(x);
        int yset = find(y);
        if (xset == yset)
            return;
        if (rank[xset] < rank[yset])
            swap(xset, yset);
        parent[yset] = xset;
        if (rank[xset] == rank[yset])
            rank[xset]++;
    }
};
int main() {
    DisjSet obj(5);
    obj.Union(0, 2), obj.Union(4, 2), obj.Union(3, 1);
    cout << (obj.find(4) == obj.find(0) ? "Yes\n" : "No\n");
    cout << (obj.find(1) == obj.find(0) ? "Yes\n" : "No\n");
    return 0;
}*/
/*//Range sum query O(n)
#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pre[n];
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = arr[i] + pre[i - 1];
    cout << pre[3] - pre[0] << endl;
    return 0;
}*/
/*//Sparse Table
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int K = 20;

int st[MAXN][K + 1];
int lg[MAXN];

void preprocess(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }

    for (int j = 1; j <= K; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}

int query(int L, int R)
{
    int j = lg[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main()
{
    int n, arr[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    preprocess(arr, n);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}*/
/*//Binary lifting for LCA in O(logn)
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int LOGN = 20;

vector<int> adj[MAXN];
int parent[MAXN][LOGN];
int depth[MAXN];

void dfs(int u, int p) {
    parent[u] = p;
    depth[u] = depth[p] + 1;
    for (int i = 1; i < LOGN; i++) {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

int kthAncestor(int u, int k) {
    for (int i = LOGN - 1; i >= 0; i--) {
        if (k >= (1 << i)) {
            u = parent[u][i];
            k -= (1 << i);
        }
    }
    return u;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(1, 0);
    while (q--) {
        int u, k;
        cin >> u >> k;
        cout << kthAncestor(u, k) << endl;
    }
    return 0;
}*/
/*// Segment tree
// prefix sum tree
// time complexity O(log N) for bot query and update
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 2, MOD = 1e9 + 7;
int tree[4 * N], a[N];
void build(int node, int st, int en)
{
	if (st == en)
	{
		tree[node] = a[st];
		return;
	}
	int mid = (st + en) / 2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, en);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int st, int en, int l, int r)
{
	if (en < l || st > r)
	{
		return INT_MIN;
	}
	if (l <= st && en <= r)
		return tree[node];
	int mid = (st + en) / 2;
	int q1 = query(2 * node, st, mid, l, r);
	int q2 = query(2 * node + 1, mid + 1, en, l, r);
	return max(q1, q2);
}
void update(int node, int st, int en, int idx, int val)
{
	if (st == en)
	{
		a[st] = val;
		tree[node] = val;
		return;
	}
	int mid = (st + en) / 2;
	if (idx <= mid)
	{
		update(2 * node, st, mid, idx, val);
	}
	else
	{
		update(2 * node + 1, mid + 1, en, idx, val);
	}
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
signed main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	build(1, 0, n - 1);
	while (1)
	{
		int type;
		cin >> type;
		if (type == -1)
			break;
		if (type == 1)
		{
			int l, r;
			cin >> l >> r;
			int ans = query(1, 0, n - 1, l, r);
			cout << ans << endl;
		}
		else if (type == 2)
		{
			int idx, val;
			cin >> idx >> val;
			update(1, 0, n - 1, idx, val);
			cout << query(1, 0, n - 1, 0, n - 1) << endl;
		}
	}
	return 0;
}*/
/*// Fenwick tree
// also called Binary Indexed Tree
// time complexity O(log N)
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> bit;
void update(int idx, int val)
{
	while (idx <= n)
	{
		bit[idx] += val;
		idx += idx & (-idx);
	}
}
int query(int idx)
{
	int ans = 0;
	while (idx > 0)
	{
		ans += bit[idx];
		idx -= idx & (-idx);
	}
	return ans;
}
int32_t main()
{
	cin >> n;
	bit = vector<int>(n + 1);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		update(i,a[i]);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int c;
		cin >> c;
		if (c == 1)
		{
			int l, r;
			cin >> l >> r;
			int ans = query(r) - query(l - 1);
			cout << ans << "\n";
		}
		else if (c == 2)
		{
			int index, val;
			cin >> index >> val;
			update(index, -a[index]);
			a[index] = val;
			update(index, val);
		}
	}
	return 0;
}*/
/*// Square Root Decomposition
// used for range queries in an array,is better suited for problems that involve online queries
// time complexity O(sqrt(n))
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000; // maximum array size
int block_size; // size of each block
vector<int> a(MAXN); // original array
vector<int> b(MAXN); // decomposed array

// build the decomposed array
void build() {
    int n = a.size();
    block_size = ceil(sqrt(n));
    for (int i = 0; i < n; i++) {
        b[i / block_size] += a[i];
    }
}

// query the sum in range [l, r]
int query(int l, int r) {
    int sum = 0;
    for (int i = l; i <= r;) {
        if (i % block_size == 0 && i + block_size - 1 <= r) {
            sum += b[i / block_size];
            i += block_size;
        } else {
            sum += a[i];
            i++;
        }
    }
    return sum;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build();
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}*/
/*// Mo's Algorithm
// used for range queries in an array,is better suited for problems that involve offline queries
// time complexity O((m+n) * √n)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 2, MOD = 1e9 + 7;
int rootN = sqrtl(N);
struct Q
{
	int idx, l, r;
};
Q q[N];
bool compare(Q a, Q b)
{
	if (a.l / rootN == b.l / rootN)
		return a.r < b.r;
	return a.l / rootN < b.l / rootN;
}
int32_t main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int queries;
	cin >> queries;
	for (int i = 0; i < queries; i++)
	{
		int l, r;
		cin >> l >> r;
		q[i].l = l;
		q[i].r = r;
		q[i].idx = i;
	}
	sort(q, q + queries, compare);
	vector<int> ans(queries);
	int curr_l=0,curr_r=-1,l,r;
	int curr_ans=0;
	for (int i = 0; i < queries; i++)
	{
		l=q[i].l;r=q[i].r;
		l--;r--;
		while(curr_r<r){
			curr_r++;
			curr_ans+=a[curr_r];
		}
		while(curr_l>l){
			curr_l--;
			curr_ans+=a[curr_l];
		}
		while(curr_l<l){
			curr_ans-=a[curr_l];
			curr_l++;
		}
		while(curr_r>r){
			curr_ans-=a[curr_r];
			curr_r--;
		}
		ans[q[i].idx]=curr_ans;
	}
	for (int i = 0; i < queries; i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}*/
/*// Lazy Propagation
// time complexity O(logN)
// The code provided implements a segment tree data structure, which is commonly used to efficiently answer range queries and update operations over an array.
// The init function initializes the segment tree by recursively building the tree from the bottom up. It starts by taking the input array vec and setting the values of the leaf nodes of the segment tree to the corresponding values of the input array. Then, it computes the values of the parent nodes of the tree by aggregating the values of their children using a specified function func.
// The propagate function propagates the value of the lazy update to the children of the current node if it is not a leaf node. It first checks if the lazy value of the current node is non-zero, indicating that there is a pending update that needs to be applied. If the current node is not a leaf node, it sets the lazy value of its children to the sum of their current value and the lazy value of the current node. Finally, it sets the lazy value of the current node to zero, indicating that it has been propagated to its children.
// The update function performs a range update on the segment tree. It first propagates the lazy update value of the current node to its children using the busy function. It then checks if the range specified by the input parameters is completely outside the range covered by the current node. If so, it simply returns without doing anything. If the range specified by the input parameters is completely inside the range covered by the current node, it sets the lazy update value of the current node to the input value diff and propagates it to its children using the busy function. If the range specified by the input parameters partially overlaps with the range covered by the current node, it recursively updates its left and right children with the same update function call.
// The query function performs a range query on the segment tree. It first propagates the lazy update value of the current node to its children using the busy function. It then checks if the range specified by the input parameters is completely inside the range covered by the current node. If so, it returns the value of the current node. If the range specified by the input parameters is completely outside the range covered by the current node, it returns a neutral value (e.g. 0 for sum queries). If the range specified by the input parameters partially overlaps with the range covered by the current node, it recursively queries its left and right children with the same query function call, and aggregates their results using the specified function func.
#include <bits/stdc++.h>
using namespace std;
int func(int a, int b) {return a + b;}
vector<int> seg, lazy;
void init(vector<int> &vec, int node, int left, int right) {
    if (left == right) {seg[node] = vec[left - 1]; return;}
    init(vec, node << 1, left, (left + right) >> 1);
    init(vec, node << 1 | 1, ((left + right) >> 1) + 1, right);
    seg[node] = func(seg[node << 1], seg[node << 1 | 1]);
}
void propagate(int node, int left, int right) {
    seg[node] += lazy[node] * (right - left + 1);
    if (left != right) lazy[node << 1] += lazy[node], lazy[node << 1 | 1] += lazy[node];
    lazy[node] = 0;
}
void update(int node, int left, int right, int start, int end, int val) {
    propagate(node, left, right);
    if (right < start || end < left) return;
    if (start <= left && right <= end) {lazy[node] += val; propagate(node, left, right); return;}
    update(node << 1, left, (left + right) >> 1, start, end, val);
    update(node << 1 | 1, ((left + right) >> 1) + 1, right, start, end, val);
    seg[node] = func(seg[node << 1], seg[node << 1 | 1]);
}
int query(int node, int left, int right, int start, int end) {
    propagate(node, left, right);
    if (start <= left && right <= end) return seg[node];
    if (right < start || end < left) return 0;
    return func(query(node << 1, left, (left + right) >> 1, start, end),
                query(node << 1 | 1, ((left + right) >> 1) + 1, right, start, end));
}
int main() {
    int n = 4;
    seg.resize(4 * n);
    lazy.resize(4 * n);
    vector<int> vec = {1, 2, 3, 4};
    init(vec, 1, 1, n);
    update(1, 1, n, 2, 3, 4);
    cout << query(1, 1, n, 2, 4) << endl;
    return 0;
}*/
/*// Sum over subsets
// time complexity O(N*2^N)
//This algorithm can be used in various applications such as data compression, combinatorial optimization, and in solving certain types of dynamic programming problems.
// This function takes an integer array a and its size n as input
void SumOverSubsets(int a[], int n) {
  // initialize an array sos to store the SumOverSubsets with size 2^n
  int sos[1 << n] = {0};
  // iterate for all possible x (subsets)
  for (int x = 0; x < (1 << n); x++) {
    // iterate for all possible bitwise subsets of x
    for (int i = 0; i < (1 << n); i++) {
      // if i is a bitwise subset of x, add its value to the SumOverSubsets of x
      if ((x & i) == i)
        sos[x] += a[i];
    }
  }
  // print all the subsets' SumOverSubsets
  for (int i = 0; i < (1 << n); i++)
    cout << sos[i] << " ";
}*/
/*//matrix exponentiation
// time complexity O(logN) for matrix multiplication
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2;
ll mod=1e9+7;
struct matrix{
    ll mat[N][N];
};
matrix mul(matrix a,matrix b){
    matrix ans;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans.mat[i][j]=0;
            for(int k=0;k<N;k++){
                ans.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%mod;
                ans.mat[i][j]%=mod;
            }
        }
    }
    return ans;
}
matrix power(matrix a,ll n){
    matrix ans;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans.mat[i][j]=(i==j);
        }
    }
    while(n){
        if(n&1){
            ans=mul(ans,a);
        }
        a=mul(a,a);
        n>>=1;
    }
    return ans;
}
int main(){
    matrix a;
    a.mat[0][0]=0; a.mat[0][1]=1;
    a.mat[1][0]=1; a.mat[1][1]=1;
    ll n=10;
    matrix ans=power(a,n);
    cout<<ans.mat[1][1]<<endl; //prints 89
    return 0;
}*/
/*//Sprague-Grundy Theorem
https://www.geeksforgeeks.org/combinatorial-game-theory-set-4-sprague-grundy-theorem/*/
