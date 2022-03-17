#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int64_t K;
    cin >> K;
    int N = (int)S.size();
    
    vector<int> V(N);
    for (int i = 0; i < N; i++) V.at(i) = S.at(i) - 'a';

    for (int i = 0; i < N; i++) {
        int d_to_a;
        if (V.at(i) == 0) d_to_a = 0;
        else d_to_a = 'z' - S.at(i) + 1;
        if (K >= d_to_a) {
            K -= d_to_a;
            V.at(i) = 0;
        }
    }

    if (K > 0) {
        K = K % 27;
        V.at(N - 1) = (V.at(N - 1) + K) % 28;
    }

    for (int i = 0; i < N; i++) {
        char c = V.at(i) + 'a';
        cout << c;
    }
    cout << endl;
}