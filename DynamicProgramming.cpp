🙏 Aditya Verma's DP Playlist: https://www.youtube.com/playlist?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go

•	0/1 knapsack problem using recursion:
Int knapsack(int w, int wt[], int val[], int n){
    // base case
    if (n == 0 || w == 0)	return 0;
    // if weight of the nth item is more than knapsack capacity w, then this item cannot be included
    if (wt[n - 1] > w)
        return knapsack(w, wt, val, n - 1);
    // return the maximum of two cases:(1) nth item included & (2) not included
    else
        return max(val[n - 1] + knapsack(w - wt[n - 1], wt, val, n - 1), knapsack(w, wt, val, n - 1));
}
Time complexity: o(2n)
Auxiliary space: o(1)

•	0/1 knapsack problem using memoization:
Int static t[n+1][w+1];
Memset(t,-1,sizeof(t));
Int knapsack(int wt[], int val[], int w, int n) {
    // base case
    if (n == 0 || w == 0)	return 0;
    // if already calculated
    if (t[n][w] != -1)
        return t[n][w];
    // else calculate
    if (wt[n - 1] <= w)
        return t[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
    else if (wt[n - 1] > w)
        return t[n][w] = knapsack(wt, val, w, n - 1);
}
Time complexity: o(n * w).  
Auxiliary space: o(n * w) 

•	Knapsack top_down:
Int knapsack(int wt[], int val[], int w, int n) {
	int t[n + 1][w + 1]; // dp matrix

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			if (i == 0 || j == 0) // base case
				t[i][j] = 0;
			else if (wt[i - 1] <= j) { // current wt can fit in bag
				t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
			}
			else if (wt[i - 1] > j) // current wt doesn't fit in bag
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][w];
}
Time complexity: o(n * w). 
Auxiliary space: o(n * w).

>> From this all has o(n*w) time and space

•	Difference of 0/1 knapsack and unbounded knapsack problems:
For   0 1 knapsack 
Dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
Unbounded knapsack problem, the recurrence relation is:
Dp[i][w] = max(val[i-1] + dp[i][w-wt[i-1]], dp[i-1][w]);
=>as you can see, the only difference is that in the unbounded knapsack problem, we use dp[i][w-wt[i-1]] instead of dp[i-1][w-wt[i-1]] to account for the fact that we can use item i multiple times.

👉🏻 Types of 0-1 Knapsack Problems:

•	Subset sum:

Bool issubsetposs(int arr[], int n, int sum) {
    bool t[n + 1][sum + 1];  // dp - matrix
    memset(t, false, sizeof(t));

    // initializing the first row with true
    for (int i = 0; i <= sum; i++)
        t[0][i] = false;

    // initializing the first column with true
    for (int i = 0; i <= n; i++)
        t[i][0] = true;

    // filling up the dp matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

•	Count the number of subsets with a given sum:
//just change bool to int and true to 1
Int countsubsets(int arr[], int n, int sum) {
    int t[n + 1][sum + 1]; // dp - matrix
    memset(t, 0, sizeof(t));

    // initializing the first row with 1
    for (int i = 0; i <= sum; i++)
        t[0][i] = 0;

    // initializing the first column with 1
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;

    // filling up the dp matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}

•	Minimum subset sum difference:
Int minsubsetsumdiff(int arr[], int n) {
    int range = 0;
    for (int i = 0; i < n; i++) {
        range += arr[i];
    }

    bool t[n + 1][range + 1];
    memset(t, false, sizeof(t));

    for (int i = 0; i <= n; i++) {
        t[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= range; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
            }
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    int diff = int_max;
    for (int j = range/2; j >= 0; j--) {
        if (t[n][j]) {
            diff = range - 2*j;
            break;
        }
    }

    return diff;
}

•	Count the number of subset with a given difference:
Let sum of subset 1 be s1 and subset 2 with s2
S1 - s2 = diff (given)
S1 + s2=sum of array (logical)
Therefore adding both eq we get :
2s1= diff + sum of array
S1= (diff + sum of array)/2; here s1 is called reqsum in below code
Int countsubsetswithgivendiff(int arr[], int n, int diff) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int reqsum = (diff + sum) / 2;

    int dp[n + 1][reqsum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= reqsum; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= reqsum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][reqsum];
}
•	Target sum:
Class solution {
Public:
    int findtargetsumways(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (target > sum || target < -sum) {
            return 0;
        }
 //suppose nums is 1 2 3 then using + maximum is 6 and using -ve sign minimum is -6 to cover this range we take 2 *sum
        int dp[n+1][2*sum+1];
        memset(dp, 0, sizeof(dp));
        
        // initialize base case
        dp[0][sum] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2*sum; j++) {
//adding the current element to the sum
//subtracting the current element from the sum

                if (j+nums[i-1] <= 2*sum) {
                    dp[i][j] += dp[i-1][j+nums[i-1]];
                }
                if (j-nums[i-1] >= 0) {
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
            }
        }
        
        return dp[n][target+sum];
    }
};

👉🏻 Types of Unbound Knapsack Problems:

•	Rod cutting problem
Int rod_cutting(int n, vector<int>& val) {
    vector<int> dp(n+1, 0); // initialize a 1d vector to store the solutions to sub-problems

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], val[j-1] + dp[i-j]); // recurrence relation for rod cutting
        }
    }

    return dp[n]; // return the solution to the original problem
}

