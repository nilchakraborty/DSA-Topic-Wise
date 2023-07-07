/*👉🏻 Stack:Abstract Data Type (ADT)=>LIFO(last in first out)
• Push(), Pop(), Peek(), isEmpty(), isFull()
👉🏻 Queue:ADT=>FIFO(first in first out)
• Enqueue(), Dequeue(), Peek(), isEmpty(), isFull()*/

/*//Implement stack using array
https://takeuforward.org/data-structure/implement-stack-using-array/*/
/*//Implement Queue using array
https://takeuforward.org/data-structure/implement-queue-using-array/*/
/*//Implement Stack using Queue
https://takeuforward.org/data-structure/implement-stack-using-single-queue/*/
/*//Implement Queue using Stack
https://takeuforward.org/data-structure/implement-queue-using-stack/*/
/*//Implement Stack using Linked List
https://takeuforward.org/data-structure/implement-stack-using-linked-list/*/
/*//Implement Queue using Linked List
https://takeuforward.org/data-structure/implement-queue-using-linked-list/*/
/*//Implement Min Stack
https://takeuforward.org/data-structure/implement-min-stack-o2n-and-on-space-complexity/*/
/*//Infix to Prefix
https://takeuforward.org/data-structure/infix-to-prefix/*/
/*//Infix to Postfix
https://takeuforward.org/data-structure/infix-to-postfix/*/
/*//LRU cache
https://takeuforward.org/data-structure/implement-lru-cache/*/
/*//Check for Balanced Parentheses
// time complexity:O(n) || space complexity:O(n)
bool isValid(string s) {
    stack<char>st; 
    for(auto it: s) {
        if(it=='(' || it=='{' || it == '[') st.push(it); 
        else {
            if(st.size() == 0) return false; 
            char ch = st.top(); 
            st.pop(); 
            if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
            else return false;
        }
    }
    return st.empty(); 
}*/
/*//Next Greater element
vector < int > nextGreaterElements(vector < int > & nums) {
    int n = nums.size();
    vector < int > nge(n, -1);// initialize vector with -1
    stack < int > st;
    //2n for circular array , use n for non circular array
    for (int i = 2 * n - 1; i >= 0; i--) {
    while (!st.empty() && st.top() <= nums[i % n]) { //i%n for circular and i for non circular
        st.pop(); // remove all elements from stack smaller than the current element
    }
    if (i < n && !st.empty()) { // check if a greater element exists in the stack
        nge[i] = st.top();
    }
    st.push(nums[i % n]); // add the current element to the stack. This ensures that the next greater element for this element is found in the future iterations of the loop.
    }
    return nge; // return the result vector
}*/
/*//Next smaller element
vector<int> nextSmallerElements(vector<int>& nums) {
  int n = nums.size();
  vector<int> nse(n, -1); // initialize vector with -1
  stack<int> st;
  for (int i = 2 * n - 1; i >= 0; i--) {
    while (!st.empty() && st.top() >= nums[i % n]) {
      st.pop(); // remove all elements from stack smaller than the current element
    }
    if (i < n && !st.empty()) { // check if a greater element exists in the stack
      nge[i] = st.top();
    }
    st.push(nums[i % n]); // add the current element to the stack
  }
  return nge; // return the result vector
}*/
/*//Area of largest rectangle in Histogram
int largestRectangleArea(vector < int > & histo) {
    stack < int > st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++) {
    while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
        int height = histo[st.top()];
        st.pop();
        int width;
        if (st.empty())
        width = i;
        else
        width = i - st.top() - 1;
        maxA = max(maxA, width * height);
    }
    st.push(i);
    }
    return maxA;
}*/
/*//Sliding Window Maximum
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        // If the deque is not empty and the front element is outside the window (i.e., its index is less than i - k), we remove it from the front of the deque.
        if (!q.empty() && q.front() == i - k) {
            q.pop_front();
        }
        // Remove elements that are smaller than the current element, We then remove all elements from the back of the deque that are smaller than the current element. This ensures that the maximum element is always at the front of the deque.
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        // Add the current element to the deque
        q.push_back(i);
        // If the window is fully formed (i.e., we have processed at least k elements), we add the maximum element (the element at the front of the deque) to the result vector.
        if (i >= k - 1) {
            result.push_back(nums[q.front()]);
        }
    }
    return result;
}
// i	nums[i]	deque	result
// 0	1	    [0]	
// 1	3	    [1]	
// 2	-1	    [1, 2]	    3
// 3	-3	    [1, 2, 3]	3
// 4	5	    [4]	        5
// 5	3	    [4, 5]	    5
// 6	6	    [6]	        6*/
