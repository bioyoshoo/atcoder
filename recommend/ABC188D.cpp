#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, C;
    cin >> N >> C;

    vector<int64_t> V(1e9 + 1);
    for (int i = 0; i < N; i++) {
        int64_t a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        V[a] = c;
        V[b + 1] = -c;
    }
    for (int i = 1; i < 1e9 + 1; i++) V.at(i) += V.at(i - 1);
    
}