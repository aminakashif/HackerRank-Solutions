# Container With Most Water 71

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given N vertical lines.

The height of the line at position i is Ai.

Choose two different lines i and j. The amount of water they can contain is:

min(Ai, Aj) × (j - i)

Find the maximum possible amount of water.

 **Input Format** 

The first line contains an integer N.

The second line contains N space-separated integers representing the heights of the lines.

 **Constraints** 

2 ≤ N ≤ 2 × 10^5

0 ≤ Ai ≤ 10^9

 **Output Format** 

Print the maximum amount of water that can be contained.

 **Sample Input 0** 

```
9
1 8 6 2 5 4 8 3 7

```

 **Sample Output 0** 

```
49

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-12T11:54:25.014Z  

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0;
    int right = n - 1;
    int maxWater = 0;

    while (left < right) {
        int height = min(a[left], a[right]);
        int width = right - left;

        int water = height * width;

        maxWater = max(maxWater, water);

        if (a[left] < a[right]) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << maxWater << endl;

    return 0;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/container-with-most-water-71/problem)