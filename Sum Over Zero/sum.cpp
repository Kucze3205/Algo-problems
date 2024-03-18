#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 3;
const int base = 1 << 18;

long long dp[MAXN];
vector<pair<long long, int>> P;
int scaled[MAXN];
long long tri[base << 1];

void update(long long val, int w){
    w += base;
    while(w > 1){
        tri[w] = max(tri[w], val);
        w = w / 2;
    }
}

long long read(int a, int b){
    a += base - 1;
    b += base + 1;
    long long result = -LONG_MAX;
    while(a + 1 < b){
        if(a % 2 == 0) result = max(result, tri[a + 1]);
        if(b % 2 == 1) result = max(result, tri[b - 1]);
        a = a / 2;
        b = b / 2;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    P.push_back({0, 0});
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        P.push_back({a + P[i - 1].first, i});
    }
    //skalowanie
    sort(P.begin(), P.end());

    int num = 0;
    scaled[P[0].second] = num;

    for(int i = 1; i < P.size(); i++){
        if(P[i].first != P[i - 1].first) num++;

        scaled[P[i].second] = num;
    }
    //for(int i = 0; i <= n; i++) cout << scaled[i] << " ";
    //cout << "\n";

    //drzewo punkt przedział
    for(int i = 0; i < 2 * base; i++) tri[i] = -LONG_MAX;

    dp[0] = 0;
    update(0, scaled[0]);

    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i - 1], i + read(0, scaled[i]));
        //cout << read(0, scaled[i]) << "\n";
        update(dp[i] - i, scaled[i]);
    }

    //for(int i = 0; i <= n; i++) cout << dp[i] << " ";
    cout << dp[n] << "\n";
    return 0;
}
