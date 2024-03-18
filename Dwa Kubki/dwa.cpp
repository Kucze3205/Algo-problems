#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 7;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int P = 199;

pair<int, int> pow_p[MAXN];

int a[MAXN];
int b[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    pow_p[0] = {1,1};

	for(int i = 1; i < n; i++)
		pow_p[i] = {
            ((ll)(pow_p[i - 1].first) * P) % MOD1,
            ((ll)(pow_p[i - 1].second) * P) % MOD2};

    pair<int, int> Ha = {0, 0},Hb = {0, 0};

    for(int i = n - 1; i >= 0; i--){
		Ha = {
            ((ll)(Ha.first) + (ll)(a[i]) * (ll)pow_p[n - 1 - i].first) % MOD1,
            ((ll)(Ha.second) + (ll)(a[i]) * (ll)pow_p[n - 1 - i].second) % MOD2};

        Hb = {
            ((ll)(Hb.first) + (ll)(b[i]) * (ll)pow_p[n - 1 - i].first) % MOD1,
            ((ll)(Hb.second) + (ll)(b[i]) * (ll)pow_p[n - 1 - i].second) % MOD2};
    }
     //cout << Hb.first << " " << Hb.second << "\n";
    for(int i = 0; i < n; i++){

        if(Ha == Hb){
            cout << "TAK";
            return 0;
        }

        pair<int, int> last_digit = {
            ((ll)(b[i]) * pow_p[n - 1].first) % MOD1,
            ((ll)(b[i]) * pow_p[n - 1].second) % MOD2};

        Hb = {
            ((ll)Hb.first + MOD1 - last_digit.first) % MOD1,
            ((ll)Hb.second + MOD2 - last_digit.second) % MOD2};
        Hb = {
            ((ll)Hb.first * P) % MOD1,
            ((ll)Hb.second * P) % MOD2};
        Hb = {
            ((ll)Hb.first + b[i]) % MOD1,
            ((ll)Hb.second + b[i]) % MOD2};
    }

    cout << "NIE";
    return 0;
}
