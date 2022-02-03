/*
    TASK:Blowblock
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > a,b,c,d;
int main()
{
    int n,i,j,num,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&num);
            if(i%2==0&&j%2==0) a.push_back(num);//แถวคู่หลักคู่
            if(i%2==0&&j%2==1) b.push_back(num);
            if(i%2==1&&j%2==0) c.push_back(num);
            if(i%2==1&&j%2==1) d.push_back(num);
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    for(i=0;i<a.size();i++)
        ans+=(a[i]*b[i]*c[i]*d[i]);
    printf("%d\n",ans);
    return 0;

}
