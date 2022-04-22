#include <bits/stdc++.h>
using namespace std;

int64_t count(string S) {
    int64_t res = 0;
    int64_t n = S.size();
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && S[i] == S[j]) j++;
        res += (j - i) / 2;
        if (i == j) j++;
        i = j;
    }
    return res;
}

int main() {
    string S;
    cin >> S;
    int64_t K;
    cin >> K;

    int64_t cnt_one = count(S);

    string SS = S + S;
    int64_t cnt_two = count(SS);

    int64_t joint = 2 * cnt_one - cnt_two;
    int64_t ans = (cnt_one - joint) * K + (K - 1) * joint;

    cout << ans << endl;
}