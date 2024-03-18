#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 3;

int rnd(int a, int b){
    return rand() % (b - a + 1) + a;
}

bool przekaznik[MAXN];

int main(){
    int seed;
    cin >> seed;
    srand(seed);

    int n = 8, m = rnd(4, 7);

    cout << n << " " << m << "\n";

    int amountofP = 0;
    for(int i = 0; i < m; i++){

        int type = rnd(0, 2);
        while(type == 1 && amountofP == 0) type = rnd(0, 2);

        if(type == 0){
            cout << "P ";

            int x = rnd(1, n), s = rnd(1, 20), a = rnd(1, 10);
            while(przekaznik[x]) x = rnd(1, n);
            cout << x << " " << s << " " << a << "\n";
            amountofP++;
            przekaznik[x] = true;

        }else if(type == 1){
            cout << "U ";
            int x = rnd(1, n);
            while(!przekaznik[x]) x = rnd(1, n);
            cout << x << "\n";
            amountofP--;
            przekaznik[x] = false;

        }else{
            cout << "Z ";
            int x1 = rnd(1, n - 1);
            int x2 = rnd(x1, n);
            cout << x1 << " " << x2 << "\n";
        }
    }

}
