/*
    TASK:Silly Bakery
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
    int n,q,w=0,fb=0,fc=0,fd=0,fe=0,l,a1,b1,c1,d1,e1,a=0,b=0,c=0,d=0,e=0;
    scanf(" %d",&n);
    for(q=0;q<n;q++)
    {
        scanf(" %d %d %d %d %d",&a1,&b1,&c1,&d1,&e1);
        a=a+a1;
        b=b+b1;
        c=c+c1;
        d=d+d1;
        e=e+e1;
    }
    printf("%d %d %d %d %d\n",a,b,c,d,e);
        w=w+a;
        if(b%4==0)
        {
            w=w+((b*3)/4);//เต็มก้อน
        }else
        if(b>4)
        {
            w=w+(b/4*3);
            fb=b%4;
        }else{fb=b;}//fbรอรวม 1/4 ไม่ก็ 1/8

        if(c%2==0)
        {
            w=w+(c/2);//เต็มก้อน
        }else
        if(c>2)
        {
            w=w+(c/2);
            fc=c%2;
        }else{fc=c;}//รวม 1/4 1/8

        if(d%4==0)
        {
            w=w+(d/4);//เต็มก้อน
        }else
        if(d>4)
        {
            w=w+(d/4);
            fd=d%4;
        }else{fd=d;}

        if(e%8==0)
        {
            w=w+(e/8);//เต็มก้อน
        }else
        if(e>8)
        {
            w=w+(e/8);
            fe=e%8;
        }else{fe=e;}
//-----------------------------------------------------------------------------------------------
        //แทน 1/4 3/4
        if(fb<=fd)
        {
            w=w+fb;
            fd=fd-fb;
            fb=0;
        }else
        if(fb>fd && fd!=0)
        {
            w=w+fd;
            fb=fb-fd;
            fd=0;
        }
        //1/8 3/4
        if(fb<=(fe/2))
        {
            w=w+fb;
            fe=fe-(fb*2);
            fb=0;
        }else
        if(fb>(fe/2) && fe!=0)
        {
            w=w+(fe/2);
            fb=fb-(fe/2);
            fe=0;
        }
        //1/2
        //1/2 1/4
        if(fc<=(fd/2))
        {
            w=w+fc;
            fd=fd-(fc*2);
            fc=0;
        }else
        if(fc>(fd/2) && fd!=0)
        {
            w=w+(fd/2);
            fc=fc-(fd/2);
            fd=0;
        }
        //1/2 1/8
        if(fc<=(fe/4))
        {
            w=w+fc;
            fe=fe-(fc*4);
            fc=0;
        }else
        if(fc>(fe/4) && fe!=0)
        {
            w=w+(fe/4);
            fc=fc-(fe/4);
            fe=0;
        }

        //1/4 1/8
        if(fd<=(fe/6))
        {
            w=w+fd;
            fe=fe-(fd*6);
            fd=0;
        }else
        if(fd>(fe/6) && fe!=0)
        {
            w=w+(fe/6);
            fd=fd-(fe/6);
            fe=0;
        }
        l=(fb*3/4)+(fc/2)+(fd/4)+(fe/8);
        if(l%1==0)
        {
            w=w+l;
        }else
        if(l>0)
        {
            w=w+l+1;
        }

        printf("%d",w);


    return 0;
}
