#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

// Red, level N, 1 -> Red, level N - 1, 1 + X : Blue, level N - 1, X*Y
// Blue, level N, 1 -> Red, level N - 1, 1 : Blue, level N - 1, Y
ll X, Y;
vector<ll> Red, Blue;
rec(int level) {
    if (level == 0) break;
    Red[level - 1] += Red[level] * (1 + X);
    Blue[level - 1] += Red[level] * X*Y;

    Red[level - 1] += Blue[level];
    Blue[level - 1] += Blue[level] * Y;
}

int main() {
    int N; cin >> N >> X >> Y;
    

}