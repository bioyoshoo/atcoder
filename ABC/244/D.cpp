#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> S(3), T(3);
    for (int i = 0; i < 3; i++) cin >> S.at(i);
    for (int i = 0; i < 3; i++) cin >> T.at(i);

    int diff = 0;
    for (int i = 0; i < 3; i++) {
        if (S.at(i) != T.at(i)) diff++;
    }
    if (diff == 2) cout << "No" << endl;
    else cout << "Yes" << endl;
}
