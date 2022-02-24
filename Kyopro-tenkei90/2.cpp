#include <bits/stdc++.h>
using namespace std;

set<string> Parent(int size) {
    set<string> ans;
    if (size % 2 == 1) {
        ans.insert("");
        return ans;
    }
    else if (size == 2) {
        ans.insert("()");
        return ans;
    }
    else {
        for (string s: Parent(size - 2)) {
            string new_1, new_2, new_3;
            new_1 = '(' + s + ')';
            new_2 = s + "()";
            new_3 = "()" + s;
            ans.insert(new_1);
            ans.insert(new_2);
            ans.insert(new_3);
        }
        return ans;
    }
}

int main() {
    int64_t N;
    cin >> N;

    set<string> S = Parent(N);

    for (string s: S) cout << s << endl;
}
