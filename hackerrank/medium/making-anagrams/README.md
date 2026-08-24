# Making Anagrams

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency. For example, `bacdc` and `dcbac` are anagrams, but `bacdc` and `dcbad` are not.

Alice is taking a cryptography class and finding *anagrams* to be very useful. She decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Can you help her find this number? 
  
Given two strings, $s1$ and $s2$, that may not be of the same length, determine the minimum number of character deletions required to make $s1$ and $s2$ anagrams. Any characters can be deleted from either of the strings. 

**Example**.  
$s1 = \texttt{abc}$    
$s2 = \texttt{amnop}$     

The only characters that match are the $\texttt{a}$'s so we have to remove $\texttt{bc}$ from $s1$ and $\texttt{mnop}$ from $s2$ for a total of $6$ deletions.  

**Function Description**  

Complete the *makingAnagrams* function in the editor below.    

makingAnagrams has the following parameter(s):  

- *string s1:* a string  
- *string s2:* a string   

**Returns**   

- *int:* the minimum number of deletions needed   


**Input Format**

The first line contains a single string, $s1$. 	
The second line contains a single string, $s2$.

**Constraints**

- $1 \le |s1|, |s2| \le 10^4$  
- It is guaranteed that $s1$ and $s2$ consist of lowercase English letters, ascii[a-z].

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-24T08:47:40.135Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {

    int count[26] = {0};

    // Count characters in s1
    for (char c : s1) {
        count[c - 'a']++;
    }

    // Remove characters that are present in s2
    for (char c : s2) {
        count[c - 'a']--;
    }

    int deletions = 0;

    // Sum of all frequency differences
    for (int i = 0; i < 26; i++) {
        deletions += abs(count[i]);
    }

    return deletions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/making-anagrams/problem)