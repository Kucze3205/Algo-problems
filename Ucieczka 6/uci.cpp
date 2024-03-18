#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 3;
const int base = 1 << 19;
int a[MAXN];
int amount[base << 1];
pair<int, int> first[MAXN]; // index pierszego wystąpienia wartości, ilość wartości mniejszych od danej

void update(int i){
    i += base - 1;
    while(i > 0){
        amount[i]++;
        i = i / 2;
    }
}

int read(int a, int b){

    a += base - 1 - 1;
    b += base - 1 + 1;
    int res = 0;

    while(a + 1 < b){
        if(a % 2 == 0) res += amount[a + 1];
        if(b % 2 == 1) res += amount[b - 1];

        a = a / 2;
        b = b / 2;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int wyn = 1;

    for(int i = 0; i < n; i++){
        update(a[i]);
        int val_amount = amount[a[i] + base - 1];
        if(val_amount == 1){
            first[a[i]].first = i;
            first[a[i]].second = read(1, a[i] - 1);
        }

        if(val_amount <= wyn) continue;

        if((i - first[a[i]].first + 1) % 2 == 0){
            int miedzy = read(1, a[i] - 1) - first[a[i]].second;
            int middle = (i - first[a[i]].first + 2) / 2;
            if(val_amount + miedzy >= middle && miedzy <= middle){
                wyn = val_amount;
                //cout << wyn << " " <<  a[i] << " " << val_amount << " " <<  miedzy << " " <<  middle << "\n";
            }
        }else{
            int miedzy = read(1, a[i] - 1) - first[a[i]].second;
            int middle = (i - first[a[i]].first + 2) / 2;
            if(val_amount + miedzy >= middle && miedzy < middle){
                wyn = val_amount;
                //cout << wyn << " " <<  a[i] << " " << val_amount << " " <<  miedzy << " " <<  middle << "\n";
            }
        }

    }

    cout << wyn << "\n";

    return 0;
}
