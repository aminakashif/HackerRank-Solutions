#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> s;

    for (int i = 0; i < q; i++) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            s.insert(x);
        }
        else if (type == 2) {
            s.erase(x);
        }
        else if (type == 3) {
            if (s.find(x) != s.end()) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
