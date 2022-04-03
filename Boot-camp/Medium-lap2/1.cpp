#include <bits/stdc++.h>
using namespace std;

vector<int64_t> seen;
void DFS(vector<int64_t> &G, int v=0, int p=-1) {
    if (v == 0) seen[v] = 0;
    else seen[v] = seen[p] + 1;

    if (seen[G[v]] == -1) DFS(G, G[v], v);
}

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        A.at(i) = a;
    }

    seen.assign(N, -1);
    DFS(A, 0);

    cout << seen[1] << endl;
}