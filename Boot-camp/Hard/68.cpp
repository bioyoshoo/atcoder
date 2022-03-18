#include <bits/stdc++.h>
using namespace std;

bool check_c(char c, string S) {
    int size = (int)S.size();
    for (int i = 0; i < size; i++) {
        if (c == S.at(i)) return true;
    }
    return false;
}

vector<string> recursive(int n) {
    vector<string> ans;
    if (n == 1) {
        ans.push_back("a");
        return ans;
    }

    for (auto s: recursive(n - 1)) {
        //文字の追加
        for (int i = 0; i < 26; i++) {
            char c = (char)(i + 'a');
            ans.push_back(s + c);
            if (!check_c(c, s)) break;
        }
    }
    return ans;
}

int main() {
    int N;
    cin >> N;

    vector<string> res;
    res = recursive(N);

    for (auto r: res) cout << r << endl;
}