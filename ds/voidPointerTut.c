#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
        /*int x = 3;*/
        const char* str = "hello";
        const void *data = str;
        printf("%s\n", (char *)data);

        return 0;
}
