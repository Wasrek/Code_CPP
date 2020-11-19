#include<stdio.h>
int main() {
int x=5,y=7;
printf("%d",x++ +y);//x++ +y=12 หลังจากนี้ค่าx=6
x=5;
y=7;
printf("\n%d",x+ ++y);
}
