#include <bits/stdc++.h>
using namespace std;

int m;
int mask;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m;

    for (int i = 0; i < m; i++){
        string str;
        int temp;
        cin >> str;

        if (str == "all"){
            mask = (1 << 21) - 1;
            continue;
        }
        else if (str == "empty"){
            mask = 0;
            continue;
        }

        cin >> temp;

        if (str == "add"){
            mask |= (1 << temp);
        }
        else if (str == "remove"){
            mask &= ~(1 << temp);
        }
        else if (str == "check"){
            if (mask & (1 << temp)){
                cout << "1" << "\n";
            }
            else{
                cout << "0" << "\n";
            }
        }
        else if (str == "toggle"){
            mask ^= (1 << temp);
        }
    }

    return 0;
}