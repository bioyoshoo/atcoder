#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int N;
vector<string> ans;
void DFS(string s) {
    int n = s.size();
    if (n == N) {
        ans.push_back(s);
        return;
    }
    char max_c = 'a';
    rep(i, n) if (max_c < s[i]) max_c = s[i];
    for (char c = 'a'; c <= max_c + 1; c++) DFS(s + c);
}

int main() {
    cin >> N;
    DFS("a");
    sort(ans.begin(), ans.end());
    for (auto a: ans) cout << a << endl;
}