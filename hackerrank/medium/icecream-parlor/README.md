# Ice Cream Parlor

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Two friends like to pool their money and go to the ice cream parlor.  They always choose two distinct flavors and they spend all of their money.

Given a list of prices for the flavors of ice cream, select the two that will cost all of the money they have.  

**Example**. 
$m = 6$
$cost = [1, 3, 4, 5, 6]$

The two flavors that cost $1$ and $5$ meet the criteria.  Using $1$-based indexing, they are at indices $1$ and $4$.  

**Function Description**

Complete the *icecreamParlor* function in the editor below.    

icecreamParlor has the following parameter(s):  

- *int m:* the amount of money they have to spend  
- *int cost[n]:* the cost of each flavor of ice cream  

**Returns**   

- *int[2]:*  the indices of the prices of the two flavors they buy, sorted ascending 

**Input Format**

The first line contains an integer, $t$, the number of trips to the ice cream parlor.   The next $t$ sets of lines each describe a visit.  

Each trip is described as follows:

1. The integer $m$, the amount of money they have pooled. 
2. The integer $n$, the number of flavors offered at the time. 
3. $n$ space-separated integers denoting the cost of each flavor: $cost[cost[1], cost[2],\ldots,cost[n]]$.  

**Note**:  The index within the cost array represents the flavor of the ice cream purchased.  

**Constraints**

- $1 \le t \le 50$  
- $2 \le m \le 10^4$   
- $2 \le n \le 10^4$   
- $1 \le cost[i] \le 10^4$, &forall; $i \in [1, n]$   
- There will always be a unique solution.

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-24T08:41:15.555Z  

```cpp
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'icecreamParlor' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER m
 *  2. INTEGER_ARRAY arr
 */

vector<int> icecreamParlor(int m, vector<int> arr) {

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {

            if (arr[i] + arr[j] == m) {
                return {i + 1, j + 1};
            }
        }
    }

    return {};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {

        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

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

        vector<int> result = icecreamParlor(m, arr);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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

[View on HackerRank](https://www.hackerrank.com/challenges/icecream-parlor/problem)