•	Coin change problem: maximum number of ways:
Int coinchange(int coins[], int n, int amount) {
    int dp[n+1][amount+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=amount;j++) {
            if(coins[i-1]<=j) dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][amount];
}
** in the choice diagram approach, when we are asked to find the maximum or minimum value, we use the "or" operator because we need to choose the branch that gives us the desired maximum or minimum value. On the other hand, when we are asked to find the count or number of ways, we use the "+" operator because we need to consider all the possible branches that lead to the desired count or number of ways.

👉🏻 Types of LCS Problems:

•	Longest common subsequence: recursive approach
Int lcs(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1 + lcs(x, y, m - 1, n - 1);
    else
        return max(lcs(x, y, m, n - 1),
                   lcs(x, y, m - 1, n));
}

•	Longest common subsequence memoization
Vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
Int lcs(string x, string y, int n, int m) {
	if (n == 0 || m == 0) dp[n][m] = 0;
	if (dp[n][m] != -1) return dp[n][m];
	if (x[n - 1] == y[m - 1])
		return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1);
	else
		return dp[n][m] = max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
}

•	Longest common subsequence top down
int lcs(string x, string y, int m, int n) {
    int l[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                l[i][j] = 0;
            } else if (x[i - 1] == y[j - 1]) {
                l[i][j] = l[i - 1][j - 1] + 1;
            } else {
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
            }
        }
    }
    return l[m][n];
}

•	Longest common substring:
Int lcs(string x, string y, int m, int n){
    int l[m + 1][n + 1];
    int maxlen = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                l[i][j] = 0;
            } else if (x[i - 1] == y[j - 1]) {
                l[i][j] = l[i - 1][j - 1] + 1;
                maxlen = max(maxlen, l[i][j]);
            } else {
                l[i][j] = 0;
            }
        }
    }
    return maxlen;
}

•	Printing longest common subsequence: 
String lcs(string x, string y, int m, int n){
    int l[m + 1][n + 1];
    // initialize the first row and column of l array to 0
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0)
                l[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                l[i][j] = l[i - 1][j - 1] + 1;
            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
        }
    }
    // traverse the l array from bottom right to top left to get the lcs
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0){
        if (x[i - 1] == y[j - 1]){
            lcs += x[i - 1];
            i--,j--;
        }
        else if (l[i - 1][j] > l[i][j - 1])
            i--;
        else
            j--;
    }
    return lcs;
}

•	Shortest common supersequence:      
Int scs(string x, string y, int n, int m) {
	return m + n - lcs(x, y, n, m); // formula // n-> length of string x ; m-> length of string y
}
** the scs is the smallest string that contains both x and y as subsequences. Therefore, it needs to contain all the characters of both strings. However, if some characters appear in both strings, we dont want to count them twice in the scs, so we subtract the length of the lcs between x and y from the sum of lengths of both strings.

•	Minimum insertion deletion to convert a to b:
Void mininsertdel(string x, string y, int n, int m) {
	int lcs_len = lcs(x, y, n, m);
	cout << "minimum number of deletions = " << (n - lcs_len)<<endl;
  	cout << "minimum number of insertions = " << (m - lcs_len)<<endl;
}

•	Edit Distance:
int editDistance(string s, string t) {
int m = s.length(), n = t.length();
int dp[m+1][n+1];
for(int i=0; i<=m; i++){
	for(int j=0; j<=n; j++){
		if(i == 0) dp[i][j] = j;
        else if(j == 0) dp[i][j] = i;
        else if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
        else{
dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});//insert,remove,replace
        }
    }
}
return dp[m][n];
}

