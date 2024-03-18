#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

priority_queue<pair<int, int>> que; // moment zakończenia, index
pair<int, int> wykl[MAXN];

vector<pair<int, int>> wyn;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> wykl[i].first >> wykl[i].second;
        que.push({-wykl[i].second, i});
    }

    pair<int, int> old_pair = {0, 0};
    int f_part, index;
    int a, b;
    bool zapas = false;

    while(que.size()){
        a = wykl[que.top().second].first;
        b = -que.top().first;
        index = que.top().second;
        que.pop();

        if(zapas){
            if(a < old_pair.second) continue;
            else{
                wyn.push_back({f_part, index});
                old_pair = {min(wykl[f_part].first, a), b};
                zapas = false;
            }
        }else{
            if(a < old_pair.second) continue;
            else{
                f_part = index;
                zapas = true;
            }
        }
    }
    cout << wyn.size() << "\n";
    for(auto p : wyn) cout << p.first << " " << p.second << "\n";


    return 0;
}
