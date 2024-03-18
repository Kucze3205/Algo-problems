#include <bits/stdc++.h>
using namespace std;

const int MAXT = 1e4;
const int MAXN = 2e5 + 3;

int pref[MAXN];
int a[MAXN];
int b[MAXN];
bool working[MAXN];
vector<int> result[MAXT];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int tcase = 0; tcase < t; tcase++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i <= n; i++) pref[i] = 0;

        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                pref[b[i]]++;
                pref[a[i]]--;
            }
        }

        for(int i = 1; i <= n; i++) pref[i] += pref[i - 1];

        for(int i = 1; i < n; i++) working[i] = true;

        for(int k = 1; k < n; k++){
            for(int xk = k; xk <= n; xk += k){
                if(pref[xk] > 0){
                    working[k] = false;
                    break;
                }
            }
        }

        for(int i = 1; i < n; i++) if(working[i]) result[tcase].push_back(i);
        result[tcase].push_back(n);
    }

    for(int i = 0; i < t; i++){
        cout << result[i].size() << "\n";
        for(auto k : result[i]) cout << k << " ";
        cout << "\n";
    }

    return 0;
}
