#include <bits/stdc++.h>
using namespace std;

const int MAXT = 1e4;
const int MAXN = 2e5 + 3;

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

        for(int i = 0; i < n; i++) working[i] = true;

        for(int k = 1; k < n; k++){
            for(int i = 0; i < n; i++){
                if(a[i] <= b[i]) continue;

                int roof_a = a[i] / k;
                int roof_b = b[i] / k;

                if(a[i] % k != 0) roof_a++;
                if(b[i] % k != 0) roof_b++;

                if(roof_a > roof_b){
                    working[k] = false;
                    break;
                }
            }

            if(working[k]) result[tcase].push_back(k);
        }
        result[tcase].push_back(n);
    }

    for(int i = 0; i < t; i++){
        cout << result[i].size() << "\n";
        for(auto k : result[i]) cout << k << " ";
        cout << "\n";
    }

    return 0;
}
