/*👉🏻 getline(cin,s): to input a line of string
👉🏻 isalpha() is used to check that a character is an alphabet or not. isdigit() for number. isalnum() : check if character is alphanumeric
👉🏻 to_string() to convert any numerical value to string.
👉🏻 to add a char after string :use s.push_back('a') instead of s+='a' bcus push_back work in O(1) and 'a' works in O(s.size())
👉🏻 substr(pos, size()) for eg : if given str is "Geeks" and str.substr(1, 3); then it will print "eek"
👉🏻 memset(It copies a single character for a specified number of times to an object) : char str[] = "geeksforgeeks";
memset(str, 't', sizeof(str)); => tttttttttttttt
👉🏻 for hour mins as string i.e 02:30 => s[0] * 600 + s[1] * 60 + s[3] * 10 + s[4];
👉🏻 return (s2.find(s1) != string::npos); ==>s1 is a substring of s2 using the find function. The find function returns the starting position of the first occurrence of s1 in s2, or string::npos if s1 is not found in s2.
• to find a word or set of letter in string we simply use find() function =>string str = "hello world!";string word = "world";int index = str.find(word);
• to find the eaxct location We store this index in the index variable => if (index != string::npos) cout << "Index of " << word << " in " << str << " is: " << index <<endl;
👉🏻 stringstream func to count word &is similar to input / output file stream
• stringstream ss(str) =>new stringstream object ss initialized with the string str.
• we can read from it : ss >> myChar;(stores it in the integer variable myChar) [ for more: www.geeksforgeeks.org / converting - strings - numbers - cc / ]
• we can write to it : ss << myInt;*/

