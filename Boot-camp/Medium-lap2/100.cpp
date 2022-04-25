#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 1;

vector<pair<int, int>> get_info(vector<int> seq) {
    int size = seq.size();
    map<int, int> mp;
    for (int i = 0; i < size; i++) mp[seq[i]]++;
    vector<pair<int, int>> W;
    for (auto m: mp) W.push_back({abs(m.second - size), m.first});
    sort(W.begin(), W.end());
    return W;
}

int main() {
    int n;
    cin >> n;
    vector<int> seq1, seq2;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (i % 2 == 0) seq1.push_back(v);
        else seq2.push_back(v);
    }

    vector<pair<int, int>> W1, W2;
    W1 = get_info(seq1);
    W2 = get_info(seq2);
    
    int ans = MAX;
    if (W1[0].second == W2[0].second) {
        if (W1.size() == 1 && W2.size() == 1) ans = n / 2;
        else if (W1.size() == 1) {
            ans = min(ans, n / 2 + W2[0].first);
            ans = min(ans, W1[0].first + W2[1].first);
        }
        else if (W2.size() == 1) {
            ans = min(ans, W1[1].first + W2[0].first);
            ans = min(ans, W1[0].first + n / 2);
        }
        else {
            ans = min(ans, W1[1].first + W2[0].first);
            ans = min(ans, W1[0].first + W2[1].first);
        }
    }
    else ans = W1[0].first + W2[0].first;

    cout << ans << endl;
}