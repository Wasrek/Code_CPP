/*
    TASK:RT_Arrange The Books
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
set<string> sett;
set<string> :: iterator it1,it2;
char a[25];
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",a);
        sett.insert(a);
        it1=sett.lower_bound(a);
        if(it1==sett.begin())
            printf("N/A ");
        else{
            it2=it1;
            it2--;
            printf("%s ",it2->c_str());
        }
        it2=it1;
        it2++;
        if(it2==sett.end())
            printf("N/A\n");
        else
            printf("%s\n",it2->c_str());
    }
    return 0;
}
