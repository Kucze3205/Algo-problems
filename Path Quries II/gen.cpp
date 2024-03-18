#include <bits/stdc++.h>
using namespace std;
int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}

int main(){
    int seed;
    cin >> seed;
    srand(seed);

    int n = 200000, q = 20;
    cout << n << " " << q << "\n";
    for(int i = 1; i <= n; i++){
        cout << rnd(1, 1e9) << " ";
    }
    cout << "\n";

    for(int i = 2; i <= n; i++){
        //cout << i << " " << rnd(1, i - 1) << "\n";
        cout << i << " " << i - 1 << "\n";
    }
    while(q--){
        int type = rnd(1, 2);
        int a = rnd(1, n);
        int b;
        if(type == 1) b = rnd(1, 1e9);
        else b = rnd(1, n);

        cout << type << " ";
        cout << a << " ";
        cout << b << "\n";
    }

}
