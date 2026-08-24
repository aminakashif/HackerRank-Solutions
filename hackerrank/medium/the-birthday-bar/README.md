# Subarray Division

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Two children, Lily and Ron, want to share a chocolate bar. Each of the squares has an integer on it. 

Lily decides to share a contiguous segment of the bar selected such that: 

- The length of the segment matches Ron's birth month, and,
- The sum of the integers on the squares is equal to his birth day.

Determine how many ways she can divide the chocolate.

**Example**   
$s = [2, 2, 1, 3, 2]$    
$d = 4$   
$m = 2$   

Lily wants to find segments summing to Ron's birth day, $d = 4$ with a length equalling his birth month, $m = 2$.  In this case, there are two segments meeting her criteria: $[2, 2]$ and $[1,3]$.

**Function Description**

Complete the *birthday* function in the editor below.    

birthday has the following parameter(s):  

- *int s[n]:* the numbers on each of the squares of chocolate  
- *int d:* Ron's birth day  
- *int m:* Ron's birth month  

**Returns**   

- *int:* the number of ways the bar can be divided  



**Input Format**

The first line contains an integer $n$, the number of squares in the chocolate bar.  	
The second line contains $n$ space-separated integers $s[i]$, the numbers on the chocolate squares where $0 \le i \lt n$.  
The third line contains two space-separated integers, $d$ and $m$, Ron's birth day and his birth month.

**Constraints**

* ${1} \leq {n} \leq 100$  
* ${1}\leq {s[i]}\leq {5}$, where (${0}\leq {i} \lt {n}$)     
* ${1} \leq {d} \leq {31}$  
* ${1} \leq {m} \leq {12}$

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-24T08:52:03.696Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'birthday' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY s
 *  2. INTEGER d
 *  3. INTEGER m
 */

int birthday(vector<int> s, int d, int m) {

    int count = 0;

    // Check every contiguous segment of length m
    for (int i = 0; i <= s.size() - m; i++) {

        int sum = 0;

        for (int j = i; j < i + m; j++) {
            sum += s[j];
        }

        if (sum == d) {
            count++;
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input =
        split(rtrim(first_multiple_input_temp));

    int d = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int result = birthday(s, d, m);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/the-birthday-bar/problem)