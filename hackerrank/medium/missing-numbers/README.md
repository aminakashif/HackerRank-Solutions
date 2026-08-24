# Missing Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two arrays of integers, find which elements in the second array are missing from the first array.

**Example**  
$arr = [7, 2, 5, 3, 5, 3]$  
$brr = [7, 2, 5, 4, 6, 3, 5, 3]$

The $brr$ array is the orginal list.  The numbers missing are $[4, 6]$.  

**Notes**  

* If a number occurs multiple times in the lists, you must ensure that the frequency of that number in both lists is the same. If that is not the case, then it is also a missing number. 
* Return the missing numbers sorted ascending. 
* Only include a missing number once, even if it is missing multiple times. 
* The difference between the maximum and minimum numbers in the original list is less than or equal to $100$.  

**Function Description**  

Complete the *missingNumbers* function in the editor below.  It should return a sorted array of missing numbers.  

missingNumbers has the following parameter(s):

- *int arr[n]:* the array with missing numbers   
- *int brr[m]:* the original array of numbers   

**Returns**   

- *int[]:* an array of integers   

**Input Format**

There will be four lines of input:  

 $n$ - the size of the first list, $arr$  
 The next line contains $n$ space-separated integers $arr[i]$  
 $m$ - the size of the second list, $brr$  
 The next line contains $m$ space-separated integers $brr[i]$  


**Constraints**

* $1 \le n, m \le 2 \times 10^{5}$  
* $ n \le m $
* $1 \le brr[i] \le 10^{4}$  
* $max(brr) - min(brr) \le 100$


**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-24T08:34:55.991Z  

```cpp
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'missingNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY brr
 */

vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    map<int, int> arrCount;
    map<int, int> brrCount;

    // Count frequencies in arr
    for (int num : arr) {
        arrCount[num]++;
    }

    // Count frequencies in brr
    for (int num : brr) {
        brrCount[num]++;
    }

    vector<int> result;

    // Check which numbers occur more times in brr
    for (auto x : brrCount) {
        int num = x.first;
        int brrFrequency = x.second;
        int arrFrequency = arrCount[num];

        if (brrFrequency > arrFrequency) {
            result.push_back(num);
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);
        brr[i] = brr_item;
    }

    vector<int> result = missingNumbers(arr, brr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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

[View on HackerRank](https://www.hackerrank.com/challenges/missing-numbers/problem)