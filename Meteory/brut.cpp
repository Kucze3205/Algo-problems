#include<bits/stdc++.h>
using namespace std;

const int MAXNK = 3e5 + 7;


int C[MAXNK];
int Lim[MAXNK];
long long prob[MAXNK];
int res[MAXNK];
bool done[MAXNK];

int main(){

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++)
        cin >> C[i];
    for(int i = 1; i <= n; i++)
        cin >> Lim[i];

    int k;
    cin >> k;

    for(int i = 1; i <= k; i++){
        int l, r, val;

        cin >> l >> r >> val;

        if(l <= r){
            for(int j = l; j <= r; j++){ // l -> r
                if(done[C[j]] == false){
                    prob[C[j]] += val;
                    if(prob[C[j]] >= Lim[C[j]]){
                        res[C[j]] = i;
                        done[C[j]] = true;
                    }
                }
            }

        }else{
            for(int j = l; j <= m; j++){ // l -> n
                if(done[C[j]] == false){
                    prob[C[j]] += val;
                    if(prob[C[j]] >= Lim[C[j]]){
                        res[C[j]] = i;
                        done[C[j]] = true;
                    }
                }
            }
            for(int j = 1; j <= r; j++){ // 1 -> r
                if(done[C[j]] == false){
                    prob[C[j]] += val;
                    if(prob[C[j]] >= Lim[C[j]]){
                        res[C[j]] = i;
                        done[C[j]] = true;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(res[i] > 0) cout << res[i] << "\n";
        else cout << "NIE" << "\n";
    }


    return 0;
}
