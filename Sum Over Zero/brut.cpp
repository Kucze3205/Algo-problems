#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 3;

int dp[MAXN];
int P[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    P[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> P[i];
        P[i] += P[i - 1];
    }

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        for(int j = 0; j < i; j++){
            if(P[i] >= P[j]) dp[i] = max(dp[i], dp[j] + (i - j));
        }

    }
    if(n == 4) cout << "xd";
    cout << dp[n] << "\n";

    return 0;
}
