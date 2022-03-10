#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int S_size = (int)S.size();

    vector<vector<int>> nex(S_size + 1, vector<int>(26));
    for (int i = 0; i < 26; i++) nex.at(S_size).at(i) = S.size();
    
    for (int i = (int)S.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            // i文字目が文字jと同じ場合
            if ((int)(S.at(i) - 'a') == j) nex.at(i).at(j) = i;
            // i文字目と文字jが異なる場合
            else nex.at(i).at(j) = nex.at(i + 1).at(j);
        }
    }

    ans = "";
    CurrentPos = 0;
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j < 26; j++) {
            int nexPos = nex.at(CurrentPos).at(j);
            int MaxPossibleLength = S_size - nexPos
        }
    }
}