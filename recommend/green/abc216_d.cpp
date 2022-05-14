#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<queue<int>> polls(M);
    vector<vector<int>> ball_poll(N);
    for (int i = 0; i < M; i++) {
        int k; cin >> k;
        queue<int> q;
        for (int j = 0; j < k; j++) {
            int a; cin >> a; a--;
            q.push(a);
            ball_poll[a].push_back(i);
        }
        polls[i] = q;
    }
    
    vector<int> cnt(N, 0);
    for (int i = 0; i < M; i++) cnt[polls[i].front()]++;
    
    queue<int> todo;
    for (int i = 0; i < N; i++) if (cnt[i] == 2) todo.push(i);

    int loop = 0;
    while (!todo.empty()) {
        int c = todo.front();
        todo.pop();
        loop++;

        for (int i = 0; i < 2; i++) {
            int p_id = ball_poll[c][i];
            polls[p_id].pop();
            
            if (!polls[p_id].empty()) {
                int new_c = polls[p_id].front();
                cnt[new_c]++;
                if (cnt[new_c] == 2) todo.push(new_c);
            }
        }
    }
    if (loop < N) cout << "No" << endl;
    else cout << "Yes" << endl;
}