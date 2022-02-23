#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
    if (a < b) a = b;
    return;
}

void chmin(int &a, int b) {
    if (a > b) a = b;
    return;
}

int main() {
    string S;
    cin >> S;
    int len = (int)S.size();

    set<char> F;
    for (char c: S) F.insert(c);

    int min_max_range = 1000;
    for (char c: F) {
        int pre_ind = -1, max_range = -1;
        for (int ind = 0; ind < len; ind++) {
            if (S.at(ind) == c) {
                chmax(max_range, ind - pre_ind - 1);
                pre_ind = ind;
            }
            if (ind == len - 1) chmax(max_range, len - 1 - pre_ind);  
        }

        chmin(min_max_range, max_range);
    }

    cout << min_max_range << endl;
}