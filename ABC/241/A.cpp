#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> V(10);
    for (int i = 0; i < 10; i++) cin >> V.at(i);

    int digits = 0;
    for (int i = 0; i < 3; i++) {
        digits = V.at(digits);
    }
    cout << digits << endl;
}