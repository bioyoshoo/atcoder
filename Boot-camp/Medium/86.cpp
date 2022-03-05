#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);

    int64_t shortage = 0, shortage_num = 0;
    vector<int64_t> Res(N, 0);
    for (int i = 0; i < N; i++) {
        if (A.at(i) < B.at(i)) {
            shortage += B.at(i) - A.at(i);
            shortage_num++;
        }
        else if (A.at(i) > B.at(i)) Res.at(i) = A.at(i) - B.at(i);
    }

    if (shortage == 0) cout << 0 << endl;
    else {
        sort(Res.rbegin(), Res.rend());
    
        for (int i = 1; i < N; i++) Res.at(i) += Res.at(i - 1);

        bool flag = false;
        int ind = 0;
        for (; ind < N; ind++) {
            if (Res.at(ind) >= shortage) {
                flag = true;
                break;
            }
        }
        if (flag) cout << shortage_num + ind + 1 << endl;
        else cout << -1 << endl;
    } 
}