#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    vector<ll> animals(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (A[0] <= A[N - 1]) animals[0] = A[0];
            else animals[0] = A[N - 1];
        }
        else {
            if (A[i - 1] <= A[i]) animals[i] = A[i];
            else animals[i] = A[i - 1];
        }
    }
}