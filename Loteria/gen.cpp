#include <bits/stdc++.h>
using namespace std;

int rnd(int a, int b){
    return (rand() % (b - a + 1) + a);
}


int main(){
    int seed;
    cin >> seed;
    srand(seed);

    int n = rnd(5, 2e5), k = rnd(1, 2e5);
    cout << n << " " << k << "\n";


    for(int i = 1; i <= n; i++){
       cout << rnd(1, 2e5) << " ";
    }

    cout << "\n";

    return 0;
}
