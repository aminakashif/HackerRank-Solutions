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
