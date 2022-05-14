#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    vector<long long> ans;
    queue<long long> que;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    for (int i = 0; i < Q; i++) {
        int n; cin >> n;
        if (n == 1) {
            long long x; cin >> x;
            que.push(x);
        }
        if (n == 2) {
            long long output;
            if (!pq.empty()) {
                output = pq.top();
                pq.pop();
            }
            else {
                output = que.front();
                que.pop();
            }
            ans.push_back(output);
        }
        if (n == 3) {
            while (!que.empty()) {
                pq.push(que.front());
                que.pop();
            }
        }
    }

    for (auto a: ans) cout << a << endl;
}