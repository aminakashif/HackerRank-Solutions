#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += a[i];
    }

    int maxSum = sum;

    for (int i = k; i < n; i++) {
        sum = sum + a[i] - a[i - k];

        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    double average = (double)maxSum / k;

    printf("%.6f", average);

    return 0;
}
