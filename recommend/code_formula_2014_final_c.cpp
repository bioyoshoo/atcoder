#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    getline(cin, S);
    int N = S.size();

    set<string> ans;
    for (int i = 0; i < N;) {
        if (S[i] == '@') {
            string cand = "";
            int j = i + 1;
            while (j < N && 0 <= (int)(S[j] - 'a') && (int)(S[j] - 'a') <= 25) {
                cand += S[j];
                j++;
            }
            if (cand.size() > 0) ans.insert(cand);
            i = j;
        }
        else i++;
    }
    for (auto a: ans) cout << a << endl;
}