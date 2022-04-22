#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    int ans = 0;
    for (int i = 0; i < N;) {
        int j = i;
        while (j < N && S[i] == S[j]) j++;
        ans++;
        if (i == j) j++;
        i = j;
    }
    ans--;

    cout << ans << endl;
}