#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 3;
int closed[MAXN];

int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}


int main(){
    int seed;
    cin >> seed;
    srand(seed);

    int n = 500000;
    cout << n << "\n";
    for(int i = 2; i <= n; i++){
        //cout << i << " " << rnd(1, i - 1) << "\n";
        //cout << 1 << " " << i << "\n";
        cout << i - 1 << " " << i << "\n";
    }
    int m = 500000;
    cout << m << "\n";
    while(m--){
        int a = rnd(1, n);

        if(closed[a]) cout << -a << "\n";
        else cout << a << "\n";

        closed[a] ^= 1;

    }
}