/*//Remove Outermost Parentheses
string removeOuterParentheses(string S) {
    string res;
    int opened = 0;
    for (char c : S) {
        if (c == '(' && opened++ > 0) res += c;
        if (c == ')' && opened-- > 1) res += c;
    }
    return res;
}*/
/*//reverse a string
reverse(str.begin(),str.end());*/
/*//Largest odd number in a string
string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; --i)
        if ((num[i] - '0') % 2)
            return num.substr(0, i + 1);
    return string();
}
// 1 liner
string largestOddNumber(string n) {
    return n.substr(0, n.find_last_of("13579") + 1);
}*/
/*//Longest Common Prefix
string longestCommonPrefix(vector<string>& strs){
    int n =strs.size();
    string ans;
    sort(strs.begin(), strs.end());
    string a = strs[0];
    string b = strs[n-1];
    for(int i =0; i< a.size(); i++){
        if(a[i] == b[i]){
            ans += a[i];
        }else break;
    }
    return ans;
}*/
/*//Isomorphic String
bool isIsomorphic(string s, string t){
    char map_s[128] = {0};
    char map_t[128] = {0};
    int len = s.size();
    for (int i = 0; i < len; ++i){
        if (map_s[s[i]] != map_t[t[i]])
            return false;
        map_s[s[i]] = i + 1;
        map_t[t[i]] = i + 1;
    }
    return true;
}*/
/*//Write a Code to check whether one string is a rotation of another
bool rotation(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}*/
/*//Check if two Strings are anagrams of each other
bool CheckAnagrams(string str1, string str2){
  if (str1.length() != str2.length())
    return false;
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());
  for (int i = 0; i < str1.length(); i++){
    if (str1[i] != str2[i])
      return false;
  }
  return true;
}*/
/*//Sort Characters by frequency
string frequencySort(string s){
    unordered_map<char, int> m;
    priority_queue<pair<int, char>> pq;
    for (char c : s)
        m[c]++;
    for (auto &p : m)
        pq.push({p.second, p.first});
    s = "";
    while (!pq.empty()){
        s += string(pq.top().first, pq.top().second);
        pq.pop();}
    return s;
}*/
/*//Maximum Nesting Depth of Paranthes
int maxDepth(string s) {
    int mx(0),cnt(0);
    for(char c:s){
        if(c=='(') cnt++;
        else if(c==')') cnt--;
        mx=max(mx,cnt);}
    return mx;
}*/
/*//Roman Number to Integer
int romanToInt(string s)
{
    int n=s.length(),i,r=0;
    for(i=0;i<n;i++)
    {
        if(i<n-1 && s[i]=='I' && s[i+1]=='V')
        {
            r+=4;
            i++;
            continue;
        }
        else if(i<n-1 && s[i]=='I' && s[i+1]=='X')
        {
            r+=9;
            i++;
            continue;
        }
        else if(s[i]=='I')
            r+=1;
        else if(s[i]=='V')
            r+=5;
        else if(i<n-1 && s[i]=='X' && s[i+1]=='L')
        {
            r+=40;
            i++;
            continue;
        }
        else if(i<n-1 && s[i]=='X' && s[i+1]=='C')
        {
            r+=90;
            i++;
            continue;
        }
        else if(s[i]=='X')
            r+=10;
        else if(s[i]=='L')
            r+=50;
        else if(i<n-1 && s[i]=='C' &&s[i+1]=='D')
        {
            r+=400;
            i++;
            continue;
        }
        else if(i<n-1 && s[i]=='C' &&s[i+1]=='M')
        {
            r+=900;
            i++;
            continue;
        }
        else if(s[i]=='C')
            r+=100;
        else if(s[i]=='D')
            r+=500;
        else if(s[i]=='M')
            r+=1000;
    }
    return r;
}*/
/*//Implement Atoi
int myAtoi(string s) {
//short version of myAtoi
    int r = 0;
    stringstream ss(s);
    ss >> r;
    return r;
//original version of myAtoi
    int sign = 1;
    int i = 0;
    long long num = 0;
    while (s[i] == ' ') {// Skip leading whitespace
        i++;
    }
    if (s[i] == '+' || s[i] == '-') {// Check sign
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    while (isdigit(s[i])) {// Convert digits
        num = num * 10 + (s[i] - '0');
        i++;
        if (num * sign >= INT_MAX) {
            return INT_MAX;
        }
        if (num * sign <= INT_MIN) {
            return INT_MIN;
        }
    }
    return num * sign;
}*/
/*//Minimum number of bracket reversals needed to make an expression balanced
int countMinReversals(string expr){
    int len = expr.length();
    if (len % 2 != 0) {
        return -1;
    }
    int left_brace = 0, right_brace = 0;
    int ans;
    for (int i = 0; i < len; i++) {
        if (expr[i] == '{') {
            left_brace++;
        }
        else {
            if (left_brace == 0) {
                right_brace++;
            }
            else {
                left_brace--;
            }
        }
    }
    ans = ceil(left_brace / 2.0) + ceil(right_brace / 2.0);
    return ans;
}*/
/*//Count and Say
string countAndSay(int n) {
    if (n == 1) return "1";
    string prev = countAndSay(n-1);
    string curr = "";
    for (int i = 0; i < prev.length(); i++) {
        int count = 1;
        while (i+1 < prev.length() && prev[i] == prev[i+1]) {
            count++;
            i++;
        }
    curr += to_string(count) + prev[i];
    }
    return curr;
}*/
/*//Rabin Karp Algo
#include <string.h>
#include <iostream>
using namespace std;

#define d 10

void rabinKarp(char pat[], char txt[], int q) {
  int m = strlen(pat);
  int n = strlen(txt);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;

  // Calculate hash value for pattern and text
  for (i = 0; i < m; i++) {
    p = (d * p + pat[i]) % q;
    t = (d * t + txt[i]) % q;
  }

  // Find the match
  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (txt[i + j] != pat[j])
          break;
      }

      if (j == m)
        cout << "Pattern is found at position: " << i + 1 << endl;
    }

    if (i < n - m) {
      t = (d * (t - txt[i] * h) + txt[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}

int main() {
  char text[] = "ABCCDDAEFG";
  char pattern[] = "CDD";
  int q = 13;
  rabinKarp(pattern, text, q);
}*/
/*// KMP Algo
// Brute Force[O(m - n) * n]
class Solution{
public:
    int strStr(string text, string pat)
    {
        int m = text.length(), n = pat.length();
        for (int i = 0; i <= m - n; i++)
        {
            int j;
            for (j = 0; j < n; j++)
            {
                if (text[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == n)
            {
                return i;
            }
        }
        return -1;
    }
};

// kmp [O(m+n)]
class Solution {
public:
    int strStr(string text, string pat) {
        int m=text.length(),n=pat.length();
        if(n==0)
            return 0;
        vector<int>lps(n,0);
        int j=0,i=1;
        while(i<n)
        {
            if(pat[i]==pat[j])
            {
                j++;
                lps[i]=j;
                i++;
            }
            else
            {
                if(j!=0 )
                {
                    j=lps[j-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        i=0,j=0;
        while(i<m)
        {
            if(text[i]==pat[j])
            {
                i++;
                j++;
                if(j==n)
                {
                    return i-j;
                }
            }
            else
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }
};*/
/*//Shortest Palindrome
#include <bits/stdc++.h>
using namespace std;
// using kmp algorithm
int find_lps(string str){
	int n = str.length();
	vector<int> lps(n, 0); // initialized with 0
	int len = 0; // length of previous longest prefix suffix
	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < n) {
		if (str[len] == str[i]) {
			lps[i++] = ++len;
		}
		else {
			if (len != 0)
				len = lps[len - 1];
			else
				lps[i++] = 0;
		}
	}
	return lps[n - 1];
}
int main(){
	string s = "AABAACAABAA";
	string rev = s;
	reverse(rev.begin(), rev.end());
	string newS = s + "#" + rev;
	int len = find_lps(newS);
	cout << s.length() - len << endl;
	return 0;
}*/
//Sliding Window & Two Pointer Combined Problems
/*//Length of Longest Substring without any Repeating Character
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0, i = 0, j = 0;
    unordered_set<char> s;
    while (i < n && j < n) {
        if (s.find(s[j]) == s.end()) {
            s.insert(s[j++]);
            maxLength = max(maxLength, j - i);
        } else {
            s.erase(s[i++]);
        }
    }
    return maxLength;
}*/
/*//longest repeating character replacement
int characterReplacement(string s, int k){
    int size = s.size();
    int ret = 0;
    vector<int> count(26, 0);
    int start = 0;
    int end = 0;
    int globalMaxFreq = 0;
    for (; end < size; end++){
        count[s[end] - 'A'] += 1;
        globalMaxFreq = max(globalMaxFreq, count[s[end] - 'A']);
        if ((end - start + 1) - globalMaxFreq > k){
            ret = max(ret, (end - start));
            count[s[start] - 'A'] -= 1;
            start += 1;
        }
    }
    return max(ret, end - start);
}*/
/*//Number of substring containing all Three Characters
int numberOfSubstrings(string s) {
    int n = s.length();
    vector<int> count(3); // count of characters 'a', 'b', 'c'
    int left = 0; // left pointer of the sliding window
    int result = 0; // number of substrings
    for (int right = 0; right < n; right++) {
        count[s[right] - 'a']++; // increment the count of the current character            
        // If we have at least one occurrence of all characters 'a', 'b', and 'c'
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            result += n - right; // all substrings starting from left to right are valid       
            // Move the left pointer to shrink the window
            count[s[left] - 'a']--;
            left++;
        }
    }
    return result;
}*/
/*//Maximum Window SubString
string minWindow(string s, string t){
    if (s.size() == 0 || t.size() == 0) return "";
    vector<int> remaining(128, 0);
    int required = t.size();
    for (int i = 0; i < required; i++) remaining[t[i]]++;
    int min = INT_MAX, start = 0, left = 0, i = 0;
    while (i <= s.size() && start < s.size()){
        if (required){
            if (i == s.size()) break;
            remaining[s[i]]--;
            if (remaining[s[i]] >= 0) required--;
            i++;
        }
        else{
            if (i - start < min)
            {
                min = i - start;
                left = start;
            }
            remaining[s[start]]++;
            if (remaining[s[start]] > 0) required++;
            start++;
        }
    }
    return min == INT_MAX ? "" : s.substr(left, min);
}*/
