/*//Activity Selection Problem
#include <bits/stdc++.h>
using namespace std;
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
    cout << "Following activities are selected " << endl;
    i = 0;
    cout << " " << i;
    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            cout << " " << j;
            i = j;
        }
    }
}
int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}*/
/*//Fractional Knapsack Problem
// Time Complexity: O(N * logN)
#include <bits/stdc++.h>
using namespace std;
struct Item{
    int value, weight;
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};
bool cmp(struct Item a, struct Item b){
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int n){
    sort(arr, arr + n, cmp);
    int curWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++){
        if (curWeight + arr[i].weight <= W){
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else{
            int remain = W - curWeight;
            finalValue += arr[i].value *((double)remain / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}
int main(){
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = "<< fractionalKnapsack(W, arr, n);
    return 0;
}*/
/*//Minimum number of Coins
#include<bits/stdc++.h>
using namespace std;
int main() {
  int V = 49;
  vector < int > ans;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  for (int i = n - 1; i >= 0; i--) {
    while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
    }
  }
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}*/
/*//N meetings in one room
#include <bits/stdc++.h>
using namespace std;
struct meeting {
   int start;
   int end;
   int pos;
};
class Solution {
   public:
      bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
      }
   void maxMeetings(int s[], int e[], int n) {
      struct meeting meet[n];
      for (int i = 0; i < n; i++) {
         meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
      }
      sort(meet, meet + n, comparator);
      vector < int > answer;
      int limit = meet[0].end;
      answer.push_back(meet[0].pos);
      for (int i = 1; i < n; i++) {
         if (meet[i].start > limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
         }
      }
      cout<<"The order in which the meetings will be performed is "<<endl;
      for (int i = 0; i < answer.size(); i++) {
         cout << answer[i] << " ";
      }
   }
};
int main() {
   Solution obj;
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   obj.maxMeetings(start, end, n);
   return 0;
}*/
/*//Minimum number of platforms required for a railway
#include<bits/stdc++.h>
using namespace std;
int countPlatforms(int n,int arr[],int dep[]){
    sort(arr,arr+n);
    sort(dep,dep+n);
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]) //one more platform needed{
            count++;
            i++;
        }
        else //one platform can be reduced{
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
}
int main(){
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
}*/
/*//Job Sequencing Problem
#include<bits/stdc++.h>
using namespace std;
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   pair < int, int > JobScheduling(Job arr[], int n) {
      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }
      int slot[maxi + 1];
      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;
      int countJobs = 0, jobProfit = 0;
      for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }
      return make_pair(countJobs, jobProfit);
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};
   Solution ob;
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;
   return 0;
}*/
/*//Insert Interval
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int n = intervals.size();
    int i = 0;
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i++]);
    }
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while (i < n) {
        res.push_back(intervals[i++]);
    }
    return res;
}*/
/*//Merge Interval
#include <bits/stdc++.h>
using namespace std;
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
}
int main(){
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}*/
/*//Non-overlapping Intervals
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return 0;     
    sort(intervals.begin(), intervals.end(), [](const auto& l, const auto& r) { 
        return l[1] < r[1]; 
    });     
    int prevIndex = 0;
    int eraseCount = 0;
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[prevIndex][1] > intervals[i][0]) ++eraseCount;
        else prevIndex = i;
    }
    return eraseCount;
}*/
/*// Minimum Cost to cut a board into squares
#include <bits/stdc++.h>
using namespace std;
int minimumCostOfBreaking(int X[], int Y[], int m, int n){
    int res = 0;
    sort(X, X + m, greater<int>());
    sort(Y, Y + n, greater<int>());
    int hzntl = 1, vert = 1;
    int i = 0, j = 0;
    while (i < m && j < n){
        if (X[i] > Y[j]){
            res += X[i] * vert;
            hzntl++;
            i++;
        }
        else{
            res += Y[j] * hzntl;
            vert++;
            j++;
        }
    }
    int total = 0;
    while (i < m)
        total += X[i++];
    res += total * vert;
    total = 0;
    while (j < n)
        total += Y[j++];
    res += total * hzntl;
    return res;
}
int main(){
    int m = 6, n = 4;
    int X[m - 1] = {2, 1, 3, 1, 4};
    int Y[n - 1] = {4, 1, 2};
    cout << minimumCostOfBreaking(X, Y, m - 1, n - 1);
    return 0;
}*/
/*// Check if it is possible to survive on Island
#include <bits/stdc++.h>
using namespace std;
void survival(int S, int N, int M){}
    if (((N * 6) < (M * 7) && S > 6) || M > N)
        cout << "No\n";
    else{
        int days = (M * S) / N;
        if (((M * S) % N) != 0)
            days++;
        cout << "Yes " << days << endl;
    }
}
int main(){
    int S = 10, N = 16, M = 2;
    survival(S, N, M);
    return 0;
}*/
