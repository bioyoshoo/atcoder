#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    map<int, int> b_idx, idx_b;
    for (int i = 0; i < N; i++) {
        b_idx[i + 1] = i;
        idx_b[i] = i + 1;
    }
    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        int idx = b_idx[x];
        
        int search_idx;
        if (idx != N - 1) search_idx = idx + 1;
        else search_idx = idx - 1;
        
        int search_ball = idx_b[search_idx];

        b_idx[x] = search_idx;
        b_idx[search_ball] = idx;

        idx_b[search_idx] = x;
        idx_b[idx] = search_ball;
    }

    for (auto a: idx_b) {
        cout << a.second << " ";
    }
    cout << endl;
}