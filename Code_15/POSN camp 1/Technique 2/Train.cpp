/*
    TASK:Train
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
list<int> l;
list<int>::iterator it;
char a[10];
int main()
{
    int n,num;
    scanf("%d",&n);
    l.push_back(999);
    it = l.begin();
    while(n--){
        scanf(" %s",a);
        if(!strcmp(a,"call"))
            printf("%d\n",*it);
        else if(a[0]=='h')
            it=l.begin();
        else if(a[0]=='t'){
            it = l.end();
            it--;
        }
        else if(a[0]=='n'){
            it++;
            if(it==l.end())it--;
        }
        else if(a[0]=='l'){
            for(list<int>::iterator i=it;i!=l.end();i++)
                printf("%d ",*i);
            printf("\n");
            it = l.end();
            it--;
        }
        else if(a[0]=='r'){
            it++;
            if(it==l.end())it++;
            else{
                it=l.erase(it);
                it--;
            }
        }
        else if(a[0]=='a'){
            scanf("%d",&num);
            l.insert(++it,num);
            it--;it--;
        }
    }

    return 0;
}
