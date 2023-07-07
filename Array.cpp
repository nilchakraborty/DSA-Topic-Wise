/*👉🏻 to reverse an array: reverse(arr,arr+n);
👉🏻 Maximum and minimum of an array => maxi=max_element(arr,arr+n);mini=min_element(arr,arr+n);
👉🏻 Move all negative numbers to beginning => // it takes user defined function that returns true before those for which the predicate returns false
==> stable_partition(arr.begin(), arr.end(), [](int num) {return num < 0;});
👉🏻 if u take int arr[] then in function take (arr,arr+n) , if u take vector<int> arr then in function take (arr.begin(),arr.end());
👉🏻 vector<int> v; we just push it into the vector using the v.pb, vectors are dynamic in nature, havent declared any size or pushed any element its size is zero.So no element exists right now.
👉🏻 vector<int> v(N); if you add more than N elements then you can anytime use the push_back() function to add elements
👉🏻 vector<int> v[N]; It creates a static array of N vectors of the first type i.e.v[0] is now a whole new and different vector than v[1] which is totally different than v[2] and so on.If you want to push a value into the 1st vector that is v[0], you will do it by v[0].push _ back(val).To access that element you will call it by v[0][0] .
👉🏻 all(x) = > sort(all(vec)) instead of sort(vec.begin(), vec.end())
👉🏻 merge() = > to merge 2 array : merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin());
👉🏻 smallest element from group of int : min({a, b, c, d});
👉🏻 rotate() => Rotates the order of the elements in the range [first, last) == > 1 2 3 4 5 6 7 8 9
==> clockwise -> right rotation, anticlockwise -> left rotation.
==> for anti clockwise rotation -> std::rotate(myvector.begin(), myvector.begin() + 3, myvector.end()); // 4 5 6 7 8 9 1 2 3
==> for clockwise rotation -> std::rotate(myvector.begin(), myvector.end() - 3, myvector.end()); // 7 8 9 1 2 3 4 5 6
👉🏻 count(arr, n, what thing you want to count) inbuilt func its count and say
👉🏻 count_if() : function returns the number of elements in a range that satisfy the condition count_if(v.begin(), v.end(), isEven);
👉🏻 A XOR(^) A = 0, for ex : ((2 ^ 2) ^ (1 ^ 1) ^ (4 ^ 4) ^ (5)) => (0 ^ 0 ^ 0 ^ 5) => 5
👉🏻 set<int> => if same number added more than one time in set it will add only one
👉🏻 sum of whole arr: accumulate(begin,end,0);
👉🏻 iota : int st = 100;
iota(numbers, numbers + 10, st); => 100 101 102 103 104 105 106 107 108 109
👉🏻 intersection of 2 array :  a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
[set_1.erase(set_1.begin(), set_1.end(), set_2.begin(), set_2.end(), set_1.begin(), set_1.end());]
👉🏻 mp[arr[i]].push_back(i) adds the value i to the end of the vector associated with the key arr[i], while mp[arr[i]]++ increments the value associated with the key arr[i] by 1.
=>vector<int> arr = {1, 2, 1, 3, 2, 4, 2, 5};
  map<int, vector<int>> mp;
==>Using mp[arr[i]].push_back(i):
Key: 1, Value: 0 2
Key: 2, Value: 1 4 6
Key: 3, Value: 3
Key: 4, Value: 5
Key: 5, Value: 7
==>Using mp[arr[i]]++:
Key: 1, Value: 2
Key: 2, Value: 3
Key: 3, Value: 1
Key: 4, Value: 1
Key: 5, Value: 1
👉🏻 first and second are used to access the key and value of each key-value pair (also called an element) in the map. first refers to the key, and second refers to the value. we're using the -> operator to access the first and second
=>begin and end are used to access the first and last elements in the map
=> vector<pair<pair<int, int>, pair<int, int>>> v = {{1, 2}, {3, 4}};
cout << p.first.first << "," << p.first.second << "," << p.second.first << "," << p.second.second << endl; ----> 1,2,3,4
👉🏻 i++: post-increment operator. It increments the value of i after the current expression is evaluated, and it returns the original value of i. For example, if i has the value of 3, then i++ would return 3 and then set i to 4.
=>On the other hand, the ++i operator is known as the pre-increment operator. It increments the value of i before the current expression is evaluated, and it returns the new value of i. For example, if i has the value of 3, then ++i
👉🏻 auto it and int i = 0 are used for different purposes in C++. auto it is used to declare an iterator variable without explicitly specifying its type to traverse a string and an array, while int i = 0 is used to declare and initialize an integer variable with a specific value.
👉🏻 nth_element(): to find nth position in unsorted array => nth_element(nums.begin(), nums.begin() + k-1, nums.end());*/

