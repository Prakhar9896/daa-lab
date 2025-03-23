#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
    char a[50];
    char b[50];
    int flag = 0;

    printf("Enter the string: ");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0';  
    printf("Enter the pattern you want to match: ");
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = '\0';

    int len_a = strlen(a);
    int len_b = strlen(b);

    int table[256];

    for (int i = 0; i < 256; i++)
    {
        table[i]=len_b;
    }

    for (int i = 0; i < len_b-1; i++)
    {
        if (table[i]!=len_b)
        {
            continue;
        }
 
        table[(int)b[i]]=len_b-i-1;
    }
    int i=len_b-1;
    int j=len_b-1;
    while(i<=len_a){
        if (a[i]!=b[j])
        {
            i+=table[a[i]];
            j=len_b-1;
            continue;
        }

        if(j==0){
            flag=1;
            break;
        }

        i--;
        j--;
    }

    if (flag==1)
    {
        printf("pattern found at index: %d",i);
    }

    else printf("pattern not found");
    return 0;

}