#include <bits/stdc++.h>
using namespace std;

string pw;
int vowSeq, conSeq;
bool haveVow, flag;
int last;

bool isVow(int idx){
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true)
    {
        cin >> pw;
        if (pw == "end")
        {
            break;
        }

        vowSeq = 0;
        conSeq = 0;
        haveVow = false;
        last = -1;
        flag = false;

        for (int i = 0; i < pw.size(); i++)
        {
            int temp = pw[i];

            if (isVow(temp))
            {   
                haveVow = true;
                vowSeq++;
                conSeq = 0;

                if (vowSeq >= 3)
                {
                    flag = true;
                }
            }
            else
            {
                vowSeq = 0;
                conSeq++;
                
                if (conSeq >= 3)
                {
                    flag = true;
                }
            }

            if (i > 0 && last == temp && (last != 'o' && last != 'e'))
            {
                if (last != 'o' && last != 'e')
                {
                    flag = true;
                }
            }

            last = temp;
        }

        if (!haveVow)
        {
            flag = true;
        }

        if (flag)
        {
            cout << "<" + pw + "> is not acceptable.\n";
        }
        else
        {
            cout << "<" + pw + "> is acceptable.\n";
        }
    }

    return 0;
}