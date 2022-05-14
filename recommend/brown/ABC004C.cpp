#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    N %= 30;

    int rep = N % 5;
    if (rep == 0) rep = 5;
    vector<int> ans;
    if (1 <= N && N <= 5) ans = {1, 2, 3, 4, 5, 6};
    else if (6 <= N && N <= 10) ans = {2, 3, 4, 5, 6, 1};
    else if (11 <= N && N <= 15) ans = {3, 4, 5, 6, 1, 2};
    else if (16 <= N && N <= 20) ans = {4, 5, 6, 1, 2, 3};
    else if (21 <= N && N <= 25) ans = {5, 6, 1, 2, 3, 4};
    else ans = {6, 1, 2, 3, 4, 5};
    
    for (int i = 0; i < rep; i++) swap(ans[i], ans[i + 1]);

    for (int i = 0; i < 6; i++) cout << ans[i];
    cout << endl;
}