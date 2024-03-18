#include <iostream>
using namespace std;

int n, r;
int Prefsum[511][511];
int W[255][255];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    

    cin >> n >> r;

    for (int i = 0; i < 255; i++)
        for (int j = 0; j < 255; j++) 
            Prefsum[i][j] = 0;      

    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> Prefsum[i][j];
        }

    for (int i = 1; i <= n + r; i++)
        for (int j = 1; j <= n + r; j++) {
            Prefsum[i][j] += Prefsum[i - 1][j];
            Prefsum[i][j] += Prefsum[i][j - 1];
            Prefsum[i][j] -= Prefsum[i - 1][j - 1];
        }



    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            W[i][j] = Prefsum[i + r][j + r];
            W[i][j] -= Prefsum[i - r - 1][j + r];
            W[i][j] -= Prefsum[i + r][j - r - 1];
            W[i][j] += Prefsum[i - r - 1][j - r - 1];
            cout << W[i][j] << " ";
        }
        cout << "\n";
    }
       
    return 0;
}
