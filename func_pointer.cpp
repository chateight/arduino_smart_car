#include <stdio.h>
#include <stdlib.h>

void start()
{
    printf("Start\n");
}

void save()
{
    printf("Save\n");
}

void end()
{
    printf("End\n");
    exit(0);
}

void (*menu[3])() =
{
    start, save, end
};

int main()
{
    while(1){
        int i = getchar();
        i -= '0' + 1;
        if( 0 <= i && i < 3 )
            menu[i]();
    }

    return 0;
}
