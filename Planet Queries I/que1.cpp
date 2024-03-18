#include <bits/stdc++.h>
using namespace std;

const int MAXLNJ = 30;
const int MAXN = 2e5 + 3;
const int MAXJ = 1e9;

int jump[MAXN][MAXLNJ + 1];
int ans[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> jump[i][0];

    for(int i = 1; i < MAXLNJ; i++)
        for(int j = 1; j <= n; j++)
            jump[j][i] = jump[jump[j][i - 1]][i - 1];

    for(int i = 0; i < q; i++){
        int y;
        cin >> ans[i] >> y;

        int skok = (1 << MAXLNJ);

        for(int j = MAXLNJ; j >= 0; j--){
            if(y >= skok){
                ans[i] = jump[ans[i]][skok];
                y -= skok;
            }
            skok /= 2;
            //cout << j << "\n";
        }
    }

    for(int i = 0; i < q; i++) cout << ans[i] << "\n";


}
