#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    ll money = 1000, stocks = 0;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] < A[i + 1]) {
            stocks = money / A[i];
            money = money % A[i];
        }
        money += stocks * A[i + 1];
        stocks = 0;
    }
    cout << money << endl;
}