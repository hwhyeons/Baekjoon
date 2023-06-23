#include <stdio.h>
#define LEN_INPUT 11

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    int i = 0;
    while (1) {
        if (s1[i] == '\0') break;
        printf("%c\n",s1[i]);
        i++;
    }
    return 0;
}
