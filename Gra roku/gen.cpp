#include <bits/stdc++.h>
using namespace std;

int rnd(int a, int b){
    return (rand() % (b - a + 1) + a);
}

int main(){
    int seed;
    cin >> seed;
    srand(seed);

    int t = 12;
    cout << t << "\n";
    for(int tcase = 0; tcase < t; tcase++){
        int n = rnd(1, 7);
        cout << n << "\n";

        int val;

        for(int i = 0; i < n; i++){
            val = rnd(1, n);
            cout << val << " ";
        }cout << "\n";

        for(int i = 0; i < n; i++){
            val = rnd(1, n);
            cout << val << " ";
        }cout << "\n";
    }

    return 0;
}
