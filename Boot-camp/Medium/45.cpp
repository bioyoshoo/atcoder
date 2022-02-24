#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;

    int64_t S = N, cc = M / 2;
    if (S >= cc) cout << S << endl;
    else cout << S + (cc - S) / 2 << endl;
}