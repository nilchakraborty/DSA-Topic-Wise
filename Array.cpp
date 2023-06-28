/*//reverse the array
void reverseArray(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
}
// using STL
reverse(arr,arr+n);*/
/*//Maximum and minimum of an array
maxi=max_element(arr,arr+n);
mini=min_element(arr,arr+n);*/
/*//K’th Smallest/Largest Element in Unsorted Array
int kthSmallest(int arr[],int n,int k){
    sort(arr,arr+n);
    return arr[k-1];
}
// using STL
nth_element(arr,arr+k-1,arr+n);
return arr[k-1];*/
/*//Sort an array of 0s, 1s and 2svoid sort012(vector<int>& arr, int n) {
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
/*//Move all negative numbers to beginning
// it takes user defined function that returns true before those for which the predicate returns false
stable_partition(arr.begin(), arr.end(), [](int num) {return num < 0;});*/
/*//Union and Intersection of two sorted arrays
void printUnion(int arr1[], int arr2[], int m, int n){
    int i = 0, j = 0;
    while (i < m && j < n){
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";
        else if (arr2[j] < arr1[i])
            cout << arr2[j++] << " ";
        else{
            cout << arr2[j++] << " ";
            i++;
        }
    }
    while (i < m)
        cout << arr1[i++] << " ";
    while (j < n)
        cout << arr2[j++] << " ";
}
//For intersection
void printIntersection(int arr1[], int arr2[], int m, int n){
    int i = 0, j = 0;
    while (i < m && j < n){
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else{
            cout << arr2[j++] << " ";
        i++;
        j++;
        }
    }
}*/
/*//cyclically rotate an array by one
using stl=>
// rotate() => Rotates the order of the elements in the range [first, last) == > 1 2 3 4 5 6 7 8 9
// clockwise -> right rotation, anticlockwise -> left rotation.
// for anti clockwise rotation -> std::rotate(myvector.begin(), myvector.begin() + 3, myvector.end()); // 4 5 6 7 8 9 1 2 3
// for clockwise rotation -> std::rotate(myvector.begin(), myvector.end() - 3, myvector.end()); // 7 8 9 1 2 3 4 5 6
void RotateByOne(vector<int>& arr) {
    rotate(arr.begin(), arr.end() - 1, arr.end());
}*/
/*//Largest Sum Contiguous Subarray
//Kadane's Algorithm
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
/*//Minimize the maximum difference between the heights
int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int minHeight = arr[0] + k;
    int maxHeight = arr[n - 1] - k;
    for (int i = 0; i < n - 1; i++) {
        int currentHeight = arr[i];
        int nextHeight = arr[i + 1];
        int lowerBound = max(minHeight, currentHeight + k);
        int upperBound = min(maxHeight, nextHeight - k);
        if (lowerBound > upperBound) continue;
        ans = min(ans, upperBound - lowerBound);
    }
    return ans;
}*/
/*//Merge two sorted arrays (without extra space)
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
/*//Merge Interval (overlapping intervals)
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
/*//next_permutation
void nextPermutation(vector<int>& arr){
    next_permutation(arr.begin(),arr.end());
}*/
/*//Count Inversions
int numberOfInversions(vector<int>&a, int n) {
    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}*/
