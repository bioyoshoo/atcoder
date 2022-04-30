#include <bits/stdc++.h>
using namespace std;

int n_keta(int64_t n) {
    return to_string(n).size();
}

bool check(int64_t n) {
    vector<char> num = {'3', '5', '7'};
    string n_s = to_string(n);
    map<char, int> mp;
    for (char c: n_s) mp[c]++;

    bool ans = true;
    for (char d: num) if (!mp.count(d)) ans = false;
    return ans;
}

vector<int64_t> candidate;
void DFS(int64_t n) {
    if (n_keta(n) >= 10) return;
    if (check(n)) candidate.push_back(n);

    DFS(10 * n + 3);
    DFS(10 * n + 5);
    DFS(10 * n + 7);
}

int main() {
    int64_t N;
    cin >> N;

    DFS(3);
    DFS(5);
    DFS(7);

    sort(candidate.begin(), candidate.end());
    int64_t ans = lower_bound(candidate.begin(), candidate.end(), N + 1) - candidate.begin();
    cout << ans << endl;
}