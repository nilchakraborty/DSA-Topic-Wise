/*👉🏻 Priority Queue=> max heap(greater to smaller) : It returns max ele from the Arr at the top.[O(log(n)) time]
==> priority_queue<pair<int, int>>pq;
• Priority Queue can be used as min heap(smaller to greater) : It returns ele from the Arr at the top.
==> priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> pq;*/

/*//Convert Min heap to Max Heap
make_heap(heap.begin(), heap.end());*/
/*//Top K Frequent Elements
vector<int> topKFrequent(vector<int> &nums, int k){
    unordered_map<int, int> map;
    for (int num: nums){
        map[num]++;
    }
    vector<int> res;
    priority_queue<pair<int, int>> pq;
    for (auto it = map.begin(); it != map.end(); it++){
        pq.push(make_pair(it->second, it->first));
        if (pq.size() > (int) map.size() - k){
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    return res;
}*/
/*//Kth largest/smallest element in an array
void kth_Largest_MaxHeap(vector<int>&arr, int k) {
    priority_queue<int>pq ;
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i])  ;
    }
    int f = k - 1 ;
    while (f > 0) {
        pq.pop()  ;
        f-- ;
    }
    cout << "Kth Largest element " << pq.top() << "\n"  ;
}
void kth_Smallest_MinHeap(vector<int>&arr, int k) {
    priority_queue<int, vector<int>, greater<int>>pq;
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i])  ;
    }
    int f = k - 1 ;
    while (f > 0) {
        pq.pop()  ;
        f-- ;
    }
    cout << "Kth Smallest element " << pq.top() << "\n"  ;
}*/
/*//Replace elements by its rank
// Time Complexity:O(n)+O(nlogn)+O(n) || space complexity:O(n+n)
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 6;
	int arr[n] = {20, 15, 26, 2, 98, 6};
	map<int, int>mp;
	int temp = 1;
	int brr[n];
	for (int i = 0; i < n; i++) {
		brr[i] = arr[i];
	}
	sort(brr, brr + n);
	for (int i = 0; i < n; i++) {
		//if element is previously not store in the map
		if (mp[brr[i]] == 0) {
			mp[brr[i]] = temp;
			temp++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << mp[arr[i]] << " ";
	}
}*/
/*//Connect n ropes with minimum cost
int minCost(int arr[], int n){
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n);
    int res = 0;
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        res += first + second;
        pq.push(first + second);
    } 
    return res;
}*/
/*// Implement a Maxheap/MinHeap using arrays and recursion.
#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = i * 2 + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void printHeap(int arr[], int n)
{
    cout << "Array represenatation of Heap is:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);

    printHeap(arr, n);
    return 0;
}*/
/*// Sort an Array using heap
#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}*/
/*// Merge “K” sorted arrays
#include<bits/stdc++.h>
using namespace std;
#define n 4
struct MinHeapNode
{
    int element;
    int i,j;
};
void swap(MinHeapNode *x, MinHeapNode *y);
class MinHeap
{
    MinHeapNode *harr;
    int heap_size;
public:
    MinHeap(MinHeapNode a[], int size);
    void MinHeapify(int );
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    MinHeapNode getMin() { return harr[0]; }
    void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); }
};
int *mergeKArrays(int arr[][n], int k)
{
    int *output = new int[n*k];
    MinHeapNode *harr = new MinHeapNode[k];
    for (int i = 0; i < k; i++)
    {
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1;
    }
    MinHeap hp(harr, k);
    for (int count = 0; count < n*k; count++)
    {
        MinHeapNode root = hp.getMin();
        output[count] = root.element;
        if (root.j < n)
        {
            root.element = arr[root.i][root.j];
            root.j += 1;
        }
else root.element = INT_MAX;
        hp.replaceMin(root);
    }
    return output;
}
MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a;
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x; *x = *y; *y = temp;
}
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
    cout << arr[i] << " ";
}
int main()
{
    int arr[][n] = {{2, 6, 12, 34},
                    {1, 9, 20, 1000},
                    {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);

    int *output = mergeKArrays(arr, k);

    cout << "Merged array is " << endl;
    printArray(output, n*k);
    return 0;
}*/
