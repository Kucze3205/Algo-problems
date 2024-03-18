#include<bits/stdc++.h>
using namespace std;

int rnd(int a, int b){
    return rand() % (b - a + 1) + a;
}
int p[100];
bool active[100];
int main(){
    int seed;
    cin >> seed;
    srand(seed);

    int n = rnd(1, 20);
    cout << n << "\n";

    for(int i = 2; i <= n; i++){
        int parent = rnd(1, i - 1);
        cout << parent << " " << i << "\n";
        p[i] = parent;
    }

    int m = rnd(1, 5);
    cout << m << "\n";
    int actn = n;
    while(m > 0 || actn > 1){
        bool act = rnd(0, 1);

        if(act && actn > 1){
            int v = rnd(2, n);

            while(active[v]){
                v = rnd(2, n);
                //cout << v << "\n";
            }
            active[v] = true;

            cout << 'A' << " " << p[v] << " " << v << "\n";
            actn--;

        }else if(m > 0){
            cout << 'W' << " " << rnd(2, n) << "\n";
            m--;
        }
    }
}
