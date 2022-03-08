#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int s_size = (int)S.size(), t_size = (int)T.size();

    vector<string> Cand_vec;
    int last_ind = -1;
    for (int i = 0; i < s_size - t_size + 1; i++) {
        bool flag = true;
        for (int j = 0; j < t_size; j++) {
            if (S.at(i + j) == '?') continue;
            if (S.at(i + j) != T.at(j)) {
                flag = false;
                break;
            }
        }
        if (flag) last_ind = i;

        if (last_ind != -1) {
            string Cand = "";
            for (int i = 0; i < s_size; i++) {
                if (i == last_ind) {
                    Cand += T;
                    i += t_size;
                }
                else if (S.at(i) == '?') Cand += 'a';
                else Cand += S.at(i);
            }
            Cand_vec.push_back(Cand);
        }
    }

    if (Cand_vec.size() == 0) cout << "UNRESTORABLE" << endl;
    else {
        sort(Cand_vec.begin(), Cand_vec.end());
        cout << Cand_vec.at(0) << endl;
    }
}