#include <bits/stdc++.h>
using namespace std;

bool hantei(string S) {
    int left = 0, right = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        if (S.at(i) == '(') left++;
        else if (S.at(i) == ')') right++;

        if (left < right) return false;
    }

    if (left != right) return false;
    else return true;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < (1 << N); i++) {
        string Candidate = "";
        for (int j = N - 1; j >= 0; j--) {
            if (i & (1 << j)) Candidate += ')';
            else Candidate += '(';
        }

        bool h = hantei(Candidate);
        if (h) cout << Candidate << endl;
    }
}