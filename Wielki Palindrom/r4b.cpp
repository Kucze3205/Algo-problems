#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;

    cin >> n >> k;
    if(k > 2 || (n % 2 == 0 && k == 2)){
        cout << "NIE";
        return 0;
    }
    if(k == 1){
        for(int i = 0; i < n; i++) cout << 9;
        return 0;
    }
    for(int i = 0; i < n / 2; i++) cout << 9 - (i % 2);
    if(n % 2 == 1) cout << 9 - (n / 2) % 2;
    for(int i = n / 2 + 1; i < n; i++) cout << 9 - (i % 2);

    return 0;
}
