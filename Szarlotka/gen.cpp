#include<bits/stdc++.h>
using namespace std;

int rnd(int a, int b){
 return (rand() % (b - a + 1)) + a;
}


int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int seed;
    cin >> seed;

    srand(seed);
    int n = rnd(1, 10000), k = rnd(-100000,10000000);
    cout << n << " " << k << "\n";

    for(int i = 0; i < n; i++) cout << rnd(-10000000, 10000000) << " ";

    cout << "\n";

    return 0;
}
