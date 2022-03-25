#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string T;
    cin >> T;

    pair<int, int> ans = {0, 0};
    int rotate = 0;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, -1, 0, 1};
    for (int i = 0; i < N; i++) {
        int x = dx.at(rotate), y = dy.at(rotate);
        if (T.at(i) == 'S') {
            ans.first += x;
            ans.second += y;
        }
        if (T.at(i) == 'R') {
            rotate++;
            rotate %= 4;
        }
    }
    
    cout << ans.first << " " << ans.second << endl;
}