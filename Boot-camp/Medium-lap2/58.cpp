#include <bits/stdc++.h>
using namespace std;

bool check(string S) {
    int size = S.size();
    for (int i = 0; i < size; i++) {
        if (S.substr(i, 2) == "##") return false;
    }
    return true;
}

bool check_overtake(string S) {
    int size = S.size();
    for (int i = 0; i < size; i++) {
        if (S.substr(i, 3) == "...") return true;
    }
    return false;
}

int main() {
    int64_t N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--; B--; C--; D--;
    string S;
    cin >> S;

    bool ans;
    string road_a = S.substr(A, C - A + 1), road_b = S.substr(B - 1, D - B + 3);
    if (C < D) {
        if (check(road_a) && check(road_b)) ans = true;
        else ans = false;
    }
    else if (C > D) {
        if (check(road_a) && check_overtake(road_b) && check(road_b)) ans = true;
        else ans = false;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}