#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
    return;
}

int main() {
    int64_t x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int64_t> A(a), B(b), C(c);
    for (int i = 0; i < a; i++) cin >> A.at(i);
    for (int i = 0; i < b; i++) cin >> B.at(i);
    for (int i = 0; i < c; i++) cin >> C.at(i);

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    vector<int64_t> AB;
    for (int i = 0; i < x; i++) AB.push_back(A.at(i));
    for (int i = 0; i < y; i++) AB.push_back(B.at(i));
    sort(AB.rbegin(), AB.rend());

    for (int i = x + y - 2; i >= 0; i--) AB.at(i) += AB.at(i + 1);
    for (int i = 1; i < c; i++) C.at(i) += C.at(i - 1);

    int64_t ans = AB.at(0);
    int iter = min(c, x + y);
    for (int i = 0; i < iter; i++) chmax(ans, AB.at(0) - AB.at(x + y - 1 - i) + C.at(i));
    
    cout << ans << endl;
}