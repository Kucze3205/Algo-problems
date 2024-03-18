#include <bits/stdc++.h>
using namespace std;

int rnd(int a, int b){
    return rand() % (b - a + 1) + a;
}


int main(){
    int seed;
    cin >> seed;
    srand(seed);

    int n = rnd(1, 10);
    cout << n << "\n";
    for(int i = 0; i < n; i++){
        cout << rnd(-1e9, 1e9) << " ";
    }
}
