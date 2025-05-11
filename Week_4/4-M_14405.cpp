#include <bits/stdc++.h>
using namespace std;

string str;
int flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for (int i = 0; i < str.size(); i++){
        if (str[i] == 'p'){
            if (str.substr(i, 2) != "pi"){
                flag = 1;
                break;
            }
            i += 1;
        }
        else if (str[i] == 'k'){
            if (str.substr(i, 2) != "ka"){
                flag = 1;
                break;
            }
            i += 1;
        }
        else if (str[i] == 'c'){
            if (str.substr(i, 3) != "chu"){
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