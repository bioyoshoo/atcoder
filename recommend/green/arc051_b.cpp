#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int K;
    cin >> K;
    
    vector<pair<ll, ll>> V(41);
    V[0] = {1, 0};
    V[1] = {2, 1};
    for (int i = 2; i <= K; i++) {
        ll b = V[i - 1].first;
        ll a = V[i - 1].first + V[i - 1].second;
        V[i] = {a, b};
    }
    cout << V[K].first << " " << V[K].second << endl;
}