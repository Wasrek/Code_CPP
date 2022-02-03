/*
TASK: Printer
LANG: CPP
AUTHOR: PeaTT~
*/
#include <bits/stdc++.h>
using namespace std;
list <string> l;
list <string>::iterator it;
int n;
char c;
string s;
int main()
{
    cin >> n;
    it = l.end();
    while(n--){
        cin >> c;
        if(c=='i'){
            cin >> s;
            l.insert(it, s);
        }
        else if(c=='l' && it!=l.begin())
            it--;
        else if(c=='r' && it!=l.end())
            it++;
        else if(c=='b' && it!=l.begin() && !l.empty())
            it = l.erase(--it);
        else if(c=='d' && it!=l.end() && !l.empty())
            it = l.erase(it);
    }
    for(list <string>::iterator i = l.begin(); i!=l.end(); i++){
        cout << *i << " ";
    }
    cout << "\n";
    return 0;
}
