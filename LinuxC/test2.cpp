#include <stdio.h>

int main() {
#if 0
    unsigned int i = 0, dec = 0;
    char bin[20];

    printf("input\n");
    scanf("%[01]", bin);

    for (i = 0; i < 20; i++)
        printf("bin[%d]= %c\n", i, bin[i]);

    i = 0;
    while (bin[i]) {
        dec += bin[i] - '0';
        if (bin[++i])
            dec <<= 1;
    }

    printf("result = %d\n", dec);

#endif
    unsigned int temp = 0x11223344;
    unsigned char* ptr = &temp;


#if 1
    printf("Address of temp = 0x%p  ::: Value of temp = 0x%p\n\n", ptr, temp);
    printf(" PTR ro gye-san !! \n");
    printf("**************************************\n");

    for (int cnt = 0; cnt < 4; cnt++) {
        printf("Current ptr = 0x%p   ::::  ", ptr);
        printf("ptr[%d] = 0x%p\n", cnt, *ptr++);
    }



    printf("\n\n");
    ptr = &temp;



    printf(" ARRAY ro gye-san !! \n");
    printf("**************************************\n");

    for (int cnt = 0; cnt < 4; cnt++) {
        printf("ptr[%d] = 0x%p\n", cnt, ptr[cnt]);
    }


#endif
    return 0;
}