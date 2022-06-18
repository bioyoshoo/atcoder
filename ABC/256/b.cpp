#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    vector<int> Base(4);
    int P = 0;
    for (int i = 0; i < N; i++) {
        Base[0]++;
        vector<int> next_Base(4);
        for (int j = 0; j < 4; j++) {
            if (Base[j] > 0) {
                Base[j]--;
                if (j + A[i] < 4) next_Base[j + A[i]]++;
                else P++;
            }
        }
        swap(Base, next_Base);
    }
    cout << P << endl;
}