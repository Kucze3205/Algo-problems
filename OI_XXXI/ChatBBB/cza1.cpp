#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int p = 314159;
const int MAXN = 1e6 + 3;

pair<int, int> p_pow[MAXN * 2];
pair<int, int> pref[MAXN * 2];

char S[MAXN * 2];

int Alph[MAXN][26];
pair<int, int> parent[MAXN * 2];
bool odw[MAXN * 2];
int num[MAXN * 2];

pair<int, int> makeHash(int i, int k, int n){
    pair<int, int> result = {
        ((ll)pref[i + k].first - pref[i].first + MOD1) % MOD1,
        ((ll)pref[i + k].second - pref[i].second + MOD2) % MOD2
    };

    return {
        ((ll)result.first * p_pow[2 * n - (i + k)].first) % MOD1,
        ((ll)result.second * p_pow[2 * n - (i + k)].second) % MOD2
    };
}

pair<int, int> ToWho(pair<int, int> H, int i, int k, int n, char a){
    pair<int, int> result = {
        ((ll)H.first - S[i] + MOD1) % MOD1,
        ((ll)H.second - S[i] + MOD2) % MOD2
    }; // odejmujemy pierwszą litere

    result = {
        ((ll)H.first + (ll)p_pow[2 * n].first * a + MOD1) % MOD1,
        ((ll)H.second + (ll)p_pow[2 * n].second * a + MOD2) % MOD2
    }; // dodajemy ostatnią litere

    result = {
        ((ll)(H.first / p) + MOD1) % MOD1,
        ((ll)(H.second / p) + MOD2) % MOD2
    }; // przesuwamy w lewo


    return result;
}

int main(){
    //ios_base :: sync_with_stdio(false);
    //cin.tie(0);

    //wczytywanie
    int n, k;
    ll a, b;

    cin >> n >> k >> a >> b;

    for(int i = n; i < n * 2; i++) S[i] = 'a';
    for(int i = 0; i < n; i++) cin >> S[i];


    p_pow[0] = {1, 1};
    for(int i = 1; i <= n * 2; i++){
        p_pow[i] = {
            ((ll)p_pow[i - 1].first * p) % MOD1,
            ((ll)p_pow[i - 1].second * p) % MOD2};
    }

    pref[0] = {0, 0};
    for(int i = 1; i <= n; i++){
        pref[i] = {
            ((ll)pref[i - 1].first + (ll)p_pow[i - 1].first * S[i - 1]) % MOD1,
            ((ll)pref[i - 1].second + (ll)p_pow[i - 1].second * S[i - 1]) % MOD2};

    }

    map<pair<int, int>, int> dex;
    map<pair<int, int>, char> znak;

    //nadawanie następnej litery dla danego podsłowa i ścieżki grafu
    for(int i = 0; i < 2 * n; i++) parent[i] = {-1, -1};

    for(int i = 0; i < n - k - 1; i++){
        pair<int, int> hash_k = makeHash(i, k, n);
        int ascii_i = S[i + k] - 97;
        if(!dex.count(hash_k)){
            dex[hash_k] = i;


        }
        Alph[dex[hash_k]][ascii_i]++;

        if(Alph[dex[hash_k]][ascii_i] > Alph[dex[hash_k]][znak[hash_k] - 97]
        || (Alph[dex[hash_k]][ascii_i] == Alph[dex[hash_k]][znak[hash_k]]
            && ascii_i < znak[hash_k])){
            znak[hash_k] = char(ascii_i + 97);

            parent[dex[hash_k]] = makeHash(i + 1, k, n);
        }
        cout << hash_k.first << "\n";

    }
    cout << "\n";

    // znajdywanie cyklu
    bool finded = false;
    pair<int, int> w = makeHash(n - k, k, n);
    int x, y;
    for(int i = 0; true; i++){
        if(!dex.count(w)){
            dex[w] = n - k + i + 1;
            pref[n + i + 1] = {
                ((ll)pref[n + i].first + (ll)p_pow[n + i].first * S[n + i]) % MOD1,
                ((ll)pref[n + i].second + (ll)p_pow[n + i].second * S[n + i]) % MOD2};

            znak[w] = 'a';
            parent[dex[w]] = makeHash(n - k + i + 1, k, n);

            cout << w.first << "\n";
        }

        if(odw[dex[w]]){
            x = num[dex[w]];
            y = i;
            //cout << x << " " << y << "\n";
            break;
        }

        odw[dex[w]] = true;
        num[dex[w]] = i;

        w = parent[dex[w]];
    }

    //rozwiazanie
    int start;
    if(a - (ll)n >= x){
        start = ((a - n - 1) % (y - x)) + x;
    }else{
        start = a - n;
        w = makeHash(n - k, k, n);
    }
    //cout << start << "\n";
    while(num[dex[w]] != start) w = parent[dex[w]];
    for(int i = 0; (ll)i < b - a + 1; i++){
        cout << znak[w];
        w = parent[dex[w]];
    }
    for(int i = 0; i < n - k; i++){
        pair<int, int> hash_k = makeHash(i, k, n);

    }

    cout << "\n";
    return 0;
}
