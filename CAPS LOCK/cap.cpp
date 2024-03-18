#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 7;
const int p = 199;
const int MOD = 1e9 + 7;

int pow_P[MAXN];
int H[MAXN];

int get_hash(int i, int m, int n){
	int res = (H[i] - H[i - m] + MOD) % MOD;	
	return ((ll)res * pow_P[n - i + m]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string text;
	cin >> text;
	
	string pattern;
	cin >> pattern;
	
	int n = text.size();
	int m = pattern.size();
	
	pow_P[0] = 1;
	for(int i = 1; i <= n; ++i)
		pow_P[i] = ((ll)pow_P[i - 1] * p) % MOD;
	
	int patternH = 0;
	for(int i = 0; i < m; ++i)
		patternH = ((ll)patternH + (ll)pow_P[i] * pattern[i]) % MOD;
	patternH = ((ll)patternH * pow_P[n]) % MOD;
	
	H[0] = 0;
	for(int i = 0; i < n; ++i)	
		H[i + 1] = ((ll)H[i] + (ll)pow_P[i] * text[i]) % MOD;
	
	string wyn = text;
	for(int i = m; i <= n; i++){
		if(get_hash(i, m, n) == patternH){
			for(int j = 0; j < m; j++){
				if(wyn[i - j - 1] <= 'Z') break;
				wyn[i - j - 1] -= 32; // zamiana malej na duza(kod ascii - 32)
			}
		}
	}
	cout << wyn;
	return 0;
}
