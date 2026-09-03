# Equal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Christy is interning at HackerRank. One day she has to distribute some chocolates to her colleagues. She is biased towards her friends and plans to give them more than the others. One of the program managers hears of this and tells her to make sure everyone gets the same number.

To make things difficult, she must equalize the number of chocolates in a series of operations. For each operation, she can give $1, 2 \text{ or }5$ pieces to all but one colleague.  Everyone who gets a piece in a round receives the same number of pieces.  

Given a starting distribution, calculate the minimum number of operations needed so that every colleague has the same number of pieces.    

**Example**   
$arr = [1, 1, 5]$    

$arr$ represents the starting numbers of pieces for each colleague.  She can give $2$ pieces to the first two and the distribution is then $[3, 3, 5]$.  On the next round, she gives the same two $2$ pieces each, and everyone has the same number:  $[5, 5, 5]$.  Return the number of rounds, $2$.  


**Function Description**  

Complete the *equal* function in the editor below.  

equal has the following parameter(s):  

- *int arr[n]:* the integers to equalize   

**Returns**   

- *int:* the minimum number of operations required

**Input Format**

The first line contains an integer $t$, the number of test cases.   

Each test case has $2$ lines.  
- The first line contains an integer $n$, the number of colleagues and the size of $arr$.   
- The second line contains $n$ space-separated integers, $arr[i]$, the numbers of pieces of chocolate each colleague has at the start.  


**Constraints**

$1 \le t \le 100$  
$1 \le n \le 10000$    
The number of chocolates each colleague has initially < $1000$.  


**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-03T08:02:30.556Z  

```cpp
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equal' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int equal(vector<int> arr) {
    int mn = *min_element(arr.begin(), arr.end());
    int ans = INT_MAX;

    for (int target = mn; target >= mn - 4; target--) {
        int operations = 0;

        for (int x : arr) {
            int diff = x - target;

            operations += diff / 5;
            diff %= 5;

            operations += diff / 2;
            diff %= 2;

            operations += diff;
        }

        ans = min(ans, operations);
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);
            arr[i] = arr_item;
        }

        int result = equal(arr);
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

[View on HackerRank](https://www.hackerrank.com/challenges/equal/problem)