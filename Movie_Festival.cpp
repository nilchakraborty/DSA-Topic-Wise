/* NILANJIT CHAKRABORTY */
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ses "\n"
#define PI 3.141592653589793238462
#define MOD 1000000007
#define INF 1e18
#define float double
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define set_bits __builtin_popcountll
#define SORTV(a) sort(a.begin(), a.end())
#define SORTA(a, n) sort(a, a + n)
#define rFO(i, n) for (int i = n - 1; i >= 0; i--)
#define FO(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define co cout <<
#define UNIQUEA(a,n) unique(a,a+n)-a
#define COUNT(str,ch) count(str.begin(),str.end(),ch)
#define MAXA(a,n) *max_element(a,a+n)
#define MINA(a,n) *min_element(a,a+n)
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define REV(v) reverse(v.begin(),v.end())
#define MAXV(v) *max_element(v.begin(),v.end())
#define MINV(v) *min_element(v.begin(),v.end())
#define w(x)	int x; cin >> x; while(x--)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
typedef pair<int, int>	pii;
typedef vector<int>		vi;
/*---------------------------------------------------------------------------------------------------------------------------*/
ll lcm(ll a, ll b){return (a/__gcd(a,b)*b);}
void printarr(ll arr[], ll n){FO(i,n) cout << arr[i] << " ";cout << "\n";}
bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
void Sieve(int n){bool prime[n + 1];memset(prime, true, sizeof(prime));for (int p = 2; p * p <= n; p++){if (prime[p] == true){for (int i = p * p; i <= n; i += p)prime[i] = false;}}for (int p = 2; p <= n; p++)if (prime[p])cout << p << " ";}
void precision(int a) {cout << setprecision(a) << fixed;}
/*---------------------------------------------------------------------------------------------------------------------------*/
void nilzz(){
    int n,x,y,cur=0,ans=0;
    cin >> n;
    vector<pii> v;
    FO(i,n){
        cin >> x >> y;
        v.pb(mp(y,x));
    }
    sort(v.begin(),v.end());
    for(auto i:v){
        if(i.S>=cur){
            cur = i.F;
            ans++;
        }
    }
    cout << ans << ses;
}
int32_t main()
{
    fast
    //my code
    nilzz();
    return 0;
}