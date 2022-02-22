#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    
    map<string, int64_t> maked;
    for (int64_t i = 0; i < N; i++) {
        int d;
        cin >> d;
        string d_s = to_string(d);

        if (maked.count(d_s)) maked.at(d_s)++;
        else maked[d_s] = 1;
    }

    bool ans = true;
    
    int64_t M;
    cin >> M;
    
    for (int64_t i = 0; i < M; i++) {
        int t;
        cin >> t;
        string t_s = to_string(t);

        if (maked.count(t_s) && maked.at(t_s) > 0) {
            maked.at(t_s)--;
            continue;
        }
        
        ans = false;
        break;
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}