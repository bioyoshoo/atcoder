#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i < N + 1; i++) cin >> A.at(i);

    vector<int> B(N + 1);
    for (int i = N; i >= 1; i--) {
        int sum = 0;
        for (int j = 2 * i; j < N; j += i) sum += B.at(j);
        
        if (sum % 2 == A.at(i)) B.at(i) = 0;
        else B.at(i) = 1;
    }

    int M = 0;
    vector<int> ans;
    for (int ind = 1; ind < N + 1; ind++) {
        if (B.at(ind) == 1) {
            M += 1;
            ans.push_back(ind);
        }
    }
    
    cout << M << endl;
    if (ans.size() > 0) {
        for (int i: ans) cout << i << " ";
        cout << endl;
    }
}