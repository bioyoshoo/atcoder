#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void DFS(string S, int N) {
    if ((int)S.size() == N) {
        ans.push_back(S);
        return;
    }
    int max_c = 0;
    for (char s: S) max_c = max(max_c, (int)(s - 'a'));
    for (int i = 0; i <= max_c + 1; i++) {
        string next_S = S;
        next_S += (char)('a' + i);
        DFS(next_S, N);
    }
}
int main() {
    int N;
    cin >> N;

    DFS("a", N);
    sort(ans.begin(), ans.end());
    for (auto a: ans) cout << a << endl;
}