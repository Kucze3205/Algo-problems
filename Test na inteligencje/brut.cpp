#include<bits/stdc++.h>
using namespace std;

const int MAXM = 1e6 + 7;
int ciag[MAXM];
vector<int> test[MAXM];
bool result[MAXM];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

	int m;
	cin >> m;

	for(int i = 0; i < m; i++){
	    cin >> ciag[i];
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


	for(int i = 0; i < n; i++){
	    int iciagu = 0;
	    for(int j = 0; j < test[i].size(); j++){
	        while(ciag[iciagu] != test[i][j]){
	            iciagu++;
	            if(iciagu >= m) break;
	        }

	        if(iciagu >= m) break;
	        iciagu++;
	        if(j == test[i].size() - 1) result[i] = true;
	        if(iciagu >= m) break;
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