/*//factorial of a large number
// time complexity: O(n) | space complexity: O(1)
#define ull unsigned long long
ull factorial(int N){
    ull f = 1;
    for (ull i = 2; i <= N; i++)
        f *= i;
    return f;
}*/
/*//Find Second Largest Element in Array
time complexity: O(n)
int findSecondLargest_On(vector<int>& arr, int n) {
    int largest = arr[0];
    int secondLargest = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
using stl=>
int findSecondLargest_NthElement(vector<int>& arr) {
    nth_element(arr.begin(), arr.begin() + 1, arr.end(), greater<int>());
    return arr[1];
}*/
/*//Leaders in an array
//time complexity: O(n) | space complexity: O(n)
vector<int> printLeaders(int arr[], int n) {
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--){
        if (arr[i] > maxi) {
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);
    }
    return ans;
}*/
/*//left rotation by one element
time complexity: O(n)
void leftRotateByOne(vector<int>& arr, int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}
using stl=>
// rotate() => Rotates the order of the elements in the range [first, last) == > 1 2 3 4 5 6 7 8 9
// clockwise -> right rotation, anticlockwise -> left rotation.
// for anti clockwise rotation -> std::rotate(myvector.begin(), myvector.begin() + 3, myvector.end()); // 4 5 6 7 8 9 1 2 3
// for clockwise rotation -> std::rotate(myvector.begin(), myvector.end() - 3, myvector.end()); // 7 8 9 1 2 3 4 5 6
void leftRotateByOne(vector<int>& arr, int n) {
    rotate(arr.begin(), arr.begin() + 1, arr.end());
}*/
/*//left rotation by d elements
brute force:
time complexity: O(d)+O(n-d)+O(d)=O(n+d) | space complexity: O(d)
void leftRotateByD(vector<int>& arr, int n, int d) {
    d=d%n;
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}
optimised:
time complexity: O(2n) | space complexity: O(1)
void leftRotateByD(vector<int>& arr, int n, int d) {
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}
using stl=>
void leftRotateByD(vector<int>& arr, int n, int d) {
    rotate(arr.begin(), arr.begin() + d, arr.end());
}*/
/*//next_permutation
void nextPermutation(vector<int>& arr){
    next_permutation(arr.begin(),arr.end());
}*/
/*//sort an array of 0s, 1s and 2s
//time complexity: O(n) | space complexity: O(1)
void sort012(vector<int>& arr, int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}*/
/*//Rearrange Array Elements by Sign (same no of +ve and -ve)
// time complexity: O(n) | space complexity: O(n)
vector<int> RearrangebySign(vector<int>A){
  int n = A.size();
  vector<int> ans(n,0);
// positive elements start from 0 and negative from 1.
  int posIndex = 0, negIndex = 1;
  for(int i = 0;i<n;i++){
// Fill negative elements in odd indices and inc by 2.
      if(A[i]<0){
          ans[negIndex] = A[i];
          negIndex+=2;
      }
// Fill positive elements in even indices and inc by 2.
      else{
          ans[posIndex] = A[i];
          posIndex+=2;
      }
  }
  return ans; 
}
//Rearrange Array Elements by Sign (different no of +ve and -ve)
// time complexity: O(2*n) | space complexity: O(n)
vector<int> RearrangebySign(vector<int>A, int n){
  vector<int> pos;
  vector<int> neg;
  for(int i=0;i<n;i++){
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
// If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
// First, fill array alternatively till the point where +ve & -ve ar equal in number.
    for(int i=0;i<pos.size();i++){
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
// Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        A[index] = neg[i];
        index++;
    }
  }
// If negatives are lesser than the positives.
  else{
// First, fill array alternatively till the point where +ve & -ve ar equal in number.
      for(int i=0;i<neg.size();i++){
        A[2*i] = pos[i];
        A[2*i+1] = neg[i];
    }
// Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        A[index] = pos[i];
        index++;
    }
  }
  return A;
}*/
/*//Kadane's Algorithm
//time complexity: O(n) | space complexity: O(1)
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}*/
/*//Maximum Product Subarray
//time complexity: O(n) | space complexity: O(1)
int maxProductSubArray(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        result = max(result,prod1);
    }
    return result;
}*/
/*//stock buy and sell
//time complexity: O(n) | space complexity: O(1)
int maximumProfit(vector<int> &Arr){
    int maxProfit = 0;
    int mini = Arr[0];
    for(int i=1;i<Arr.size();i++){
        int curProfit = Arr[i] - mini;
        maxProfit = max(maxProfit,curProfit);
        mini = min(mini,Arr[i]);
        }
    return maxProfit;
}*/
/*//Maximum profit by buying and selling a share at most twice
#include <iostream>
using namespace std;
int main(){
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = 7;
    int profit = 0;
    for (int i = 0; i < n; i++){
        int sub = price[i] - price[i - 1];
        if (sub > 0)
            profit += sub;
    }
    cout << "Maximum profit " << profit; 
    return 0;
}*/
/*//Set Matrix Zeros
// time complexity: O(n*m) | space complexity: O(1)
// x axis menas rows and y axis means columns
void setZeroes(vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < n; i++){
// if first column has zero then col0 = 0
        if (matrix[i][0] == 0)  col0 = 0;
// if any element is zero then make first element of that row and column zero
        for (int j = 1; j < m; j++){
            if (matrix[i][j] == 0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
// start from last row and column and make zero
    for (int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 1; j--){
// if first element of row or column is zero then make that element zero
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
// if col0 is zero then make first column zero
        if (col0 == 0)  matrix[i][0] = 0;
    }
}*/
/*//Rotate Matrix/Image by 90 Degrees
// time complexity: O(n/2 * n/2)+ O(n * n/2) [n/2 because it works on half of array size] | space complexity: O(1)
// basic rule to solve this: "swap then reverse"
void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}*/
/*//spiral traversal of matrix
// time complexity: O(n*m) | space complexity: O(n)
vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    vector<int> ans;
    while (top <= bottom && left <= right) {
// in a spiral traversal when we go through top left to right then top row is done so we increment top
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;
// in a spiral traversal when we go through right top to bottom then right column is done so we decrement right
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;
// in a spiral traversal when we go through bottom right to left then bottom row is done so we decrement bottom
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
// in a spiral traversal when we go through left bottom to top then left column is done so we increment left
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}*/
/*//Merge Interval (overlapping intervals)
// time complexity: O(n) + O(nlogn) | space complexity: O(1)
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}*/
/*//Merge two sorted arrays
// time complexity: O(n+m) | space complexity: O(n+m)
void merge(vector<int>& a1, int m, vector<int>& a2, int n) {
        vector<int> a3(m+n);
        merge(a1.begin(), a1.end(), a2.begin(), a2.end(), a3.begin());
        return a3;
}
//Merge two sorted arrays without extra space
void mergeWithoutExtraSpace(vector<int>& arr1, int n, vector<int>& arr2, int m) {
    for (int i = m - 1; i >= 0; i--) {
        int last = arr1[n - 1];
        int j;
        // Shift all elements in arr1 greater than arr2[i] to the right
        for (j = n - 2; j >= 0 && arr1[j] > arr2[i]; j--)
            arr1[j + 1] = arr1[j];

        // If there was a smaller element in arr1, place arr2[i] at its position
        if (j != n - 2 || last > arr2[i]) {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
}*/
/*//Pascal Triangle Problem
//variation 1: we are given the row number r and the column number c, and we need to find out the element at position
// time complexity: O(c) | space complexity: O(1)
int nCr(int n, int r) {
    long long res = 1;
    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}
//variation 2: Given the row number n. Print the n-th row of Pascal’s triangle
// time complexity: O(n) | space complexity: O(1)
void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " ";
    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}
//variation 3: print pascal triangle
// time complexity: O(n) | space complexity: O(1)
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element
//calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;
//store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}*/
/*//Repeat and Missing Number
// time complexity: O(n) | space complexity: O(1)
vector<int>missing_repeated_number(const vector<int> &A) {
    long long int len = A.size();
    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;    
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }    
    missingNumber = (S + P/S)/2;
    repeating = missingNumber - S;
    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
}*/
/*//2 sum problem
//time complexity: O(n)+O(nlogn) | space complexity: O(1)
string twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()){
            // return {mpp[moreNeeded], i}; // if pair found
            return "YES";
        }
        mpp[num]=i;
    }
    // return {-1, -1}; // if no pair found
    return "NO";
}*/
/*//3 sum problem
//time complexity: O(n^2) | space complexity: O(3*k)
vector<vector<int>> threeSum(vector<int>& num) {
    vector<vector<int>> res; 
    sort(num.begin(), num.end());
    for (int i = 0; i < (int)(num.size())-2; i++) {
        if (i == 0 || (i > 0 && num[i] != num[i-1])) {
            int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
            while (lo < hi) {
                if (num[lo] + num[hi] == sum) {
                    vector<int> temp; 
                    temp.push_back(num[i]); 
                    temp.push_back(num[lo]); 
                    temp.push_back(num[hi]); 
                    res.push_back(temp);
                    while (lo < hi && num[lo] == num[lo+1]) lo++;
                    while (lo < hi && num[hi] == num[hi-1]) hi--;
                    lo++; hi--;
                } 
                else if (num[lo] + num[hi] < sum) lo++;
                else hi--;
           }
        }
    }
    return res;
}*/
/*//4 sum problem
//time complexity: O(n^3) | space complexity: O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }
    return ans;
}*/
/*//majority element ( >n/2)
//using Boyer Moore Voting Algorithm === time complexity: O(n) | space complexity: O(1)
int majorityElement(vector<int> v) {
    int n = v.size();
    int cnt = 0;
    int el;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }
    if (cnt1 > (n / 2)) return el;
    return -1;
}
// short form =>
int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate;
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}*/
/*//majority element ( >n/3)
//time complexity: O(n) | space complexity: O(1)
vector<int> majorityElement(vector<int>& a) {
    int y=-1,z=-1,cny=0,cnz=0;
    for (const auto & x: a) {
        if(x==y)    cny++; //if x is equal to y then increment count of y
        else if(x==z)   cnz++;//if x is equal to z then increment count of z
        else if(!cny)   y=x,cny=1;//if y is not present then make y=x and increment count of y
        else if(!cnz)   z=x,cnz=1;//if z is not present then make z=x and increment count of z
        else    cny--,cnz--;//if x is not equal to y and z then decrement count of y and z
    }
    cny=cnz=0;//reset count of y and z
    for (const auto & x: a) {
        if(x==y)    cny++;//increment count of y
        else if(x==z)   cnz++;//increment count of z
    }
    vector<int> r;
	if (cny > size(a)/3) r.push_back(y);//if count of y is greater than n/3 then push y in result
	if (cnz > size(a)/3) r.push_back(z);//if count of z is greater than n/3 then push z in result
	return r;
}*/
/*//Longest Consecutive Subsequence
int findLongestConseqSubseq(int arr[], int n){
    unordered_set<int> S;
    int ans = 0;
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
    for (int i = 0; i < n; i++) {
        if (S.find(arr[i] - 1) != S.end()) {
            continue;
        }
        else {
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}*/
/*//Find if there is a subarray with 0 sum
// time complexity: O(n) | space complexity: O(n)
bool subArrayExists(int arr[], int N){
    unordered_set<int> sumSet;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
        sumSet.insert(sum);
    }
    return false;
}*/
/*//Longest Subarray with sum K
//time complexity: O(n) | space complexity: O(1)
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size();
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
// if sum > k, reduce the subarray from left until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
// if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
// Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }
    return maxLen;
}*/
/*//Count pairs with given sum
// time complexity: O(n) | space complexity: O(n)
int getPairsCount(int arr[], int n, int k){
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(k - arr[i]) != m.end()) {
            count += m[k - arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}*/
