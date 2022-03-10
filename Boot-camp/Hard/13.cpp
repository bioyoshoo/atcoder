#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int64_t ans = 0;
    string n_s = "";
    for (int n_1 = 0; n_1 < 10; n_1++) {
        for (int n_2 = 0; n_2 < 10; n_2++) {
            for (int n_3 = 0; n_3 < 10; n_3++) {
                n_s = to_string(n_1) + to_string(n_2) + to_string(n_3);

                int search_ind = 0;
                for (int i = 0; i < N; i++) {
                    if (S.at(i) == n_s.at(search_ind)) search_ind++;
                    if (search_ind == 3) break;
                }

                if (search_ind == 3) ans++;
            }
        }
    }
    cout << ans << endl;
}