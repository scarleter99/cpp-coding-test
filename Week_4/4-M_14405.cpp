#include <bits/stdc++.h>
using namespace std;

string s;
int flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'p'){
            if (s.substr(i, 2) != "pi"){
                flag = 1;
                break;
            }
            i += 1;
        }
        else if (s[i] == 'k'){
            if (s.substr(i, 2) != "ka"){
                flag = 1;
                break;
            }
            i += 1;
        }
        else if (s[i] == 'c'){
            if (s.substr(i, 3) != "chu"){
                flag = 1;
                break;
            }
            i += 2;
        }
        else{
            flag = 1;
            break;
        }
    }

    if (flag){
        cout << "NO";
    }
    else{
        cout << "YES";
    }

    return 0;
}