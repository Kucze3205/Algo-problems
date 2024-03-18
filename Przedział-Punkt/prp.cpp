#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD1 = 1e9 + 7;
const int base = 1 << 17;
int tab[base << 1];
vector<int> res;

void upgrade(int a, int b, int c){
    a += base - 1;
    b += base + 1;

    while(a + 1 < b){

        if(a % 2 == 0){
            tab[a + 1] = ((ll)tab[a + 1] * c) % MOD1;
            //cout << tab[b - 1] << " ";
        }
        if(b % 2 == 1){
            tab[b - 1] = ((ll)tab[b - 1] * c) % MOD1;
            //cout << tab[b - 1] << " ";
        }
        a = a / 2;
        b = b / 2;
    }
}

int read(int a){
    a += base;
    int wyn = 1;
    while(a > 0){

        wyn = ((ll)wyn * tab[a]) % MOD1;
        a = a / 2;
    }

    return wyn;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    for(int i = 0; i < 2 * base; i++) tab[i] = 1;

    for(int i = 0; i < q; i++){
        int t, a, b, c;
        cin >> t;
        if(t == 0){
            cin >> a >> b >> c;
            upgrade(a, b, c);
        }
        if(t == 1){
            cin >> a;
            res.push_back(read(a));
        }
    }

    //for(int i = 0; i < 4; i++) res.push_back(read(i));

    for(auto w : res) cout << w << "\n";


    return 0;
}
