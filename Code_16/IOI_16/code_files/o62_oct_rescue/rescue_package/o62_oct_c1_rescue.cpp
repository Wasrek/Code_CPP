#include <iostream>
#include <bits/stdc++.h>
#include "rescuelib.h"

using namespace std;

int R,C,nc,nr,ul,ur,dl,dr;

void atr(int uu,int dd,int l){
    nc=((uu+dd-(R-1))/2)+l;
    nr=uu-(nc-l)+1;
    return ;
}

void atl(int uu,int dd,int l){
    nc=l-((uu+dd-(R-1))/2);
    nr=uu-(l-nc)+1;
    return ;
}

void hau(int ll,int rr, int l,int CC){
    nr=((ll+rr)-(CC-1))/2+1;
    nc=(ll-(nr-1))+l;
    return ;
}

void had(int ll,int rr,int l,int CC){
    nr=((ll+rr)-(CC-1))/2+1;
    nc=(ll-(nr-1))+l;
    nr=R-nr+1;
    return ;    
}

int ty(){
    if(ul!=-1 && dl==-1 && ur==-1 && dr==-1) return 1;
    if(ul==-1 && dl!=-1 && ur!=-1 && dr!=-1) return 2;
    if(ul==-1 && dl!=-1 && ur==-1 && dr==-1) return 3;
    if(ul!=-1 && dl==-1 && ur!=-1 && dr!=-1) return 4;
    if(ul==-1 && dl==-1 && ur!=-1 && dr==-1) return 6;
    if(ul!=-1 && dl!=-1 && ur==-1 && dr!=-1) return 5;
    if(ul==-1 && dl==-1 && ur==-1 && dr!=-1) return 8;
    if(ul!=-1 && dl!=-1 && ur!=-1 && dr==-1) return 7;
}

int main()
{
    get_size(R,C);
    int dis,l,r,mid,n,uu,dd,t;
    ul=drop_robot(1,1);
    ur=drop_robot(1,C);
    dl=drop_robot(R,1);
    dr=drop_robot(R,C);
    if(ul!=-1 && ur!=-1 && dl!=-1 && dr!=-1){
        atr(ul,dl,1);
        answer(nr,nc);
    }
    if(ul==-1 && dl==-1 && ur!=-1 && dr!=-1){
        atl(ur,dr,C);
        answer(nr,nc);
    }
    if(ur==-1 && dr==-1 && ul!=-1 && dl!=-1){
        atr(ul,dl,1);
        answer(nr,nc);
    }
    if(ul==-1 && ur==-1 && dl!=-1 && dr!=-1){
        had(dl,dr,1,C);
        answer(nr,nc);
    }
    if(dl==-1 && dr==-1 && ul!=-1 && ur!=-1){
        hau(ul,ur,1,C);
        answer(nr,nc);
    }
    t=ty();
    // printf("%d\n",t);
    if(t%2==0){
        l=0,r=C+1;
        while(l<r){
            mid=(l+r)/2;
            if(t%4!=0) n=drop_robot(1,mid);
            else n=drop_robot(R,mid);
            if(n==-1){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        if(t==2 || t==4){
            uu=drop_robot(1,l);
            dd=drop_robot(R,l);
            if(t==2){
                if(dl<dr) atl(uu,dd,l);
                else atr(uu,dd,r);
            }else{
                if(ul<ur) atl(uu,dd,l);
                else atr(uu,dd,r);
            }
        }else if(t==6){
            uu=drop_robot(1,l);
            hau(uu,ur,l,C-l+1);
        }else{
            uu=drop_robot(R,l);
            had(uu,dr,l,C-l+1);
        }
        // printf("%d %d\n",nr,nc);
        answer(nr,nc);
    }else {
        l=0,r=C+1;
        while(l<r){
            mid=(l+r+1)/2;
            if(t==1 || t==5) n=drop_robot(1,mid);
            else n=drop_robot(R,mid);
            if(n==-1){
                r=mid-1;
            }else{
                l=mid;
            }
        }
        if(t==5 || t==7){
            uu=drop_robot(1,l);
            dd=drop_robot(R,l);
            if(t==5){
                if(dl<dr) atl(uu,dd,l);
                else atr(uu,dd,l);
            }else{
                if(ul<ur) atl(uu,dd,l);
                else atr(uu,dd,l);
            }
        }else if(t==1){
            uu=drop_robot(1,l);
            // printf("%d %d %d\n",ul,uu,l,1);
            hau(ul,uu,1,l);
        }else{
            uu=drop_robot(R,l);
            had(dl,uu,1,l);
        }
        // printf("%d %d\n",nr,nc);
        answer(nr,nc);
    }
    return 0;
}
