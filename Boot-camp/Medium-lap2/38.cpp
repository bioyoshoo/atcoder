#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int64_t, int> D;
    for (int i = 0; i < N; i++) {
        int64_t d;
        cin >> d;
        D[d]++;
    }
    
    int M;
    cin >> M;
    bool flag = true;
    for (int i = 0; i < M; i++) {
        int64_t t;
        cin >> t;
        if (!D.count(t) || D[t] == 0) flag = false;
        else D[t]--;
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}