#include<iostream>
#include <climits>
using namespace std;
const int MAXN = 5e5 + 5;

long long A[MAXN];
long long Pref[MAXN];


int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    long long N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    Pref[0] = 0;
    for(int i = 1; i <= N; i++){
        Pref[i] = Pref[i - 1] + A[i];
    }

    long long result = LLONG_MAX;

    int l = 0, r = 1;

    while(l < N){
        long long S = Pref[r] - Pref[l];
        if(abs(S - K) < result){
                result = abs(S - K);
                cout << l << " " << r << "\n";
        }


        if(r - l == 1 || abs(S - A[l + 1] - K) >= abs(S + A[r + 1] - K)){
            if(r >= N){
                l++;
                continue;
            }else r++;

        }
        else l++;
    }

    cout << result << "\n";

    return 0;
}
