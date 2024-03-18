#include<bits/stdc++.h>
using namespace std;

const int MAXM = 1e6 + 7;
vector<int> ciag[MAXM];
vector<int> test[MAXM];
bool result[MAXM];

int BS(int l, int r, int act, int j){
    while(l < r){
        int mid = (l + r) / 2;
        if(ciag[j][mid] > act) r = mid;
        else l = mid + 1;
    }

    return ciag[j][l];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

	int m, a;
	cin >> m;

	for(int i = 0; i < m; i++){
	    cin >> a;
	    ciag[a].push_back(i);
	}
	int n;
	cin >> n;

	int mi, b;
	for(int i = 0; i < n; i++){
	    cin >> mi;
	    for(int j = 0; j < mi; j++){
	       cin >> b;
	       test[i].push_back(b);
	    }

	}

    int act;

    for(int i = 0; i < n; i++){
        act = -1;

        result[i] = true;
        for(auto j : test[i]){
            //cout << j << " ";
            if(ciag[j].size() == 0 || act >= ciag[j][ciag[j].size() - 1]){
                result[i] = false;
                break;
            }
            act = BS(0, ciag[j].size() - 1, act, j);
        }
    }

	for(int i = 0; i < n; i++){
	    if(result[i])
	        cout << "TAK" << "\n";
	    else
	        cout << "NIE" << "\n";

	}

    return 0;
}
