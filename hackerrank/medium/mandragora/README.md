# Mandragora Forest

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

The evil forest is guarded by vicious mandragoras. Garnet and her [pet](http://finalfantasy.wikia.com/wiki/Quina) must make a journey through.  She starts with $1$ health point ($s$) and $0$ experience points.    

As she encouters each mandragora, her choices are:

1. Garnet's pet *eats* mandragora $i$. This increments $s$ by $1$ and defeats mandragora $i$.  
2. Garnet's pet *battles* mandragora $i$. This increases $p$ by $s \times H[i]$ experience points and defeats mandragora $i$. 

Once she defeats a mandragora, it is out of play.  Given a list of mandragoras with various health levels, determine the maximum number of experience points she can collect on her journey.  

For example, as always, she starts out with $s = 1$ health point and $p=0$ experience points.  Mandragoras have the following health values: $H=[3, 2, 5]$.  For each of the beings, she has two choices, $e$at or $b$attle.  We have the following permutations of choices and outcomes:
			
    Action  s	p
    _______ _   __
    e, e, e 4	0
    e, e, b	3	15
    e, b, b	2	14
    b, b, b	1	10
    b, b, e	2	10
    b, e, e	3	9
    b, e, b	2	16
    e, b, e	3	6
    
Working through a couple of rows, first, her pet can eat all three and she does not gain any experience points.  In the second row, her pet eats the first two to have $1+2=3$ health points, then battles the beast with $5$ heatlth points to gain $3 * 5 =15$ experience points.  We see that the best option is to eat the beast with $2$ points and battle the others to achieve $2 \times (3+5)=16$ experience points.

**Function Description**  

Complete the *mandragora* function in the editor below.  It must return an integer that denotes the maximum number of experience points that Garnet can earn.

mandragora has the following parameter(s):  

- *H*: an array of integers that represents the health values of mandragoras  

**Input Format**

The first line contains an integer, $t$, denoting the number of test cases. Each test case is described over two lines:

1. The first line contains a single integer $n$, the number of mandragoras in the forest. 
2. The second line contains $n$ space-separated integers describing the respective health points for the mandragoras $H[H[1], H[2]...H[n]]$.  	

**Constraints**

* $1 \le t \le 10^5$   
* $1 \le n \le 10^5$   
* $1 \le H[i] \le 10^7$, where $1 \le i \le n$   
* The sum of all $n$s in a single test case is $\le 10^6$  

**Output Format**

For each test case, print a single line with an integer denoting the maximum number of experience points that Garnet can earn.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-24T09:12:14.434Z  

```cpp
#include <bits/stdc++.h> 
   
using namespace std; 
   
string ltrim(const string &); 
string rtrim(const string &); 
vector<string> split(const string &); 
   
/* 
 * Complete the 'mandragora' function below. 
 * 
 * The function is expected to return a LONG_INTEGER. 
 * The function accepts INTEGER_ARRAY H as parameter. 
 */ 
   
long mandragora(vector<int> H) { 
    sort(H.begin(), H.end());

    long long total = 0;
    for (int x : H) {
        total += x;
    }

    long long ans = 0;
    long long eaten = 0;

    for (int i = 0; i < H.size(); i++) {
        eaten += H[i];

        long long remaining = total - eaten;
        long long strength = i + 2;

        ans = max(ans, strength * remaining);
    }

    ans = max(ans, total);

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
   
        string H_temp_temp; 
        getline(cin, H_temp_temp); 
   
        vector<string> H_temp = split(rtrim(H_temp_temp)); 
   
        vector<int> H(n); 
   
        for (int i = 0; i < n; i++) { 
            int H_item = stoi(H_temp[i]); 
   
            H[i] = H_item; 
        } 
   
        long result = mandragora(H); 
   
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

[View on HackerRank](https://www.hackerrank.com/challenges/mandragora/problem)