#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int64_t len = (int)S.size();

    int64_t count = len * (len - 1);
    for (int64_t i = 0; i < len; i++) {
        if (S.at(i) == 'U') count += i;
        else if (S.at(i) == 'D') count += len - 1 - i;
    }

    cout << count << endl;
}