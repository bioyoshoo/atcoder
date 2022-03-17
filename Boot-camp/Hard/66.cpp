#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = (int)S.size();

    int64_t ans = 0;
    string sub_s = "";
    for (int i = 0; i < N; i++) {
        sub_s += S.at(i);
        if (i - 2 > 0) sub_s += sub_s.substr(1, 3);
        if (sub_s == "ABC") {
            sub_s = "BAC";
            ans++;
        }
    }
}