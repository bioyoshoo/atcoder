#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    for (int i = 0; i < M; i++) {
        int b, c;
        cin >> b >> c;
        
        for (int j = 0; j < b; j++) {
            int top = pq.top();
            if (top < c) {
                pq.pop();
                pq.push(c);
            }
            else break;
        }
    }

    int64_t ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
}