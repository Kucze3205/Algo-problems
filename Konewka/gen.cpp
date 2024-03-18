#include<bits/stdc++.h>
using namespace std;

int rnd(int a, int b){
    return (rand() % (b - a + 1)) + a;
}

int main(){

    int seed;
    cin >> seed;
    srand(seed);

    int n = rnd(1, 8);
    int k = rnd(1, 50);
    cout << n << " " << k << "\n";
    for(int i = 0; i < n; i++){
        cout << rnd(1, 8) << " ";
    }
    cout << "\n";

    int q = rnd(1, 7);
    cout << q << "\n";

    int op = rnd(1 , q);

    for(int i = 0; i < op; i++){
        int a = rnd(0, n - 1);
        int b = rnd(a, n - 1);
        cout << "p " <<  a << " " << b << "\n";
    }
    for(int i = 0; i < q - op; i++){
        int a = rnd(0, n - 1);
        int b = rnd(a, n - 1);
        cout << "d " <<  a << " " << b << "\n";
    }

    return 0;
}
