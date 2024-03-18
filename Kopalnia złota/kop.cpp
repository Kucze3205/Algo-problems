#include<bits/stdc++.h>
using namespace std;

const int MAXN = 12e3;
const int PUSH_VAL = 3e4; //zmiana pola na dodatnie wartosci
const int base = 1 << 17; //

vector<pair<pair<int, int>,int>> nugg;
int Broom[base << 1]; // drzewo przedzial-przedzial
int Prop[base << 1]; // propagacja wsteczna

int p, k, val;

void Push(int w, int l, int r){
    Prop[l] += Prop[w];
    Prop[r] += Prop[w];

    Broom[l] += Prop[w];
    Broom[r] += Prop[w];

    Prop[w] = 0;
}

void upgrade_Tree(int w, int a, int b){
    if(p > b || k < a)
        return;
    else if(p <= a && b <= k){
        Broom[w] += val;
        Prop[w] += val;
        //cout << a << " " << b << "\n";
    }else{
        int l = 2 * w, r = 2 * w + 1, mid = (a + b) / 2;
        Push(w, l, r);

        upgrade_Tree(l, a, mid); //przekazanie do lewego syna
        upgrade_Tree(r, mid + 1, b);  //przekazanie do prawego syna

        Broom[w] = max(Broom[l], Broom[r]);
    }
}

int main(){

    int s, w, n;

    cin >> s >> w;
    cin >> n;
    s++; //
    w++; // zamiana punktu na kwadrat

    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        x += PUSH_VAL;
        y += PUSH_VAL;
        nugg.push_back({{y, x}, 1});
        nugg.push_back({{y + w, x}, -1});
    }

    sort(nugg.begin(), nugg.end());

    int result = 0;
    int actualW = -1;

    for(int i = 0; i < nugg.size(); i++){
        int x = nugg[i].first.second;
        int y = nugg[i].first.first;


        p = x;
        k = x + s - 1;
        val = nugg[i].second;

        upgrade_Tree(1, 0, base - 1);


        if(i == nugg.size() - 1 || nugg[i + 1].first.first > actualW){
            result = max(result, Broom[1]);
            if(i != nugg.size() - 1)
                actualW = nugg[i + 1].first.first;

            cout << y << "\n";
        }

    }
    cout << result;
    return 0;
}



