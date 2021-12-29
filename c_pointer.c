#include <stdio.h>
 
int main(void) {
    int num = 1;
    int *p_num;
    p_num = &num;
        
    printf("int型変数numのアドレス:%p\n", &num);
    printf("int型ポインタ変数p_numの値:%p\n", p_num);             // same as above(&numm)
    printf("int型変数numのアドレス先の値:%d\n", *(&num));          // "*" as a operator
    printf("int型ポインタ変数p_numの参照先アドレスの値:%d\n", *p_num);      // same as above
 
    const char str[] = "abcdefghijklm";
    for (const char *ptr = str; *ptr; ++ptr){
        printf("%c\n", *ptr);                                   // char code is UTF-8
    }

    return 0;
}
