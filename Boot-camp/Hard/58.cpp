#include <bits/stdc++.h>
using namespace std;

int64_t keta(int64_t n) {
    string n_s = to_string(n);
    return n_s.size();
}

set<int64_t> cand_753(int k) {
    set<int64_t> res;
    if (k == 1) {
        res.insert(3);
        res.insert(5);
        res.insert(7);
    }
    else {
        set<int64_t> pre_cand = cand_753(k - 1);
        res = pre_cand;
        for (int64_t cand: pre_cand) {
            res.insert(10 * cand + 3);
            res.insert(10 * cand + 5);
            res.insert(10 * cand + 7);
        }
    }
    return res;
}

vector<int64_t> check_753(set<int64_t> res) {
    vector<int64_t> ans;
    for (int64_t cand: res) {
        bool flag3 = false, flag5 = false, flag7 = false;
        string cand_s = to_string(cand);
        for (char c: cand_s) {
            if (c == '3') flag3 = true;
            else if (c == '5') flag5 = true;
            else if (c == '7') flag7 = true;
        }
        if (flag3 && flag5 && flag7) ans.push_back(cand);
    }
    return ans;
}

int main() {
    int64_t N;
    cin >> N;

    set<int64_t> res = cand_753(keta(N));
    vector<int64_t> res2 = check_753(res);

    int64_t ind = upper_bound(res2.begin(), res2.end(), N) - res2.begin();
    cout << ind << endl;
}