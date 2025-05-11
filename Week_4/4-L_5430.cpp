#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[100004];
string p, line;
string ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        int cnt = 0, isR = 0, front = 0, back = 0, flag = 0;

        cin >> p >> n >> line;

        int temp = 0;
        for (char c : line){
            if (c == '[' || c == ']'){
                continue;
            }
            else if (c >= '0' && c <= '9'){
                temp = temp * 10 + (c - '0');
                a[cnt] = temp;
            }
            else{
                cnt++;
                temp = 0;
            }
        }

        for (char c : p){
            if (c == 'R'){
                isR ^= 1;
            }
            else{
                if (isR){
                    back++;
                }
                else{
                    front++;
                }
                if (front + back > n){
                    cout << "error" << "\n";
                    flag = 1;
                    break;
                }
            }
        }

        if (flag){
            continue;
        }

        cout << "[";
        if (!isR){
            for(int i = front; i < n - back; i++){
                cout << a[i];
                if (i != n - back - 1){
                    cout << ",";
                }
            }
        }
        else{
            for(int i = n - back - 1; i >= front; i--){
                cout << a[i];
                if (i != front){
                    cout << ",";
                }
            }
        }
        cout << "]\n";
    }

    return 0;
}
