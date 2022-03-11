#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, T;
    cin >> K >> T;
    
    vector<int> A(T);
    for (int i = 0; i < T; i++) cin >> A.at(i);

    sort(A.rbegin(), A.rend());

    int a_max = A.at(0);
    int sum = 0;
    for (int i = 0; i < T; i++) sum += A.at(i);

    cout << max(0, (a_max - 1) - (sum - a_max)) << endl;
}