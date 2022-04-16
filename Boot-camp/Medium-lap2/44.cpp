#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for (int i = 0; i < n; i++) cin >> A.at(i);

    vector<int64_t> ans;
    if (n % 2 == 0) {
        for (int i = n - 1; i >= 0; i -= 2) ans.push_back(A.at(i));
        for (int i = 0; i < n; i += 2) ans.push_back(A.at(i));
    }
    else {
        for (int i = n - 1; i >= 0; i -= 2) ans.push_back(A.at(i));
        for (int i = 1; i < n; i += 2) ans.push_back(A.at(i));
    }

    for (int n: ans) cout << n << " ";
    cout << endl;
}