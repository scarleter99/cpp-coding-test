#include <bits/stdc++.h>
using namespace std;

string pw;
int vowSeq, conSeq;
bool haveVow, flag;
int last;

char vowList[] = {'a', 'e', 'i', 'o', 'u'};

bool isVow(int idx){
    return find(vowList, vowList + 5, idx) != vowList + 5;
	//return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> pw;
        if (pw == "end"){
            break;
        }

        vowSeq = 0;
        conSeq = 0;
        haveVow = false;
        last = -1;
        flag = false;

        for (int i = 0; i < pw.size(); i++){
            int temp = pw[i];

            if (isVow(temp)){   
                haveVow = true;
                vowSeq++;
                conSeq = 0;

                if (vowSeq >= 3){
                    flag = true;
                    break;
                }
            }
            else{
                vowSeq = 0;
                conSeq++;
                
                if (conSeq >= 3){
                    flag = true;
                    break;
                }
            }

            if (last == temp && !(temp == 'o' || temp == 'e')){
                flag = true;
                break;
            }

            last = temp;
        }

        if (!haveVow){
            flag = true;
        }

        if (flag){
            cout << "<" + pw + "> is not acceptable.\n";
        }
        else{
            cout << "<" + pw + "> is acceptable.\n";
        }
    }

    return 0;
}