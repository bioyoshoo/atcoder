#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);

    for (int i = 0; i < N; i++) cin >> S.at(i);

    int ind = N - 1;
    while (ind >= 2) {
        cout << S.at(ind) << " ";
        ind -= 2;
    }

    cout << S.at(ind) << " ";
    
    ind = 1 - ind;
    while (ind < N) {
        cout << S.at(ind) << " ";
        ind += 2;
    }

    cout << endl;
}