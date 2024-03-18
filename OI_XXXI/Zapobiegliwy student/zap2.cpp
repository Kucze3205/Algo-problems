#include <bits/stdc++.h> // ocen/
using namespace std;

const int MAXN = 5e5 + 5;

vector<pair<int, int>> vctr; // moment zakończenia, index
pair<int, int> wykl[MAXN];
vector<int> potencial;
vector<pair<int, int>> wyn;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> wykl[i].first >> wykl[i].second;
        vctr.push_back({wykl[i].second, i});
    }
    sort(vctr.begin(), vctr.end());
    pair<int, int> old_pair = {0, 0};
    int index;
    int a, b;

    for(auto w : vctr){
        a = wykl[w.second].first;
        b = w.first;
        index = w.second;

        if(a < old_pair.second) continue;
        else{
            potencial.push_back(index);
            old_pair = {a, b};
            wyn.push_back({index, -1});
        }
    }

    bool mniej1 = false, wybrany = false;
    old_pair = {0, 0};
    int act_spoj = 0; // index vectora potencial

    for(auto w : vctr){ if(w.second == vctr[0].second) continue; // pierwsze omijamy

        a = wykl[w.second].first;
        b = w.first;
        index = w.second;

        if(index != potencial[act_spoj + 1]){
            if(a < old_pair.second || b > wykl[potencial[act_spoj + 1]].first) continue;
            else if(!wybrany){
                wyn[act_spoj].second = index;
                wybrany = true;
            }
        }else{
            if(wyn[act_spoj].second == -1){
                mniej1 = true;
                wyn[act_spoj].second = potencial[potencial.size() - 1];
            }
            old_pair = {wykl[potencial[act_spoj]]};
            act_spoj++;
            wybrany = false;
        }
    }

    cout << wyn.size() - (int)mniej1 << "\n";
    for(int i = 0; i < wyn.size() - (int)mniej1; i++)
        cout << wyn[i].first << " " << wyn[i].second << "\n";

    return 0;
}