/*//Stock Buy Sell to Maximize Profit
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
/*//Rearrange array in alternating positive & negative items
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
/*//factorial of a large number
// time complexity: O(n) | space complexity: O(1)
#define ull unsigned long long
ull factorial(int N){
    ull f = 1;
    for (ull i = 2; i <= N; i++)
        f *= i;
    return f;
}*/
/*//Maximum Product Subarray
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
/*//Given an array of size n and a number k, find all elements that appear more than n/k times
// time complexity: O(n) | space complexity: O(n)
vector<int> find_elements(vector<int>& arr, int K){
    int N = arr.size();
    unordered_map<int, int> freq_map;
    for (int i = 0; i < N; i++) {
        if (freq_map.find(arr[i]) == freq_map.end()) {
            freq_map[arr[i]] = 1;
        }
        else {
            freq_map[arr[i]]++;
        }
    }
    vector<int> req_elements;
    for (auto& p : freq_map) {
        if (p.second > (N / K)) {
            req_elements.push_back(p.first);
        }
    }
    return req_elements;
}*/
/*//Maximum profit by buying and selling a share at most twice
#include <iostream>
using namespace std;

int main()
{
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = 7;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        int sub = price[i] - price[i - 1];
        if (sub > 0)
            profit += sub;
    }
    cout << "Maximum profit " << profit; 
    return 0;
}*/
/*//Find whether an array is a subset of another array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    unordered_set<int> s;
    for (int i = 0; i < m; i++)
    {
        s.insert(arr1[i]);
    }
    int p = s.size();
    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }
    if (s.size() == p)
    {
        cout << "arr2[] is subset of arr1[]" << endl;
    }
    else
    {
        cout << "arr2[] is not a subset of arr1[]" << endl;
    }

    return 0;
}*/
/*//Find the triplet that sum to a given value
#include <bits/stdc++.h>
using namespace std;
bool find3Numbers(int arr[], int n, int sum)
{   
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << "triplet is" << arr[i] << "," << arr[j] << "," << arr[k];
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int n = sizeof(arr) / sizeof(arr[0]);
    find3Numbers(arr, n, sum);
    return 0;
}*/
/*//Trapping Rain Water
#include <bits/stdc++.h>
using namespace std;
int maxWater(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        int right = arr[i];
        for (int j = i + 1; j < n; j++)

            right = max(right, arr[j]);
        res = res + (min(left, right) - arr[i]);
    }
    return res;
}
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<< maxWater(arr, n);
    return 0;
}*/
/*//Chocolate Distribution Problem
#include <bits/stdc++.h>
using namespace std;
int findMinDiff(int arr[], int n, int m)
{
    if (m == 0 || n == 0)
        return 0;
    sort(arr, arr + n);
    if (n < m)
        return -1;
    int min_diff = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is " << findMinDiff(arr, n, m);
    return 0;
}*/
/*//Smallest Subarray with sum greater than a given value
#include <bits/stdc++.h>
using namespace std;
int smallestSubarraywithSum(int arr[], int n, int x)
{
    int sum = 0, minLength = n + 1, start = 0, end = 0;
    while (end < n)
    {
        while (sum <= x && end < n)
        {
            sum += arr[end++];
        }
        while (sum > x && start < n)
        {
            if (end - start < minLength)
            {
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;
    int minLength = smallestSubarraywithSum(arr, n, x);
    if (minLength == n + 1)
    {
        cout << "No such subarray exists" << endl;
    }
    else
    {
        cout << "Smallest length Subarray is: " << minLength << endl;
    }
    return 0;
}*/
/*//Three way partitioning of an array
void threeWayPartition(int arr[], int n, int lowVal, int highVal){
    int start = 0, end = n - 1;
    for (int i = 0; i <= end;){
        if (arr[i] < lowVal)
            swap(arr[i++], arr[start++]);
    else if (arr[i] > highVal)
        swap(arr[i], arr[end--]);
    else
        i++;
}*/
/*//Minimum no. of operations required to make an array palindrome
int minOps(int arr[], int n){
    int ans = 0;
    for (int i = 0, j = n - 1; i <= j;){
        if (arr[i] == arr[j]){
            i++;
            j--;
        }
        else if (arr[i] > arr[j]){
            i--;
            arr[j] += arr[j + 1];
            ans++;
        }
        else{
            i++;
            arr[i] += arr[i - 1];
            ans++;
        }
    }
    return ans;
}*/
/*Repeat and Missing Number
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
/*Count Subarrays with Xor as K
int Solution::solve(vector<int> &A,int B){
    map<int,int> freq;
    int cnt=0;
    int xorr=0;
    for(auto it:A){
        xorr^=it;
        if(xorr==B) cnt++;
        if(freq.find(xorr^B)!=freq.end())
            cnt+=freq[xorr^B];
        freq[xorr]+=1;
    }
    return cnt;
}*/
