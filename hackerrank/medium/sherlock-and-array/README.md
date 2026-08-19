# Sherlock and Array

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Watson gives Sherlock an array of integers.  His challenge is to find an element of the array such that the sum of all elements to the left is equal to the sum of all elements to the right.  

**Example**  

$arr = [5, 6, 8, 11]$  

$8$ is between two subarrays that sum to $11$.  

$arr = [1]$  

The answer is $[1]$ since left and right sum to $0$.

You will be given arrays of integers and must determine whether there is an element that meets the criterion.  If there is, return `YES`.  Otherwise, return `NO`.

**Function Description**  

Complete the *balancedSums* function in the editor below.  

balancedSums has the following parameter(s):  

- *int arr[n]:* an array of integers  

**Returns**  

- *string:*  either `YES` or `NO`  

**Input Format**

The first line contains $T$, the number of test cases.  

The next $T$ pairs of lines each represent a test case.  
- The first line contains $n$, the number of elements in the array $arr$.  
- The second line contains $n$ space-separated integers $arr[i]$ where $0 \le i < n$.  


**Constraints**

$1 \le T \le 10$    
$1 \le n \le 10^5$   
$1 \le arr[i] \le 2 \times 10^4$  
$0 \le i < n$


**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-19T10:58:08.207Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'balancedSums' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

string balancedSums(vector<int> arr) {
    int totalSum = 0;
    
    for (int x : arr) {
        totalSum += x;
    }

    int leftSum = 0;

    for (int x : arr) {
        totalSum -= x;  // now totalSum = right side

        if (leftSum == totalSum) {
            return "YES";
        }

        leftSum += x;
    }

    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
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

        string result = balancedSums(arr);

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

[View on HackerRank](https://www.hackerrank.com/challenges/sherlock-and-array/problem)