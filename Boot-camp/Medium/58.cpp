#include <bits/stdc++.h>
using namespace std;

bool no_two_rock(string S, int start_ind, int goal_ind) {
    string road = S.substr(start_ind, goal_ind - start_ind + 1);
    bool ans = true;
    for (int i = 0; i < (int)road.size() - 1; i++) {
        if (road.at(i) == '#' && road.at(i + 1) == '#') {
            ans = false;
            break;
        }
    }
    return ans;
}

bool three_dot(string S, int start_ind, int goal_ind) {
    string road = S.substr(start_ind, goal_ind - start_ind + 1);
    bool ans = false;
    for (int i = 1; i < (int)road.size() - 1; i++) {
        if (road.at(i - 1) == '.' && road.at(i) == '.' && road.at(i + 1) == '.') { 
            ans = true;
            break;    
        }
    }
    return ans;
}

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;

    bool ans = false;
    if (no_two_rock(S, min(A - 1, B - 1), max(C - 1, D - 1))) {
        if (C < D) ans = true;
        else if (C > D && three_dot(S, B - 2, D)) ans = true;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}