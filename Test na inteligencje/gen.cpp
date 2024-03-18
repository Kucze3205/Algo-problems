#include<bits/stdc++.h>
using namespace std;

int rnd(int a, int b){
    return rand() % (b - a + 1) + a;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

	int seed;
	cin >> seed;
	srand(seed);

    int m = rnd(1, 10);
    cout << m << "\n";

	for(int i = 0; i < m; i++){
        int a = rnd(1, 10);
	    cout << a << " ";
	}
	cout << "\n";

	int n = rnd(1, 10);
	cout << n << "\n";

	int mi = rnd(1, 10);
	for(int i = 0; i < n; i++){
	    cout << mi << "\n";
	    for(int j = 0; j < mi; j++){
            int b = rnd(1, 10);
            cout << b << " ";
	    }
        cout << "\n";
	}

    return 0;
}
