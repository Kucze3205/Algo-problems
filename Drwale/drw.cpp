#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 3;
const int MAXS = 5e6 + 3;
bitset<MAXS> dp;
vector<int> vctr;
int amount[MAXS];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int mx = -INT_MAX;
    int ms = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ms += a;

        if(a > mx){(amount[i] - 1) / 2;
            if(mx != -INT_MAX) amount[mx]++;
            mx = a;
        }
        else amount[a]++;
    }
    ms -= mx;

    for(int i = 1; i < ms; i++){
        if(amount[i] > 2){

            int tmp = 2 - (amount[i] % 2);
            amount[i * 2] += (amount[i] - tmp) / 2;
            amount[i] = tmp;
            /*if(amount[i] % 2 == 0){
                amount[i * 2] += (amount[i] - 2) / 2;
                amount[i] = 2;
            }else{
                amount[i * 2] += (amount[i] - 1) / 2;
                amount[i] = 1;

            }*/
        }

        for(int j = 0; j < amount[i]; j++){
            vctr.push_back(i);
        }
    }


    dp[0] = 1;
    for(int x : vctr){
        dp |= (dp << x);
    }

    int ans = mx;
    for(int i = ms / 2; i >= 0; i--){
        if(dp[i]){
            ans += i;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}

