#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 3;
int a[MAXN];
int amount[MAXN];

int liczwyn(int p, int k){
    vector<int> vctr;
    for(int i = p; i <= k; i++) amount[a[i]] = 0;
    for(int i = p; i <= k; i++){
        amount[a[i]]++;
        vctr.push_back(a[i]);
    }
    sort(vctr.begin(), vctr.end());

    //if(p == 0 && k == 4) cout << amount[vctr[(k - p + 1) / 2]] << " ";

    if((k - p + 1) % 2 == 1) return amount[vctr[(k - p + 1) / 2]];
    else return max(amount[vctr[(k - p) / 2]], amount[vctr[(k - p + 1) / 2]]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int wyn = 1;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            wyn = max(wyn, liczwyn(i, j));
            if(liczwyn(i, j) == 2) cout << i << " " << j;
        }
    }
    cout << wyn << "\n";

    return 0;
}
