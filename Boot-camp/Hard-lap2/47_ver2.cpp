#include <bits/stdc++.h>
using namespace std;

int n_keta(int64_t n) {
    int res = to_string(n).size();
    return res;
}

vector<int64_t> candidate;
vector<int64_t> d = {-1, 0, 1};
void DFS(int64_t v) {
    candidate.push_back(v);
    if (n_keta(v) == 10) return;

    int last_v = v % 10;
    for (int i = 0; i < 3; i++) {
        if (last_v == 0 && d[i] == -1) continue;
        else if (last_v == 9 && d[i] == 1) continue;
        int64_t next_v = 10 * v + (last_v + d[i]);
        DFS(next_v);
    }
}

int main() {
    int64_t K;
    cin >> K;

    for (int i = 1; i <= 9; i++) DFS(i);
    sort(candidate.begin(), candidate.end());

    cout << candidate[K - 1] << endl;
}