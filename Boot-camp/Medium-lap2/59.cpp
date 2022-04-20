#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P.at(i);

    int ans = 0;
    for (int i = 0; i < N;) {
        int j = i;
        while (j < N && P.at(j) == j + 1) j++;
        ans += (j - i + 1) / 2;
        if (i == j) j++;
        i = j;
    }

    cout << ans << endl;
}