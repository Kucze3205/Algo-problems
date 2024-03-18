#include <bits/stdc++.h> // ocen/
using namespace std;

const int MAXN = 5e5 + 5;

vector<pair<pair<int, int>, int>> vctr; // moment zakończenia, index
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
        vctr.push_back({{wykl[i].second, -wykl[i].first}, i});
    }
    sort(vctr.begin(), vctr.end());

    int old_b = 0;
    int f_part, index;
    int a, b;


    for(auto w : vctr){
        a = -w.first.second;
        b = w.first.first;
        index = w.second;
        //cout << a << " " << b << " " << index << "\n";

        if(a < old_b) continue;
        else{
            potencial.push_back(index);
            old_b = b;
        }
    }

    old_b = 0;
    int old_b_zapas = 0;

    bool zapas = false;
    bool zapas_pierwszy = false;

    for(auto w : vctr){
        a = -w.first.second;
        b = w.first.first;
        index = w.second;

        if(zapas){
            if(a < old_b) continue;
            else{
                wyn.push_back({f_part, index});
                old_b = wykl[f_part].second;
                old_b_zapas = b;
                zapas = false;
            }
        }else{
            if(a < old_b_zapas){
                if(a < old_b) continue;
                else{
                    zapas_pierwszy = true;
                    f_part = index;
                }
            }
            else{
                zapas = true;
                if(zapas_pierwszy){
                    wyn.push_back({index, f_part});
                    old_b = b;
                    old_b_zapas = b;
                    zapas = false;
                    zapas_pierwszy = false;
                }
                f_part = index;
            }
        }
    }

    if(potencial.size() == wyn.size()){
        cout << wyn.size() << "\n";
        for(auto p : wyn) cout << p.first << " " << p.second << "\n";
    }else{
        cout << potencial.size() - 1 << "\n";
        for(int i = 0; i < potencial.size() - 1; i++)
            cout << potencial[i] << " " << potencial[potencial.size() - 1] << "\n";
    }

    return 0;
}
