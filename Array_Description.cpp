// Time limit: 1.00 s Memory limit: 512 MB
// You know that an array has n integers between 1 and m, and the absolute difference between two adjacent values is at most 1.

// Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.

// Input

// The first input line has two integers n and m: the array size and the upper bound for each value.

// The next line has n integers x1,x2,…,xn: the contents of the array. Value 0 denotes an unknown value.

// Output

// Print one integer: the number of arrays modulo 109+7.

// Constraints
// 1≤n≤105
// 1≤m≤100
// 0≤xi≤m
// Example

// Input:
// 3 5
// 2 0 2

// Output:
// 3

// Explanation: The arrays [2,1,2], [2,2,2] and [2,3,2] match the description.

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int cnt2 = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (a[k] - a[i] <= m && a[k] - a[i] >= 1) cnt2++;
                if (a[k] - a[j] <= m && a[k] - a[j] >= 1) cnt2++;
            }
            if (cnt2 == n - 2) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}