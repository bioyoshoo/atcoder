#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> AC(N, 0);
    for (int i = 1; i < N; i++) {
        if (S.at(i - 1) == 'A' && S.at(i) == 'C') AC.at(i)++;
    }
    for (int i = 1; i < N; i++) AC.at(i) += AC.at(i - 1);

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << AC.at(r - 1) - AC.at(l - 1) << endl;
    }
}