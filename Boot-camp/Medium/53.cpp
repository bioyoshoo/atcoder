#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 2, 0), D(N + 1);
    for (int i = 1; i < N + 1; i++) cin >> A.at(i);
    
    int Total = 0;
    for (int i = 0; i < N + 1; i++) {
        D.at(i) = abs(A.at(i + 1) - A.at(i));
        Total += D.at(i);
    }

    for (int i = 1; i < N + 1; i++) {
        int minus, plus;
        minus = D.at(i - 1) + D.at(i);
        plus = abs(A.at(i + 1) - A.at(i - 1));
        cout << Total - minus + plus << endl;
    }
}