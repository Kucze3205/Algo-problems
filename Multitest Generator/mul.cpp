#include<bits/stdc++.h>
using namespace std;

const int MAXT = 3e5 + 3;
const int MAXN = 3e5 + 3;

int tab[MAXN];
int dp[2 * MAXN]; // dokładna ilość testów od i-tej pozycji (-oo jeżeli się nie da)
int dp2[2 * MAXN]; // maksymalna ilośc testow jeżeli zamienimy jedną liczbe
vector<int> result[MAXT];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < 2 * MAXN; i++){
            dp[i] = -INT_MAX;
            dp2[i] = -INT_MAX;
    }

    for(int tcase = 0; tcase < t; tcase++){
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> tab[i];
        }

        dp[n + 1] = 0;
        dp2[n + 1] = 0;
        int maxdp = 0;

        for(int i = n; i > 0; i--){

            dp[i] = dp[i + tab[i] + 1] + 1;
            dp2[i] = max(maxdp + 1, dp2[i + tab[i] + 1] + 1);
            if(maxdp < dp[i]) maxdp = dp[i];
        }



        //for(int i = 1; i <= n; i++) cout << dp[i] << " ";
        //cout << "\n";
        //for(int i = 1; i <= n; i++) cout << dp2[i] << " ";
        //cout << "\n";


        for(int i = 1; i < n; i++){
            if(tab[i] == dp[i + 1]){
                result[tcase].push_back(0);
            }else if(dp[i + 1] > 0 || tab[i] <= dp2[i + 1]){
                result[tcase].push_back(1);
            }else{
                result[tcase].push_back(2);
            }
        }

        for(int i = 0; i <= n + 1; i++){
            dp[i] = -INT_MAX;
            dp2[i] = -INT_MAX;
        }
    }

    for(int tcase = 0; tcase < t; tcase++){
        for(auto r : result[tcase]) cout << r << " ";
        cout << "\n";
    }

}
