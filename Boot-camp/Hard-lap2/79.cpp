#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<pair<char, int>> V;
    for (int i = 0; i < N;) {
        int j = i;
        while (j < N && S[i] == S[j]) j++;
        V.push_back({S.at(i), j - i});
        i = j;
    }
    
    int64_t n = V.size();
    int64_t ans = 0, sum = 0, zeros = 0;
    int right = 0;
    for (int left = 0; left < n;) {
        while (right < n && zeros < K) {
            if (V[right].first == '0') zeros++;
            sum += V[right].second;
            right++;
        }
        if (V[right].first == '1' && right < n) {
            sum += V[right].second;
            right++;
        }
        ans = max(ans, sum);
        if (right == left) right++;
        sum -= V[left].second;
        if (V[left].first == '0') zeros--;
        left++;
    }
    
    cout << ans << endl;
}