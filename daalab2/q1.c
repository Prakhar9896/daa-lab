#include<stdio.h>
int main(){
    int m,n,gcd;
    int opc=0;
    printf("enter the two numbers: ");
    scanf("%d %d",&m,&n);

    for (int i = m>n ? n:m; i >0; i--)
    {
        opc++;
        if (m%i==0 && n%i==0)
        {
            gcd=i;
            break;
        }
    }
    printf("the gcd of two number is: %d",gcd);
    printf("\nOperation count: %d",opc);
    return 0;
}