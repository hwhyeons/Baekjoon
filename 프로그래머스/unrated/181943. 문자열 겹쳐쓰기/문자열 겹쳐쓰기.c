#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, const char* overwrite_string, int s) {
    int len1 = strlen(my_string);
    int len2 = strlen(overwrite_string);
    char* answer = (char*)malloc(sizeof(char)*(len1+len2+2));
    strcpy(answer,my_string);
    for (int i =0; i<len2; i++) {
        answer[s+i] = overwrite_string[i];
    }
    return answer;
}