#include <stdio.h>
#include <string.h>

int main() {
    char a[50] = "i am sam from florida";
    char b[50];
    int flag = 0; 
    int opc=0;

    printf("Enter the pattern you want to match: ");
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = '\0';

    int len_a = strlen(a);
    int len_b = strlen(b);

    for (int i = 0; i <= len_a - len_b; ++i) { 
        flag = 1; 
        for (int j = 0; j < len_b; ++j) {
            opc++;
            if (a[i + j] != b[j]) { 
                flag = 0; 
                break;
            }
        }
        if (flag == 1) { 
            printf("Pattern found at index: %d\n", i);
            break;
        }
    }

    if (flag == 0) { 
        printf("Pattern not found\n");
    }
    printf("Operation count is: %d",opc);
    return 0;
}
