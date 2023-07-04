/*👉🏻 When you see the word "maximum" or "minimum" in a problem statement, 
it's often a sign that you'll need to use some sort of optimization strategy and that can be solved using binary search.
👉🏻 using STL=> binary_search(first,last,val); it return true if present.
👉🏻 common template ---> 
int search(vector<int>& nums, int target) {
	int start= 0, end= nums.size()-1;
	while (start <= end){
		int mid = start + (end-start)/2;
		if (target==nums[mid])	return mid;
		else if (target<nums[mid])	end= mid-1;
		else 	start= mid+1;
	}
return -1; 
}
👉🏻 equal_range is used to find the sub - range within a given range (first, last)[equal_range(v.begin(), v.end(), target)]
vector<int> v = {1, 2, 3, 4, 5};
	auto it = lower_bound(v.begin(), v.end(), 3); =>2 (first element that is not less than a specified value)
    auto it = upper_bound(v.begin(), v.end(), 3); =>3 (first element in the range that is greater than the specified value)
👉🏻 suppose arr = {1, 2, 3, 3, 3, 4, 5},x = 3; 
=> to find first occurance of x => distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
=> to find last occurance of x => distance(arr.begin(), upper_bound(arr.begin(), arr.end(), x)-1);
👉🏻 floor(2.3)=2,ceil(2.3)=3*/

/*//Search Insert Position
int searchInsert(vector<int>& arr, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}*/
/*//Floor and Ceil in Sorted Array
int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] <= x) {
			ans = arr[mid];
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}
int findCeil(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] >= x) {
			ans = arr[mid];
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}*/
/*//Count Occurrences in Sorted Array
int countOccurrences(const vector<int>& nums, int target) {
    return distance(lower_bound(nums.begin(), nums.end(), target), upper_bound(nums.begin(), nums.end(), target));
}*/
/*//Search in Rotated Sorted Array
int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) return mid;
        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}*/
/*//Minimum in Rotated Sorted Array
int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);
            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:
            // keep the minimum:
            ans = min(ans, arr[mid]);
            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}*/
/*//Peak Element in Array
int findPeak(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1]) {
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }
    return start;
}*/
/*//Square root of a number using log
//time complexity: O(log2log2N)
double squareRoot(double n){
    return pow(2, 0.5*log2(n));
}*/
/*//Nth Root of a Number using Binary Search
//time complexity: N*log(M*10^d)
double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}
void getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-7; 
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    cout <<n<<"th root of "<<m<<" is "<<low<<endl;
}
*/
/*//Koko Eating Bananas
int minEatingSpeed(vector<int>& A, int h) {
    int left = 1, right = 1e9;
    while (left < right) {
        int m = (left + right) / 2;
        int sum = 0;
        for (int i : A)
            sum += ceil(static_cast<double>(i) / m);
        if (sum > h)
            left = m + 1;
        else
            right = m;
    }
    return left;
}*/
/*//Minimum days to make M bouquets
// time complexity: O(Nlog(max(A[i])))
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size(), l = 1, h = 1e9;
    if (((long long int)m % 1000000007) * ((long long int)k % 1000000007) > n)
        return -1;
    while (l < h) {
        int mid = l + (h - l) / 2;
        int flower = 0;
        int bouquets = 0;
        for (int i = 0; i < n; ++i) {
            if (bloomDay[i] > mid) {
                flower = 0;
            } 
            else if (++flower >= k) {
                bouquets++;
                flower = 0;
            }
        }
        if (bouquets < m)
            l = mid + 1;
        else
            h = mid;
    } 
    return l;
}*/
/*//Find the smallest Divisor Given a Threshold
int sumByD(vector<int> arr, int div) {
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}
int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size();
    if (n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}*/
/*//Capacity to Ship Packages within D Days
// time complexity: O(Nlog(sum-max+1))
int findDays(vector<int> weights, int cap) {
    int days = 1, load = 0;
    for (int i = 0; i < weights.size(); ++i) {
        if (weights[i] + load > cap) {
            days += 1;
            load = weights[i];
        } else {
            load += weights[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> weights, int d) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= d) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}*/
/*//Aggressive cows
// time complexity: O(Nlog(max-min))
bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int cntCows = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}*/
/*//Book Allocation or Allocate Minimum Number of Pages from N books to M students
int countStudents(vector<int>& arr, int pages) {
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } else {
            students += 1;
            pagesStudent = arr[i];
        }
    }
    return students;
}
int findPages(vector<int>& arr, int n, int m) {
    if (m > n)
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}*/
/*//Median of Two Sorted Arrays of different sizes
// time complexity: O(log(min(n,m)))
float median(int num 1[],int num2[],int m,int n) {
    if(m>n)
        return median(nums2,nums1,n,m);//ensuring that binary search happens on minimum size array  
    int low=0,high=m,medianPos=((m+n)+1)/2;
    while(low<=high) {
        int cut1 = (low+high)>>1;
        int cut2 = medianPos - cut1;
        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
        int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
        int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
        if(l1<=r2 && l2<=r1) {
            if((m+n)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0.0;
}*/
/*//K-th Element of two sorted arrays
int kthelement(int arr1[], int arr2[], int m, int n, int k) {
    if(m > n) {
        return kthelement(arr2, arr1, n, m, k); //ensuring that binary search happens on minimum size array
    }
    int low = max(0,k-m), high = min(k,n);//k-m because if we take more than m elements from arr1 then we will have to take less than k elements from arr2
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}*/
/*//Search in sorted 2D matrix
// time complexity: O(log(n*m))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int lo = 0;
    if(!matrix.size()) return false;
    int hi = (matrix.size() * matrix[0].size()) - 1;
    while(lo <= hi) {
        int mid = (lo + (hi - lo) / 2);
        if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target) {
            return true;
        }
        if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return false;
}*/
/*//Matrix median or Median of Row Wise Sorted Matrix
//time complexity O(row*log col)
int countSmallerThanMid(vector<int> &row, int mid){
  int l = 0, h = row.size() - 1;
  while (l <= h){
    int md = (l + h) >> 1;
    if (row[md] <= mid){
      l = md + 1;
    }
    else{
      h = md - 1;
    }
  }
  return l;
}
int findMedian(vector<vector<int>> &A){
  int low = 1;
  int high = 1e9;
  int n = A.size();
  int m = A[0].size();
  while (low <= high){
    int mid = (low + high) >> 1;
    int cnt = 0;
    for (int i = 0; i < n; i++){
      cnt += countSmallerThanMid(A[i], mid);
    }
    if (cnt <= (n * m) / 2)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}*/
