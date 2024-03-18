#include <bits/stdc++.h>
#include <set>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 7;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int P = 314159;


pair<int, int> pow_p[MAXN];
pair<int, int> pref_H[MAXN];
pair<int, int> suf_H[MAXN];
int a[MAXN];

int CountDistinct(int k, int n){

	set<pair<int, int>> distinct;
	
    int am = 0;
    for(int i = k; i <= n; i += k){
    
        pair<int, int> odciety = {
            ((ll)pref_H[i].first - pref_H[i - k].first + MOD1) % MOD1,
            ((ll)pref_H[i].second - pref_H[i - k].second + MOD2) % MOD2};
            
        odciety = {
            ((ll)odciety.first * pow_p[n - i].first) % MOD1,
            ((ll)odciety.second * pow_p[n - i].second) % MOD2};

        pair<int, int> odwrocony = {
            ((ll)suf_H[n - i + k].first - suf_H[n - i].first + MOD1) % MOD1,
            ((ll)suf_H[n - i + k].second - suf_H[n - i].second + MOD2) % MOD2};
            
        odwrocony = {
            ((ll)odwrocony.first * pow_p[i - k].first) % MOD1,
            ((ll)odwrocony.second * pow_p[i - k].second) % MOD2};
            
		//cout << k;
		//cout << "\n";	
		//cout << odciety.first << " " << odciety.second << "\n";
		//cout << odwrocony.first << " " << odwrocony.second << "\n";
		//cout << "\n";
		
		if(odciety.first <= 0 || odciety.second <= 0 || odwrocony.first <= 0 || odwrocony.second <= 0)
			cout << "XD";
		
        if(distinct.find(odciety) == distinct.end() && distinct.find(odwrocony) == distinct.end()){
            
            am++;
        }
        distinct.insert(odciety);
    }

    return am;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
    int n;
	
    cin >> n;
	
    for(int i = 0; i < n; i++)
        cin >> a[i];

    pow_p[0] = { 1,1 };

	for(int i = 1; i <= n; i++)
		pow_p[i] = {
            ((ll)(pow_p[i - 1].first) * P) % MOD1,
            ((ll)(pow_p[i - 1].second) * P) % MOD2};

    pref_H[0] = { 0,0 };

    for(int i = 1; i <= n; i++){
		pref_H[i] = {
            ((ll)(pref_H[i - 1].first) + (ll)(a[i - 1]) * (ll)pow_p[i - 1].first) % MOD1,
            ((ll)(pref_H[i - 1].second) + (ll)(a[i - 1]) * (ll)pow_p[i - 1].second) % MOD2};
    }

    suf_H[0] = { 0,0 };

    for(int i = 1; i <= n; i++){
		suf_H[i] = {
            ((ll)(suf_H[i - 1].first) + (ll)(a[n - i]) * (ll)pow_p[i - 1].first) % MOD1,
            ((ll)(suf_H[i - 1].second) + (ll)(a[n - i]) * (ll)pow_p[i - 1].second) % MOD2};
    }

    int max_opt = 0;
    vector<int> optimum;

    for(int i = 1; i <= n; i++){

        int count_distinct = CountDistinct(i, n);

        if(count_distinct > max_opt){
            max_opt = count_distinct;
            optimum.clear();
            optimum.push_back(i);
        }else if(count_distinct == max_opt)
            optimum.push_back(i);
    }

    cout << max_opt << " " << optimum.size() << "\n";
    
    for(int i = 0; i < optimum.size(); i++)
        cout << optimum[i] << " ";

    return 0;
}
