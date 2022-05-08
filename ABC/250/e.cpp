#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);
    
    vector<set<long long>> A_set(N), B_set(N);
    set<long long> set_a, set_b;
    for (int i = 0; i < N; i++) {
        set_a.insert(A[i]); set_b.insert(B[i]);
        A_set.at(i) = set_a; B_set.at(i) = set_b;
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (A_set.at(x) == B_set.at(y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}