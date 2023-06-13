#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //wczytywanie

    
    int n, m;
    int leader = 0;
    int amount = 0;
    int c;

    cin >> n >> m;

    for (int i = 0; i < n * m; i++) {
        cin >> c;
        if (c != 0) {
            if (amount != 0) {
                if (c == leader) {
                    amount++;
                }
                else {
                    amount--;
                }
            }
            else {
                amount = 1;
                leader = c;
            }   
        }
    }

    cout << leader << "\n";
}