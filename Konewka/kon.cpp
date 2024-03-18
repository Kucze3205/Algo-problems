#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 19;
int N, K;
pair<int, int> t[MAXN << 1]; //drzewo przedział-przedział --> dodaj wartość, odczytaj minimum
int t2[MAXN << 1]; //ilośc wartości >= k

void push(int w){

    t[w * 2].second += t[w].second;
    t[w * 2 + 1].second += t[w].second;

    t[w * 2].first += t[w].second;
    t[w * 2 + 1].first += t[w].second;

    t[w].second = 0;
}

void add(int v, int p, int q, int a, int b){
    if(b < p || a > q) return;
    else if(a <= p && q <= b){
        t[v].first += 1;
        t[v].second += 1;
    }else{
        int l = v * 2, r = v * 2 + 1, mid = (p + q) / 2;
        push(v);

        add(l, p, mid, a, b);
        add(r, mid + 1, q, a, b);

        t[v].first = max(t[l].first, t[r].first);
    }
}

void inicjuj(int n, int k, int *D)
{
    N = n, K = k;
    for(int i = 0; i < MAXN * 2; i++){
        t[i] = {-INT_MAX, 0};
        t2[i] = 0;
    }

    for(int i = 0; i < n; ++i){
        t[i + MAXN] = {D[i], 0};

        if(t[i + MAXN].first >= k){
            int dex = i + MAXN;
            while(dex > 0){
                t2[dex]++;
                dex = dex / 2;
            }
            t[i + MAXN].first = -INT_MAX;
        }else{
            int dex = i + MAXN;

            while(t[dex].first > t[dex / 2].first && dex != 1){
                t[dex / 2].first = t[dex].first;
                dex = dex / 2;
            }
        }
    }

}

void podlej(int a, int b)
{
    add(1, 0, MAXN - 1, a, b);

    int maksimum  = t[1].first;

    while(maksimum >= K){

        int dex = 1;
        while(dex < MAXN){
            push(dex);
            if(t[dex].first == t[dex * 2].first){
                t[dex].first = -INT_MAX;
                dex = 2 * dex;
            }
            else{
                t[dex].first = -INT_MAX;
                dex = 2 * dex + 1;
            }
        }
        t[dex].first = -INT_MAX;

        while(dex > 0){
            t2[dex]++;
            dex = dex / 2;

            t[dex].first = max(t[2 * dex].first, t[2 * dex + 1].first);
        }

        maksimum  = t[1].first;
    }
}

int dojrzale(int a, int b) // zczytanie wartości z przedziału a b
{
    int wyn = 0;

    int p = a - 1 + MAXN;
	int k = b + 1 + MAXN;

	while(p + 1 < k){
        if(p % 2 == 0) wyn += t2[p + 1];
        if(k % 2 == 1) wyn += t2[k - 1];

        p = p / 2;
        k = k / 2;
    }

    return wyn;
}

