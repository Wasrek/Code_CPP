import math
n = input("")
a = n.split(",")
num=int(a[0]+a[1]+a[2])
a0=int(math.floor(num/(10**(len(a[1])+len(a[2])))))
num-=a0*10**(len(a[1])+len(a[2]))
a1=int(math.floor(num/10**len(a[2])))
num-=a1*10**(len(a[2]))
a2=num
d1=int(10**len(a[1]))
d2=int((10**len(a[2]))-1)
u1=int(a1)
u2=int((10**len(a[2]))-1)
u3=int(a2)
ans1=u1*u2+u3
ans2=d1*d2
div = int(math.gcd(d1,math.gcd(u1,u3)))
d1=d1//div
u1=u1//div
u3=u3//div
ans1=u1*u2+u3
div = int(math.gcd(d2,u3))
d2=d2//div
u2=u2//div
u3=u3//div
ans1 = u1*u2+u3
ans2 = d1*d2
div = int(math.gcd(ans1,ans2))
ans1=ans1//div
ans2=ans2//div
ans1+=(ans2*a0)
print(int(ans1) , "/" , int(ans2))