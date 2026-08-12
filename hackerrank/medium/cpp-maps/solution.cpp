#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, int> m;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        string name;
        cin >> name;

        if (type == 1) {
            int marks;
            cin >> marks;
            m[name] += marks;
        }
        else if (type == 2) {
            m.erase(name);
        }
        else if (type == 3) {
            cout << m[name] << endl;
        }
    }

    return 0;
}
