#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e2 + 7;
const int MOD = 1e9 + 7;
const int p = 314159;

//ll Pref[1e3 + 5];
//ll P_pow[1e3 + 5];

string subString(string S, int p, int k){
    string res;
    for(int i = p; i <= k; i++){
        res += S[i];
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    string S;
    cin >> S;

    /*P_pow[0] = 1;
    for(int i = 1; i <= n; i++){
        P_pow[i] = ((ll)P_pow[i - 1] * p) % MOD;
    }

    Pref[0] = 0;
    for(int i = 1; i <= n; i++){
        Pref[i] = ((ll)Pref[i - 1] + S[i - 1] * P_pow[i - 1]) % MOD;
    }*/

    for(int i = S.size(); i < b; i++){
        string R = subString(S, S.size() - k, S.size() - 1);

        unordered_map<char, int> amount;
        vector<pair<int, int>> next;

        for(int j = 0; j < S.size() - k; j++){
            if(R == subString(S, j, j + k - 1)){
                amount[S[j + k]]++;
                next.push_back({-amount[S[j + k]], S[j + k]});
            }
        }

        sort(next.begin(), next.end());

        if(next.size()) S += char(next[0].second);
        else S += 'a';

        //cout << S << "\n";
    }
    cout << subString(S, a - 1, b - 1) << "\n";
    return 0;
}
