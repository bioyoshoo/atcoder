#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> V(N, -1);
    
    bool flag = true;
    for (int i = 0; i < M; i++) {
        int s, c;
        cin >> s >> c;
        s--;
        
        if (V.at(s) != -1 && V.at(s) != c) flag = false;
        else V.at(s) = c;
    }
    if (N > 1 && V.at(0) == 0) flag = false;
    
    if (!flag) cout << -1 << endl;
    else {
        if (N > 1 && V.at(0) == -1) V.at(0) = 1;

        for (int i = 0; i < N; i++) if (V.at(i) == -1) V.at(i) = 0;
        for (int i = 0; i < N; i++) cout << V.at(i);
        cout << endl;
    }
}