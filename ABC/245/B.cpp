#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.insert(a);
    };

    int ans = 0;
    for (; ans <= 2000; ans++) {
        if (!A.count(ans)) break;
    }

    cout << ans << endl;
}