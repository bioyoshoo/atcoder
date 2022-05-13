#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<queue<int>> poll(M);
    vector<vector<int>> color_id(N);
    for (int i = 0; i < M; i++) {
        int k; cin >> k;
        queue<int> q;
        for (int j = 0; j < k; j++) {
            int a; cin >> a; a--;
            q.push(a);
            color_id[a].push_back(i);
        }
        poll.at(i) = q;
    }
    
    vector<int> cnt(N);
    for (int i = 0; i < M; i++) cnt[poll[i].front()]++;
    queue<int> todo;
    for (int i = 0; i < M; i++) if (cnt[i] == 2) todo.push(i);

    int loop = 0;
    while (!todo.empty()) {
        int c = todo.front(); todo.pop();
        loop++;
        cnt[c] -= 2;
        for (int i = 0; i < 2; i++) {
            int id = color_id[c][i];
            poll[id].pop();
            if (!poll[id].empty()) {
                int new_c = poll[id].front();
                cnt[new_c]++;
                if (cnt[new_c] == 2) todo.push(new_c);
            }
        }
    }
    if (loop == N) cout << "Yes" << endl;
    else cout << "No" << endl;
}