#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    map<int64_t, vector<int64_t>> A_map;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        A_map[a].push_back(i);
    }
    
    // query
    int64_t Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int64_t l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        if (!A_map.count(x)) cout << 0 << endl;
        else {
            vector<int64_t> interval = A_map[x];
            int64_t inv_size = interval.size();
            int64_t r_idx = inv_size - 1;
            for (int j = 0; j < inv_size; j++) if (r >= interval[j]) r_idx = j;
            int64_t l_idx = 0;
            for (int j = 0; j < inv_size; j++) if (l <= interval[j]) l_idx = j;

            if (l_idx > r_idx) cout << 0 << endl;
            else cout << r_idx - l_idx + 1 << endl;  
        }
    }
}