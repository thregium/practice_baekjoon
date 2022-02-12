#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : N(N <= 20)개의 컵의 색과 반지름 또는 지름이 순서 없이 주어진다. 수가 먼저 나오면 지름이고,
나중에 나오면 반지름이다. 이때, 각 컵을을 반지름이 커지는 순으로 정렬하여 출력한다.
모든 컵의 반지름과 색은 다르며, 모든 컵의 색은 소문자로 이루어진 20자 이하의 단어며,
반지름은 1000 이하의 자연수이다.

해결 방법 : 모든 컵들의 색과 반지름을 구조체로 묶어서 저장한다. 각 줄을 입력받을 때 마다
반지름과 지름 여부를 확인한 다음, 구조체에 각 컵의 색과 반지름을 파싱한다. 그리고 이 구조체들을
반지름 오름차순으로 정렬하여 출력하면 된다.

주요 알고리즘 : 문자열, 파싱, 정렬

출처 : Rocky 2016 I번
*/

typedef struct cup {
    char color[32];
    int rad;
} cup;

char buff1[32], buff2[32];
cup c[32];

int cmp1(const void* a, const void* b) {
    int ai = ((cup*)a)->rad;
    int bi = ((cup*)b)->rad;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", buff1, buff2);
        if (isdigit(buff1[0])) {
            c[i].rad = strtoll(buff1, NULL, 10) / 2;
            strcpy(c[i].color, buff2);
        }
        else {
            c[i].rad = strtoll(buff2, NULL, 10);
            strcpy(c[i].color, buff1);
        }
    }
    qsort(c, n, sizeof(cup), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%s\n", c[i].color);
    }
    return 0;
}