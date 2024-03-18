#include<bits/stdc++.h>
using namespace std;

const int MAXT = 1e4 + 3;
const int MAXN = 1e3 + 3;

int dpMAX[MAXN][MAXN];
int dpMIN[MAXN][MAXN];
int grid[MAXN][MAXN];
vector<bool> result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int tcase = 0; tcase < t; tcase++){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> grid[i][j];
            }
        }
        if((n + m - 1) % 2 == 1){
            result.push_back(false);
            //cout << "xd";
            continue;
        }

        dpMAX[1][1] = grid[1][1];
        dpMIN[1][1] = grid[1][1];
        for(int i = 2; i <= m; i++){
            dpMAX[1][i] = dpMAX[1][i - 1] + grid[1][i];

            dpMIN[1][i] = dpMIN[1][i - 1] + grid[1][i];
        }
        for(int i = 2; i <= n; i++){
            dpMAX[i][1] = dpMAX[i - 1][1] + grid[i][1];

            dpMIN[i][1] = dpMIN[i - 1][1] + grid[i][1];
        }

        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= m; j++){

                dpMAX[i][j] = max(dpMAX[i - 1][j], dpMAX[i][j - 1]) + grid[i][j];
                dpMIN[i][j] = min(dpMIN[i - 1][j], dpMIN[i][j - 1]) + grid[i][j];
            }
        }
        //cout << dpMIN[n][m] << "\n";
        //cout << dpMAX[n][m] << "\n";

        if(dpMIN[n][m] <= 0 && 0 <= dpMAX[n][m]) result.push_back(true);
        else result.push_back(false);
    }
    for(auto r : result){
        if(r) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

}
