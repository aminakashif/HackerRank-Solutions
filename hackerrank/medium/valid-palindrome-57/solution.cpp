#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    cin >> s;

    bool palindrome = true;

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            palindrome = false;
            break;
        }

        left++;
        right--;
    }

    if (palindrome) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}
