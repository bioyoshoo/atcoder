#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> visited;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (visited.count(a)) ans++;
        else visited.insert(a);
    }

    cout << ans << endl;
}