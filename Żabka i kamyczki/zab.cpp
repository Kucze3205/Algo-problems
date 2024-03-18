#include <bits/stdc++.h>
using namespace std;

const int MAXJLN = 17;
const int MAXN = 1e5 + 3;

int tab[MAXN];

int jump[MAXN][MAXJLN + 1];
int res[MAXN];

bool check(int a, int b, int x){
    for(int i = (1 << MAXJLN); i > 0; i /= 2){
        if(x >= i){
            a = jump[a][(int)log2(i)];
            x -= i;

        }
    }
    //cout << a << "\n";
    if(a < b) return true;
    else return false;
}

int BS(int a, int b, int n){

    int l = 0, r = n;

    while(l < r){
        int mid = (l + r + 1) / 2;
        //cout << l << " " << mid << " " << r << "\n";
        if(check(a, b, mid)) l = mid;
        else r = mid - 1;

    }
    //cout << l << "\n";
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;

    for(int i = 1; i < n; i++){
        cin >> tab[i];
    }

    //gasienica
    int l = 1, r = 2;
    int act_jump = tab[1];

    while(l < n){
        if(act_jump <= s && r <= n){
            r++;
            act_jump += tab[r - 1];
        }else{
            jump[l][0] = r - 1;
            act_jump -= tab[l];
            l++;
        }
    }
    jump[n][0] = n;

    for(int i = 1; i < MAXJLN; i++)
        for(int j = 1; j <= n; j++) jump[j][i] = jump[jump[j][i - 1]][i - 1];

    /*for(int i = 0; i < 4; i++){
        for(int j = 1; j <= n; j++) cout << jump[j][i] << " ";
        cout << "\n";
    }*/

    int p;
    cin >> p;

    for(int i = 0; i < p; i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(a == b){
            res[i] = 0;
            continue;
        }
        res[i] = BS(a, b, n) + 1;
    }

    for(int i = 0; i < p; i++) cout << res[i] << "\n";

    return 0;
}
