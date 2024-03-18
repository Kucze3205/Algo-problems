#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int mess[MAXN];
unordered_map<int, int> amount;
priority_queue<pair<int, int>> state;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;

    for(int i = 0; i < n; i++){
        cin >> mess[i];
    }

    int l = 0, r = 0;

    int imp;
    int act = 0;
    int act_max = w;
    int wyn = w;

    if(w == n){
        cout << w;
        return 0;
    }
    while(r < n){
        if(act <= act_max){
            amount[mess[r]]++;
            state.emplace(amount[mess[r]], mess[r]);
            act++;
            imp = state.top().first;
            act_max = imp + w;
            if(act_max > wyn) wyn = act_max;
            r++;
        }else{
             amount[mess[l]]--;
             act--;
             state.emplace(amount[mess[l]], mess[r]);
             while(state.top().first != amount[state.top().second]){
                state.pop();
             }
             imp = state.top().first;
             act_max = imp + w;
             l++;
        }
    }
    cout << wyn;

    return 0;
}
