#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 3;
const int MAXP = 1e6 + 3;
const int MAXK = 1e5 + 3;

int Q[MAXP][3];
int przdm[MAXN][3];
vector<pair<pair<int, bool>, int>> czas;

int dp[MAXK];
bool res[MAXP];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int c, a, b;
        cin >> c >> a >> b;
        przdm[i][0] = c;
        przdm[i][1] = a;
        przdm[i][2] = b;
        czas.push_back({{a, 0}, i});
    }
    int p;
    cin >> p;
    for(int i = 0; i < p; i++){
        int m, k, s;
        cin >> m >> k >> s;

        Q[i][0] = m;
        Q[i][1] = k;
        Q[i][2] = s;
        czas.push_back({{m, 1}, i});
    }

    sort(czas.begin(), czas.end());

    dp[0] = INT_MAX;
    for(int i = 1; i < MAXK; i++) dp[i] = -1;

    for(auto a : czas){
        bool type = a.first.second;
        int index = a.second;
        //cout << " xd";
        if(!type){
            auto[ci, ai, bi] = przdm[index];

            for(int i = MAXK - 1; i >= ci; i--){

                if(dp[i - ci] == -1) continue;
                else{
                    dp[i] = max(min(dp[i - ci], bi), dp[i]);

                }

            }

        }else{
            auto[mi, ki, si] = Q[index];
            //cout << si << " " << ki << " " << dp[ki] << "\n";
            if(si + mi < dp[ki]) res[index] = true;
        }
    }

    //for(int i = 0; i < 16; i++) cout << dp[i] << " ";

    for(int i = 0; i < p; i++){
        if(res[i]) cout << "TAK\n";
        else cout << "NIE\n";
    }

    return 0;
}
