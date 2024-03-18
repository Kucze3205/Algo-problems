#include <bits/stdc++.h>
using namespace std;

int rnd(int a, int b){
    return (rand() % (b - a + 1)) + a;
}

bool neigh[10][10];

int main(){
    int seed;
    cin >> seed;
    srand(seed);

    int n = rnd(1,8);
    int m = rnd(1, n * (n - 1) / 2);
    int k = rnd(1, 10);

    cout << n << " ";
    cout << m << " ";
    cout << k << "\n";

    int a, b;
    for(int i = 1; i <= n; i++) neigh[i][i] = true;

    for(int i = 0; i < m; i++){
        do{
            a = rnd(1,n);
            b = rnd(1,n);
            //cout << "xd";
        }while(neigh[a][b]);

        cout << a << " " << b << "\n";

        neigh[a][b] = true;
        neigh[b][a] = true;
    }

    int d;
    for(int i = 0; i < k; i++){
        a = rnd(1,n);
        b = rnd(1,n);
        d = rnd(1, 15);

        cout << a << " ";
        cout << b << " ";
        cout << d << "\n";

    }

    return 0;
}
