/*
    TASK:Sequence Sort
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > a;//vector = array 1 dimension vector of vector is 2 dimensions array
vector<int> b;
int main()
{

    int n,m,i,j,num;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&num);
            b.push_back(num);
        }
        a.push_back(b);
        b.clear();//for b to get the number from new lines
    }
    sort(a.begin(),a.end());
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
        printf("%d ",a[i][j]);
    printf("\n");
    }
}
