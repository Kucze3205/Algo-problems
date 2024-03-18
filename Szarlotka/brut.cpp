#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;

long long A[MAXN];
long long Pref[MAXN];


int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    long long N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    Pref[0] = 0;
    for(int i = 1; i <= N; i++){
        Pref[i] = Pref[i - 1] + A[i - 1];
    }

    long long result = LLONG_MAX;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= N - i; j++){

            long long S = Pref[j + i] - Pref[j];
            if(S - K < result && -S + K < result){
                result = S - K;
                if(result < 0) result = -result;
                //cout << i << " " << j << "\n";
            }
        }
    }

    if(result < 0) cout << -result << "\n";
    else cout << result << "\n";

    return 0;
}
