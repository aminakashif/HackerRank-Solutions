# Sherlock and Anagrams

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Two strings are [*anagrams*][123] of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.  

**Example**  
$s = mom$  

The list of all anagrammatic pairs is $[m, m], [mo, om]$ at positions $[[0], [2]], [[0, 1], [1, 2]]$ respectively.

[123]: http://en.wikipedia.org/wiki/Anagram  

**Function Description**

Complete the function *sherlockAndAnagrams* in the editor below.  

sherlockAndAnagrams has the following parameter(s):

-  *string s:* a string  

**Returns**  

- *int:* the number of unordered anagrammatic pairs of substrings in $s$

**Input Format**

The first line contains an integer $q$, the number of queries.   
Each of the next $q$ lines contains a string $s$ to analyze. 

**Constraints**

$1 \le q \le 10$   
$2 \le \text{ length of }s \le 100$  
$s$ contains only lowercase letters in the range ascii[a-z]. 

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-24T09:17:27.038Z  

```cpp
#include <bits/stdc++.h> 
   
using namespace std; 
   
string ltrim(const string &); 
string rtrim(const string &); 
   
/* 
 * Complete the 'sherlockAndAnagrams' function below. 
 * 
 * The function is expected to return an INTEGER. 
 * The function accepts STRING s as parameter. 
 */ 
   
int sherlockAndAnagrams(string s) { 
    int ans = 0;
    int n = s.size();

    for (int len = 1; len < n; len++) {
        map<string, int> freq;

        for (int i = 0; i + len <= n; i++) {
            string sub = s.substr(i, len);
            sort(sub.begin(), sub.end());
            freq[sub]++;
        }

        for (auto x : freq) {
            int count = x.second;
            ans += count * (count - 1) / 2;
        }
    }

    return ans;
} 
   
int main() 
{ 
    ofstream fout(getenv("OUTPUT_PATH")); 
   
    string q_temp; 
    getline(cin, q_temp); 
   
    int q = stoi(ltrim(rtrim(q_temp))); 
   
    for (int q_itr = 0; q_itr < q; q_itr++) { 
        string s; 
        getline(cin, s); 
   
        int result = sherlockAndAnagrams(s); 
   
        fout << result << "\n"; 
    } 
   
    fout.close(); 
   
    return 0; 
} 
   
string ltrim(const string &str) { 
    string s(str); 
   
    s.erase( 
        s.begin(), 
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))) 
    ); 
   
    return s; 
} 
   
string rtrim(const string &str) { 
    string s(str); 
   
    s.erase( 
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), 
        s.end() 
    ); 
   
    return s; 
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem)