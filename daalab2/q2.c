#include <stdio.h>
#include <stdlib.h>

int* PrimeFactors(int n, int* size,int* opc) {
    int* a = (int*)malloc(100 * sizeof(int));
    int k = 0;
    *opc++;
    while (n % 2 == 0) {
        *opc++;
        a[k++] = 2;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        *opc++;
        while (n % i == 0) {
            *opc++;
            a[k++] = i;
            n /= i;
        }
    }
    *opc++;
    if (n > 2) {
        a[k++] = n;
    }

    *size = k; 
    return a;
}

void displayfactors(int* a, int size,int x) {
    printf("Prime factors of %d are: ",x);
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int m, n;
    printf("Enter the numbers: ");
    scanf("%d %d", &m,&n);

    int size1, size2,gcd=1;
    int opc=0;
    int* arr1 = PrimeFactors(m, &size1,&opc);
    int* arr2 = PrimeFactors(n, &size2,&opc);

    displayfactors(arr1, size1,m);
    displayfactors(arr2, size2,n);

    for (int i = size1; i>=0 && gcd==1; i--)
    {
        opc++;
        for (int j = size2; j >=0; j--)
        {
            opc++;
            if(arr1[i]==arr2[j]){
                gcd=arr1[i];
                break;
            }
        }
        
    }

    printf("\ngcd of %d and %d is: %d",m,n,gcd);
    printf("\noperation count: %d",opc);

    free(arr1);
    free(arr2);

    return 0;
}
