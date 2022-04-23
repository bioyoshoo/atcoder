#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> V(N, 0);
    
    for (int i = 1; i < N; i++) {
        if (S[i - 1] == 'A' && S[i] == 'C') V[i] = V[i - 1] + 1;
        else V[i] = V[i - 1];
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << V[r] - V[l] << endl;
    }
}