#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

int prefzer[MAXN];
int sufjed[MAXN];
int in[MAXN];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    int wyn = INT_MAX;

    for(int i = 1; i <= n; i++)
        cin >> in[i];


    prefzer[0] = 0;
    for(int i = 1; i <= n; i++){
        prefzer[i] = prefzer[i - 1];
        if(!in[i]) prefzer[i]++;
    }

    sufjed[n + 1] = 0;
    for(int i = n; i > 0; i--)
        sufjed[i] = sufjed[i + 1] + in[i];


    for(int i = 0; i <= n; i++)
        wyn = min(wyn, prefzer[i] + sufjed[i + 1]);

    cout << wyn << "\n";

    return 0;
}