/*//Count the number of subarrays with given xor K
// time complexity: O(n) | space complexity: O(n)
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size();
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
// prefix XOR till index i:
        xr = xr ^ a[i];
//By formula: x = xr^k:
        int x = xr ^ k;
// add the occurrence of xr^k to the count:
        cnt += mpp[x];
// Insert the prefix xor till index i into the map:
        mpp[xr]++;
    }
    return cnt;
}*/
/*//Trapping Rain Water
int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}*/
/*//Chocolate Distribution Problem
int findMinDiff(int arr[], int n, int m){
    if (m == 0 || n == 0)
        return 0;
    sort(arr, arr + n);
    if (n < m)
        return -1;
    int min_diff = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++){
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}*/
//Sliding Window & Two Pointer Combined Problems
/*//Max Consecutive Ones
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
int longestOnes(vector<int> &A, int K){
    int max_count = 0, zero_count = 0;
    for (int left = 0, right = 0; right < nums.size(); right++){
        if (nums[right] == 0)
            zero_count++;
        if (zero_count > k){
            if (nums[left++] == 0)
                zero_count--;
        }
        max_count = max(max_count, right - left + 1);
    }
    return max_count;
}*/
/*//Binary subarray with sum
int atMost(vector<int>& nums, int goal){
    int window_start=0, window_end=0, ans=0,count=0;
    if (goal < 0)
        return 0;
    for(window_end=0; window_end<nums.size() ;window_end++){
        count+=nums[window_end];
        while(count>goal){
            count-=nums[window_start];
            window_start++;
        }
        ans+=window_end-window_start+1;
    }
    return ans;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums,goal)-atMost(nums,goal-1);
}*/
/*//Maximum Points You Can Obtain from Cards
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size(),lsum=0,rsum=0;
    for(int i=0;i<k;i++)
        lsum+=cardPoints[i];
    int maxi=lsum;
    for(int i=0;i<k;i++){
        rsum+=cardPoints[n-i-1];
        lsum-=cardPoints[k-1-i];
        maxi=max(maxi,lsum+rsum);
    }
    return maxi;
}*/
/*//Subarray with k different integers
int subArray(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> map;
    int count = 0, start = 0, end = 0;
    while (end < n) {
        map[nums[end]]++;
        while (map.size() > k) {
            map[nums[start]]--;
            if (map[nums[start]] == 0) {
                map.erase(nums[start]);
            }
            start++;
        }
        count += end - start + 1;
        end++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subArray(nums, k) - subArray(nums, k - 1);
}*/
