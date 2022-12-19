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
}*/
/*// Disjoint Set
//(to find the number of connected components in a graph)
//time complexity O(4*alpha) == O(4)
#include <iostream>
using namespace std;
class DisjSet {
	int *rank, *parent, n;

public:
	DisjSet(int n)
	{
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	void makeSet()
	{
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int x)
	{
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void Union(int x, int y)
	{
		int xset = find(x);
		int yset = find(y);

		if (xset == yset)
			return;

		if (rank[xset] < rank[yset]) {
			parent[xset] = yset;
		}
		else if (rank[xset] > rank[yset]) {
			parent[yset] = xset;
		}
		else {
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
};

int main()
{
	DisjSet obj(5);
	obj.Union(0, 2);
	obj.Union(4, 2);
	obj.Union(3, 1);
	if (obj.find(4) == obj.find(0))
		cout << "Yes\n";
	else
		cout << "No\n";
	if (obj.find(1) == obj.find(0))
		cout << "Yes\n";
	else
		cout << "No\n";

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
// Binary Indexed Tree
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
		idx += (idx & -idx);
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
// time complexity O(sqrt(n))
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 2, MOD = 1e9 + 7;
int32_t main() {
	int n;cin>>n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int len = sqrtl(n)+1;
	vector<int> b(len);
	for (int i = 0; i < n; i++)
	{
		b[i/len]+=a[i];
	}
	int q;cin>>q;while (q--)
	{
		int l,r;
		cin>>l>>r;
		l--;r--;
		int sum=0;
		for (int i = l; i <=r;){
			if(i%len==0 && i+len-1<=r){
				sum+=b[i/len];
				i+=len;
			}
			else{
				sum+=a[i];
				i++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}*/
/*// Mo's Algorithm
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
#include <bits/stdc++.h>
using namespace std;
int func(int a, int b)	{return a + b;}
int nest_func(int a, int n)	{return a * n;}
vector<int> seg, lazy;
void init(vector<int> &vec, int node, int left, int right)
{
	if (left == right)
	{
		seg[node] = vec[left - 1];
		return;
	}
	init(vec, node << 1, left, (left + right) >> 1);
	init(vec, node << 1 | 1, ((left + right) >> 1) + 1, right);
	seg[node] = func(seg[node << 1], seg[node << 1 | 1]);
}

void busy(int node, int left, int right)
{
	if (!lazy[node])
		return;
	seg[node] = func(seg[node], nest_func(lazy[node], (right - left + 1)));
	if (left != right)
	{
		lazy[node << 1] = func(lazy[node << 1], lazy[node]);
		lazy[node << 1 | 1] = func(lazy[node << 1 | 1], lazy[node]);
	}
	lazy[node] = 0;
}

void update(int node, int left, int right, int start, int end, int diff)
{
	busy(node, left, right);
	if (right < start || end < left)
		return;
	if (start <= left && right <= end)
	{
		lazy[node] = diff;
		busy(node, left, right);
		return;
	}
	update(node << 1, left, (left + right) >> 1, start, end, diff);
	update(node << 1 | 1, ((left + right) >> 1) + 1, right, start, end, diff);
	seg[node] = func(seg[node << 1], seg[node << 1 | 1]);
}

int query(int node, int left, int right, int start, int end)
{
	busy(node, left, right);
	if (start <= left && right <= end)
		return seg[node];
	int mid = (left + right) >> 1;
	if (mid < start)
		return query(node << 1 | 1, mid + 1, right, start, end);
	if (mid + 1 > end)
		return query(node << 1, left, mid, start, end);
	return func(query(node << 1, left, mid, start, end), query(node << 1 | 1, mid + 1, right, start, end));
}

int main()
{
	int size = 4;
	seg.resize(4 * size);
	lazy.resize(4 * size);
	vector<int> vec{1, 2, 3, 4};
	init(vec, 1, 1, size);
	update(1, 1, size, 2, 3, 4);
	cout << query(1, 1, size, 2, 4) << endl;
}*/
