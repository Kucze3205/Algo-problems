#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;

long long A[MAXN];
long long Pref[MAXN];
set<long long> S;
set<long long> Srev;


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

    S.insert(0);

    for(int i = 1; i <= N; i++){

        auto it = S.lower_bound(Pref[i] - K);

        if(abs(Pref[i] - *it - K) < result && S.find(*it) != S.end()){
            if(abs(Pref[i] - *it - K) < result ) result = abs(Pref[i] - *it - K);
        }
        it--;
        if(abs(Pref[i] - *(it) - K) < result && S.find(*it) != S.end()){
            if(abs(Pref[i] - *it - K) < result) result = abs(Pref[i] - *it - K);
        }

        /*if(Pref[i] == 13){
            for(auto w : S) cout << w << " ";
            cout << "\n";
            cout << Pref[i] - K << "\n";
            cout << *it;
        }*/

        //cout << *it << " " << (bool)(S.find(*it) != S.end()) << "\n";
        //cout << *(--it) << " " << (bool)(S.find(*(--it)) != S.end()) << "\n";

        //cout << "\n";
        S.insert(Pref[i]);
    }

    cout << result << "\n";

    return 0;
}
