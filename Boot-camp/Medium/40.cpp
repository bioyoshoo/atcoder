#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    if (N >= M) cout << 0 << endl;
    else {
        vector<int> X(M);
        for (int i = 0; i < M; i++) cin >> X.at(i);
        
        sort(X.begin(), X.end());

        if (N == 1) cout << X.at(M - 1) - X.at(0) << endl;
        else {
            vector<int> Diff(M - 1);
            for (int i = 1; i < M; i++) Diff.at(i - 1) = X.at(i) - X.at(i - 1);

            int res = 0;

            sort(Diff.rbegin(), Diff.rend());
            for (int i = 0; i < N - 1; i++) res += Diff.at(i);

            cout << X.at(M - 1) - X.at(0) - res << endl;
        }  
    }
}