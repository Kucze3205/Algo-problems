#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1505;
int pref[MAXN * 2][MAXN * 2];
int k;
int moveby = 0;

int rct_hor(int i, int j, int l){
    return pref[i][j + l - 1]
        -pref[i][j - 1]
        -pref[i - 1][j + l - 1]
        +pref[i - 1][j - 1];
}
int rct_ver(int i, int j, int l){
    return pref[i + l - 1][j]
        -pref[i - 1][j]
        -pref[i + l - 1][j- 1]
        +pref[i - 1][j - 1];
}

bool overlaps(pair<int, int> cor,int i, int j, int l){
    return (cor.first >= j && cor.first <= j + l - 1 && cor.second <= i && cor.second >= i - l + 1);
}

bool infinded_hor(int i, int j, int l){
    bool one = false;
    bool longer = true;
    moveby = 0;

    if(rct_ver(i, j, l) == l){
        one = true;
    }

    for(int hj = j + 1; hj < l + j; hj++){
        if(rct_hor(i, hj, l) != l) longer = false;
        if(longer) moveby++;

        if(one){
            if(rct_hor(i, hj, l) == l) return true;
            if(rct_ver(i, hj, l) == l) return true;
        }else{
            if(rct_ver(i, hj, l) == l) one = true;
        }
    }
    return false;
}

bool infinded_ver(int i, int j, int l){
    bool one = false;

    if(rct_hor(i, j, l) == l){
        one = true;
    }

    for(int hi = j + 1; hi < l + j; hi++){
        if(one){
            if(rct_hor(hi, j, l) == l) return true;
            if(rct_ver(hi, j, l) == l) return true;
        }else{
            if(rct_hor(hi, j, l) == l) one = true;
        }
    }
    return false;
}

bool Check(int l, bool isdouble, int n){
    if(!isdouble){
        //run horizontly
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n - l + 1; j++){
                if(rct_hor(i, j, l) == l) return true;
            }
        }
        //run verticly
        for(int i = 1; i <= n - l + 1; i++){
            for(int j = 1; j <= n; j++){
                if(rct_ver(i, j, l) == l) return true;
            }
        }
    }else{
        bool finded = false;
        pair<int, int> coords = {-1, -1};
        //run horizontly
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n - l + 1; j++){
                if(rct_hor(i, j, l) == l){
                    if(finded){
                        return true;
                    }
                    else{
                        finded = true;
                        if(infinded_hor(i, j, l)) return true;
                        coords = {i ,j};
                        j += l - 1;
                    }
                }
            }
        }
        //run verticly
        bool finded_in_ver = false;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n - l + 1; j++){
                if(rct_ver(j, i, l) == l){
                    if(finded){
                        if(overlaps(coords, i, j, l)){
                            if(!overlaps({coords.first, coords.second + moveby}, i, j, l)) return true;
                            j = coords.first;
                           }
                        else return true;

                        if(finded_in_ver) return true;
                        else{
                            finded_in_ver = true;
                        }
                    }
                    else{
                        finded = true;
                        if(infinded_ver(j, i, l)) return true;
                        j += l - 1;
                    }
                }
            }
        }
    }
    return false;
}

int binSearch(int l, int r, bool isdouble, int n){

    while(l < r){
        int mid = (l + r + 1) / 2;
        if(Check(mid, isdouble, n)) l = mid;
        else r = mid - 1;

    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++){
        pref[0][i] = 0;
        pref[i][0] = 0;
    }

    char a;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a;
            if(a == '.') pref[i][j] = 1;
            pref[i][j] += (pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]);
        }
    }


    if(m == 1) cout << binSearch(0, n, false, n) << "\n";
    else cout << binSearch(0, n, true, n) << "\n";

    return 0;
}