•	Longest palindromic subsequence:
Int lps(string x, int n) {
	string rev_x = x;
	reverse(rev_x.begin(), rev_x.end()); // reverse the string // take reversed string as another string of lcs and apply lcs 
	return lcs(x, rev_x, n, n);
}

•	Minimum number of deletion in a string to make it a palindrome:
int LPS(string X, int n) {
	string rev_X = X;
	reverse(rev_X.begin(), rev_X.end());
	return LCS(X, rev_X, n, n);
}
// . minimum number of deletions 
  // min = n – len
int MinDelForPallindrome(string X, int n) {
	return n - LPS(X, n); // substract LPS from the length of string to get Minimum number of deletions to make a string palindrome
}

•	Print Shortest Common Supersequence:
string SCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	int i = n, j = m;
	string scs = "";
	while (i > 0 && j > 0) {
		if (X[i - 1] == Y[j - 1]) { // when char are eqaul from table obs 
			scs += X[i - 1]; // take only once 
			i--, j--; // and decrement both
		}
		else if (dp[i][j - 1] > dp[i - 1][j]) {
			scs += Y[j - 1]; // in this we will take the charecter to string 
			j--;
		}
		else {
			scs += X[i - 1]; // taking the charecter to string 
			i--;
		}
	}
	while (i > 0) {
		scs += X[i - 1]; // take left chareter from str1
		i--;
	}
	while (j > 0) {
		scs += Y[j - 1]; // take left chareter from str1
		j--;
	}
	reverse(scs.begin(), scs.end());
	return scs;
}

•	Longest Repeating Subsequence:
Int main() {
	string X; cin >> X;int n = X.length();
	cout << LCS(X, X, n, n) << endl;
}

•	Sequence Pattern Matching:
bool SeqPatternMatching(string X, string Y, int n, int m) {
	return LCS(X, Y, n, m) == min(n, m 
}

•	Minimum number of insertion in a string to make it a palindrome:
int MinInsertForPallindrome(string X, int n) {
	return n - LPS(X, n);
}

👉🏻 Types of MCM Problems:

•	MCM Recursive: 
int Solve(int arr[], int i, int j) {
	if (i >= j)     return 0;
	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, temp_ans);
	}
	return ans;
}

•	MCM Memoization:
const int D = 1000;
int t[D][D];
int Solve(int arr[], int i, int j) {
if (i >= j) {
t[i][j] = 0;     return 0;}
if (t[i][j] != -1)return t[i][j]; 
int ans = INT_MAX;
for (int k = i; k <= j - 1; k++) {
int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
ans = min(ans, temp_ans);
}
return t[i][j] = ans;
}


•	Palindrome Partitioning Recursive:
bool isPallindrome(string X, int i, int j) {
	while (i <= j) {
		if (X[i] != X[j])
			return false;
		i++, j--;
	}
	return true;
}
int Solve(string X, int i, int j) {
	if (i >= j || isPallindrome(X, i, j))
		return 0;
	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp_ans = Solve(X, i, k) + Solve(X, k + 1, j) + 1;
		ans = min(ans, temp_ans);
	}
	return ans;
}

•	Palindrome Partitioning Memoization:
const int D = 1001;
int t[D][D];
bool isPallindrome(string X, int i, int j) {
	while (i <= j) {
		if (X[i] != X[j])
			return false;
		i++, j--;
	}
	return true;
}
int Solve(string X, int i, int j) {
	if (i >= j || isPallindrome(X, i, j)) {
		t[i][j] = 0;
		return 0;
	}
	if (t[i][j] != -1)
		return t[i][j];
	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp_ans = Solve(X, i, k) + Solve(X, k + 1, j) + 1;
		ans = min(ans, temp_ans);
	}
	return t[i][j] = ans;
}

•	Palindrome Partitioning Memoized optimization:
const int D = 1001;
int t[D][D];
bool isPallindrome(string X, int i, int j) {
	while (i <= j) {
		if (X[i] != X[j])
			return false;
		i++, j--;
	}
	return true;
}
int Solve(string X, int i, int j) {
	if (t[i][j] != -1)
		return t[i][j];
	if (i >= j || isPallindrome(X, i, j)) {
		t[i][j] = 0;
		return 0;
	}
	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
**The variables left and right store the values of the subproblems for the substrings from i to k and from k+1 to j, respectively. This allows us to retrieve the values from the memoized table if they have already been computed, thus reducing the number of recursive calls and making the algorithm more efficient.
		int left, right;
		if (t[i][k] == -1)
			left = Solve(X, i, k);
		else
			left = t[i][k];
		if (t[k + 1][j] == -1)
			right = Solve(X, k + 1, j);
		else
			right = t[k + 1][j];
		int temp_ans = left + right + 1;
		ans = min(ans, temp_ans);
	}
	return t[i][j] = ans;
}

