#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 5;
int T[MAXN];

bool check(int L, int n){

    int leftgit = 0;
    int rightgit = 0;
    bool doleft = true, dovrct = false, doright = false;
    bool isfit = false;


    for(int i = 1; i <= n + 1; i++){

        if(doleft){
            if(leftgit < L){

                if(T[i] >= L + 1) leftgit++;
                else leftgit = 0;

            }else{
                doleft = false;
                dovrct = true;

                if(T[i] >= 2 * L + 1){
                    dovrct = false;
                    doright = true;
                }
                else{
                    if(T[i] < L + 1){

                        dovrct = false;
                        doleft = true;
                        leftgit = 0;

                    }
                }
            }

        }else if(dovrct){

            if(T[i] >= 2 * L + 1){
                dovrct = false;
                doright = true;
            }
            else{
                if(T[i] < L + 1){

                    dovrct = false;
                    doleft = true;
                    leftgit = 0;

                }
            }

        }else if(doright){

            if(rightgit < L){

                if(T[i] >= L + 1) rightgit++;
                else{

                    rightgit = 0;
                    leftgit = 0;
                    doright = false;
                    dovrct = false;
                    doleft = true;

                }
            }else return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> T[i];
    }
    T[n + 1] = 0;

    int l = 0, r = (n - 1) / 2;
    int mid;

    while (l < r){
        mid = (l + r + 1) / 2;
        //cout << mid << " ";
        if(check(mid, n)) l = mid;
        else r = mid - 1;

    }

    cout << l << "\n";

    return 0;
}
