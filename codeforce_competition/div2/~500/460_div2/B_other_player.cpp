#include<stdio.h>
main()
{
    int a,b,p,c,d,e,x,n,q,t=0;
    long long w[10009];
    scanf("%d",&n);
        
    for(x=0;x<=1;x++)
    for(p=0;p<=9;p++)
    for(q=0;q<=9;q++)
    for(a=0;a<=9;a++)
    for(b=0;b<=9;b++)
    for(c=0;c<=9;c++)
    for(d=0;d<=9;d++)
    for(e=0;e<=9;e++)
    {
        
        if(a+b+c+d+e+q+p+x==10){
            t++;
            w[t]=e+d*10+c*100+b*1000+a*10000+q*100000+p*1000000+x*10000000; 
        }
        if(t==10000){
        e=10;d=10;c=10;b=10;a=10;q=10;p=10;x=10;
            //return 0;
        }
    }
        printf("%lld\n",w[n]);
}
