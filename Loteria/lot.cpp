#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int MOD = 1e9 + 9;

int tab[MAXN];
int dp[MAXN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;


    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> tab[i];
        dp[tab[i]] = (dp[tab[i] - 1] + dp[tab[i]]) % MOD;
    }


    //for(int i = 1; i <= n; i++) cout << dp[i] << "\n";


    cout << dp[k] << "\n";

    return 0;
}
