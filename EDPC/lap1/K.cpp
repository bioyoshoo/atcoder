#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;
vector<int> dp;
int rec(int k) {
    if (dp[k] >= 0) return dp[k];
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (k - A[i] >= 0 && !rec(k - A[i])) res = 1;
    }
    return dp[k] = res;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A.push_back(a);
    }

    dp.assign(K + 1, -1);

    if (rec(K)) cout << "First" << endl;
    else cout << "Second" << endl;
}