#include<stdio.h>
#include<string.h>
int main(){
int q,i,l,f,x;
char d[15],ans[50],ch=0;
scanf("%d",&q);
for(i=0;i<q;i++)
{
    scanf(" %s",d);
    scanf("%d",&f);
    l=strlen(d);
    if(l>10){ch=1;}//0=48
    if((d[0]<48 || d[0]>51)|| (d[1]<48 || d[1]>57) || d[2]!=47 || (d[3]<48 || d[3]>49) || (d[4]<48 || d[4]>57)
       || d[5]!=47 || (d[6]<49 || d[6]>50)|| (d[7]<48 || d[7]>57) || (d[8]<48 || d[8]>57) || (d[9]<48 || d[9]>57))
    {
        ch=1;
    }
    if(d[0]==51 && d[1]>50){ch=1;}//30up
    if(d[0]==48 && d[1]==48){ch=1;}
    if(ch){printf("No");}else{
    if(f==2){
        for(x=0;x<2;x++){printf("%c",d[x]);}
        printf(" ");
        if(d[3]=='0'){
            if(d[4]=='1'){printf("January");}else
            if(d[4]=='2'){printf("February");}else
            if(d[4]=='3'){printf("March");}else
            if(d[4]=='4'){printf("April");}else
            if(d[4]=='5'){printf("May");}else
            if(d[4]=='6'){printf("June");}else
            if(d[4]=='7'){printf("July");}else
            if(d[4]=='8'){printf("August");}else
            if(d[4]=='9'){printf("September");}

        }else
        {
            if(d[4]=='0'){printf("October");}else
            if(d[4]=='1'){printf("November");}else
            if(d[4]=='2'){printf("December");}
        }
        printf(", ");
        for(x=6;x<10;x++){printf("%c",d[x]);}

    }else
    if(f==3){
            if(d[3]=='0'){
            if(d[4]=='1'){printf("January");}else
            if(d[4]=='2'){printf("February");}else
            if(d[4]=='3'){printf("March");}else
            if(d[4]=='4'){printf("April");}else
            if(d[4]=='5'){printf("May");}else
            if(d[4]=='6'){printf("June");}else
            if(d[4]=='7'){printf("July");}else
            if(d[4]=='8'){printf("August");}else
            if(d[4]=='9'){printf("September");}

        }else
        {
            if(d[4]=='0'){printf("October");}else
            if(d[4]=='1'){printf("November");}else
            if(d[4]=='2'){printf("December");}
        }
         printf(" ");

        for(x=0;x<2;x++){printf("%c",d[x]);}

        printf(", ");
        for(x=6;x<10;x++){printf("%c",d[x]);}

    }else


    if(f==4){
        for(x=0;x<2;x++){printf("%c",d[x]);}
        printf(" ");
        if(d[3]=='0'){
            if(d[4]=='1'){printf("January");}else
            if(d[4]=='2'){printf("February");}else
            if(d[4]=='3'){printf("March");}else
            if(d[4]=='4'){printf("April");}else
            if(d[4]=='5'){printf("May");}else
            if(d[4]=='6'){printf("June");}else
            if(d[4]=='7'){printf("July");}else
            if(d[4]=='8'){printf("August");}else
            if(d[4]=='9'){printf("September");}

        }else
        {
            if(d[4]=='0'){printf("October");}else
            if(d[4]=='1'){printf("November");}else
            if(d[4]=='2'){printf("December");}
        }
        printf(", ");
        for(x=8;x<10;x++){printf("%c",d[x]);}

    }





    }

}


}
