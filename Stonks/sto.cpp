#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 3;

int p[MAXN];
long long wyn[MAXN];
long long pref[MAXN];
int n, x;

long long getmax(int a,int b){
    p[a] = b - x;
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + p[i];

    long long min_v = 0, max_v = -INT_MAX;
    for(int i = 1; i <= n; i++){
        if(min_v > pref[i - 1]) min_v = pref[i - 1];
        if(max_v < pref[i] - min_v) max_v = pref[i] - min_v;
    }
    return max_v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;

    cin >> n >> q >> x;
    pref[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        p[i] -= x;
    }

    wyn[0] = getmax(0 , x);
    //for(int i = 0; i <= n; i++) cout << pref[i] << " ";

    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;

        wyn[i] = getmax(a, b);
    }

    for(int i = 0; i <= q; i++) cout << wyn[i] << " ";

    return 0;
}
