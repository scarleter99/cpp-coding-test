#include <bits/stdc++.h>
using namespace std;

int t;
string str;
bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        cin >> str;

        int temp = 0;
        for (char c : str){
            if (c == '('){
                temp++;
            }
            else if (c == ')'){
                temp--;
            }

            if (temp < 0){
                break;
            }
        }

        if (temp == 0){
            cout << "YES\n";
        }
        else{
            
            cout << "NO\n";
        }
    }

    return 0;
}