•	Evaluate Expression to true Recursive:
int Solve(string X, int i, int j, bool isTrue) {
	if (i >= j) {
		if (isTrue)
			return X[i] == 'T';
		else
			return X[i] == 'F';
	}
	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int l_T = Solve(X, i, k - 1, true);
		int l_F = Solve(X, i, k - 1, false);
		int r_T = Solve(X, k + 1, j, true);
		int r_F = Solve(X, k + 1, j, false);
		if (X[k] == '|') {
			if (isTrue == true)
				ans += l_T * r_T + l_T * r_F + l_F * r_T;
			else
				ans += l_F * r_F;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += l_T * r_T;
			else
				ans += l_T * r_F + l_F * r_T + l_F * r_F;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += l_T * r_F + l_F * r_T;
			else
				ans += l_T * r_T + l_F * r_F;
		}
	}
	return ans;
}

•	Evaluate expression to true memoization using map:
unordered_map<string, int> ump;
int Solve(string X, int i, int j, bool isTrue) {
	string key = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");
	if (ump.find(key) != ump.end())
		return ump[key];
	if (i >= j) {
		if (isTrue)
			ump[key] = X[i] == 'T';
		else
			ump[key] = X[i] == 'F';
		return ump[key];
	}
	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int l_T = Solve(X, i, k - 1, true);
		int l_F = Solve(X, i, k - 1, false);
		int r_T = Solve(X, k + 1, j, true);
		int r_F = Solve(X, k + 1, j, false);
		if (X[k] == '|') {
			if (isTrue == true)
				ans += l_T * r_T + l_T * r_F + l_F * r_T;
			else
				ans += l_F * r_F;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += l_T * r_T;
			else
				ans += l_T * r_F + l_F * r_T + l_F * r_F;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += l_T * r_F + l_F * r_T;
			else
				ans += l_T * r_T + l_F * r_F;
		}
	}
	return ump[key] = ans;
}

•	Evaluate expression to true memoization using 3d array:
const int D = 1001;
int dp[2][D][D]; // i,j and istrue and false is changing 
int Solve(string X, int i, int j, bool isTrue) {
	if (i >= j) {
		if (isTrue)
			dp[1][i][j] = X[i] == 'T';
		else
			dp[0][i][j] = X[i] == 'F';
		return dp[isTrue][i][j];
	}
	if (dp[isTrue][i][j] != -1)
		return dp[isTrue][i][j];
	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int l_T = Solve(X, i, k - 1, true);
		int l_F = Solve(X, i, k - 1, false);
		int r_T = Solve(X, k + 1, j, true);
		int r_F = Solve(X, k + 1, j, false);
		if (X[k] == '|') {
			if (isTrue == true)
				ans += l_T * r_T + l_T * r_F + l_F * r_T;
			else
				ans += l_F * r_F;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += l_T * r_T;
			else
				ans += l_T * r_F + l_F * r_T + l_F * r_F;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += l_T * r_F + l_F * r_T;
			else
				ans += l_T * r_T + l_F * r_F;
		}
	}
	dp[isTrue][i][j] = ans;
	return ans;
}
int main() {
	string X; cin >> X;
	memset(dp[0], -1, sizeof(dp[0]));
	memset(dp[1], -1, sizeof(dp[1]));
	cout << Solve(X, 0, X.length() - 1, true) << endl;
	return 0;
}

•	Scramble string recursive: 
bool Solve(string X, string Y) {
	if (X.compare(Y) == 0)
		return true;
	if (X.length() <= 1)
		return false;
	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
**firstly it checks x 1st part to y end part then it checks x 1st part to y 1st part
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i), Y.substr(0, n - i))) || (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i), Y.substr(i)))) {
			flag = true; // change the  flag to true and break 
			break;
		}
	}
	return flag;
}
int main() {
	string X, Y; cin >> X >> Y;
	if (X.length() != Y.length())
		cout << "No\n";
	else
		Solve(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}

•	Scramble string top down:
unordered_map<string, int> ump;
bool Solve(string X, string Y) {
	string key = X + " " + Y;
	if (ump.find(key) != ump.end()) // if we did not found the and travesed upto end of the map 
		return ump[key];
	if (X.compare(Y) == 0) {
		ump[key] = true;
		return true;
	}
	if (X.length() <= 1) {
		ump[key] = false;
		return false;
	}

	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i), Y.substr(0, n - i))) ||
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i), Y.substr(i)))) {
			flag = true;
			break;
		}
	}
	return ump[key] = flag; // store in table for further reference 
}

