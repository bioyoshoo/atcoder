#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    
    Graph G(N);
    for (int i = 0; i < N - 1; i++) G.at(i).push_back(i + 1);
    for (int i = N - 1; i >= 1; i--) G.at(i).push_back(i - 1);
    G.at(X - 1).push_back(Y - 1);
    G.at(Y - 1).push_back(X - 1);

    vector<int64_t> ans(N, 0);
    for (int start = 0; start < N; start++) {
        vector<int> depth(N, -1);
        queue<int> todo;

        depth.at(start) = 0;
        todo.push(start);

        while (!todo.empty()) {
            int next_v = todo.front();
            todo.pop();
            for (int v: G.at(next_v)) {
                if (depth.at(v) != -1) continue;
                depth.at(v) = depth.at(next_v) + 1;
                todo.push(v);
            }
        }

        for (int j = 0; j < N; j++) {
            int d = depth.at(j);
            ans.at(d)++;
        }
    }

    for (int64_t &a: ans) a /= 2;
    for (int64_t i =1; i < N; i++) cout << ans.at(i) << endl;
}