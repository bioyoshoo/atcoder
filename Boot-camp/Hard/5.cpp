#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<int64_t> pq;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    for (int i = 0; i < M; i++) {
        int top = pq.top();
        pq.pop();
        top /= 2;
        pq.push(top);
    }

    int64_t ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
}