•	Egg dropping problem recursive:
int Solve(int eggs, int floors) {
	if (eggs == 1)
		return floors;
	if (floors == 0 || floors == 1)
		return floors;
	int mn = INT_MAX;
//we take k as threshold floor, above this egg must break and below this egg doesnot break so we only calculate in between 0th floor to threshold floor
	for (int k = 1; k <= floors; k++) {
		int temp_ans = 1 + max(Solve(eggs - 1, k - 1), Solve(eggs, floors - k)); // once egg break means decrement both floor and egg and if it doesnt break then num of eggs remain same and floor become floor number - threshold floor
		mn = min(mn, temp_ans);
	}
	return mn;
}

•	Egg dropping problem top down:
const int D = 101;
int t[D][D];
int Solve(int eggs, int floors) {
	if (t[eggs][floors] != -1)
		return t[eggs][floors];
	if (eggs == 1 || floors == 0 || floors == 1) {
		t[eggs][floors] = floors;
		return floors;
	}
	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) {
		int temp_ans = 1 + max(Solve(eggs - 1, k - 1), Solve(eggs, floors - k));
		mn = min(mn, temp_ans);
	}
	return t[eggs][floors] = mn; // store in table for further reference 
}

•	Egg dropping problem memoization optimization:
const int D = 101;
int dp[D][D];
int Solve(int eggs, int floors) {
	if (dp[eggs][floors] != -1) // if value is already there in the table then return the value 
		return dp[eggs][floors];
	if (eggs == 1 || floors == 0 || floors == 1) { // base condition
		dp[eggs][floors] = floors;
		return floors;
	}
	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) {
		int top, bottom;
		if (dp[eggs - 1][k - 1] != -1) // break the temp in sub problemes 
			top = dp[eggs - 1][k - 1];
		else {
			top = Solve(eggs - 1, k - 1);
			dp[eggs - 1][k - 1] = top;
		}

		if (dp[eggs][floors - k] != -1)
			bottom = dp[eggs][floors - k];
		else {
			bottom = Solve(eggs, floors - k);
			dp[eggs][floors - k] = bottom;
		}
		int temp_ans = 1 + max(top, bottom);
		mn = min(mn, temp_ans);
	}
	return dp[eggs][floors] = mn;
}

// Some Extra Qs: 
/*// Climbing Stairs
int climbStairs(int n){
    int dp[n + 2];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}*/
/*// Frog Jump with k Distances
int frogJump(int n, int k){
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0)
                dp[i] += dp[i - j];
        }
    }
    return dp[n];
}*/
/*// Maximum sum of non-adjacent elements
int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    if (n == 0)
        return arr[0];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        int pick = arr[i] + dp[i - 2];
        int nonPick = dp[i - 1];
        dp[i] = max(pick, nonPick);
    }
    return dp[n - 1];
}*/
/*// Longest Increasing Subsequence
int lis(int arr[], int n){
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++){
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    return *max_element(lis, lis + n);
}*/
/*// Maximum Sum Increasing Subsequence
int maxSumIS(int arr[], int n)
{
    int i, j, max = 0;
    int msis[n];
    for (i = 0; i < n; i++)
        msis[i] = arr[i];
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];
    for (i = 0; i < n; i++)
        if (max < msis[i])
            max = msis[i];

    return max;
}*/
/*// Word Break Problem
bool helper(string s, vector<string> &w){
    if (s.size() == 0) return dp[s.size()] = true;
    if (dp[s.size()] != -1) return dp[s.size()];
    bool check = false;
    for (int idx = 0; idx < w.size(); idx++){
        if (s.substr(0, w[idx].size()) == w[idx]){
            if (helper(s.substr(w[idx].size()), w)){
                check = true;
                break;
            }
        }
    }
    return dp[s.size()] = check;
}
bool wordBreak(string s, vector<string> &W){
    if (W.size() == 0) return false;
    memset(dp, -1, sizeof dp);
    return helper(s, W);
}*/
