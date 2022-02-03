/*
    TASK:Dot
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
// pair<int,int> p;
// set <pair<int,int>> s;
// int main()
// {
//     int n,a,b;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++){
//         scanf("%d %d",&p.first,&p.second);
//         s.insert(p);
//     }
//     printf("%d\n",s.size());
//     return 0;
// }
//ใช้ set ทำ ทำmem เกิน ติด X type ของset ถ้าเป็น struct ต้องเขียน func hash เพิ่ม
int a[1010][1010];
int main()
{
	int n,x,y,now=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&x,&y);
		if(!a[x][y])now++;
        a[x][y]=1;
	}
	printf("%d",now);
	return 0;
}