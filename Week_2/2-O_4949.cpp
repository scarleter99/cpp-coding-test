#include <bits/stdc++.h>
using namespace std;

string line;
bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(getline(cin, line)){
        if (line == "."){
            break;
        }

        flag = true;
        stack<char> st;
        for (char c : line){
            if (c == '[' || c == '('){
                st.push(c);
            }
            else if (c == ']'){
                if (st.size() && '[' == st.top()){
                    st.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if (c == ')'){
                if (st.size() && '(' == st.top()){
                    st.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
        }

        if (flag && st.empty()){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }

    return 0;
}