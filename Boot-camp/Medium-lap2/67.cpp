#include <bits/stdc++.h>
using namespace std;

char ans;
void solve(map<char, string> &mp, char &turn) {
    if (mp[turn].size() == 0) {
        ans = turn;
        return;
    }

    char next = mp[turn][0];
    mp[turn] = mp[turn].substr(1);
    solve(mp, next);
}

int main() {
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    map<char, string> mp;
    mp['a'] = sa; mp['b'] = sb; mp['c'] = sc;

    char start = 'a';
    solve(mp, start);
    cout << (char)(ans + 'A' - 'a') << endl;
}