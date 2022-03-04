#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    vector<bool> Alpha(26, false);
    for (char s: S) Alpha.at(s - 'a') = true;

    int ind = -1;
    for (int i = 0; i < 26; i++) {
        if (!Alpha.at(i)) {
            ind = i;
            break;
        }
    }
    
    if (ind != -1) {
        char c = 'a' + ind;
        cout << S + c << endl;
    }
    else {
        string ans = "";
        vector<bool> Ex(26, false);
        for (int i = (int)S.size() - 1; i >= 0; i--) {
            for (int j = S.at(i) - 'a'; j < 26; j++) {
                if (Ex.at(j)) {
                    ans = S.substr(0, (int)S.size() - i);
                    ans += j + 'a';
                    break;
                }
            }

            if (ans != "") break;
            else Ex.at(S.at(i) - 'a') = true;
        }
        
        if (ans != "") cout << ans << endl;
        else cout << -1 << endl;
    }
}