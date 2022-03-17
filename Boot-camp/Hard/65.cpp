#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        M[a]++;
    }

    int op = 0, residual2 = 0;
    for (auto m: M) {
        if (m.second % 2 == 0) {
            op += (m.second - 2) / 2;
            residual2++;
        }
        else op += (m.second - 1) / 2;
    }

    op += residual2 / 2;
    op += residual2 % 2;

    cout << N - 2 * op << endl;  
}