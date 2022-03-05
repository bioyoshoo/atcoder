#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int64_t Q;
    cin >> Q;
    for (int64_t i = 0; i < Q; i++) {
        int64_t t, k;
        cin >> t >> k;

        int64_t birth_time = ceil((double)k / log10(2));
        string birth_c;
}