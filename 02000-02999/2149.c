#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 10자 이하의 키 값과 100자 이하의 암호문이 주어질 때, 이 암호를 복호화한 결과를 구한다.
암호문의 길이는 키 값의 자연수배이다. 암호는 키와 평문을 같은 줄 단위로 나열한 다음,
키를 기준으로 안정적인 오름차순 정렬을 한 결과를 좌종서로 읽는 방식으로 구한다.

해결 방법 : 구조체 정렬을 통해 정렬한 각 줄이 원래 줄에서 몇 번째 줄인지 구하고,
곱셈과 나눗셈 연산을 통해 암호문의 위치에서 평문의 위치로 옮길 지역을 찾아서 옮긴 다음, 복호화한 평문을 출력하면 된다.

주요 알고리즘 : 구현, 문자열, 정렬

출처 : ECRC 2003 A번
*/

typedef struct ki {
    char c;
    int pos;
} ki;

char key[16], crypt[128], uncry[128];
ki ka[16];

int cmp1(const void* a, const void* b) {
    ki ak = *(ki*)a;
    ki bk = *(ki*)b;
    if (ak.c != bk.c) return ak.c > bk.c ? 1 : -1;
    else return ak.pos > bk.pos ? 1 : ak.pos == bk.pos ? 0 : -1;
}

int main(void) {
    int kl, h;
    scanf("%s", key);
    kl = strlen(key);
    for (int i = 0; i < kl; i++) {
        ka[i].c = key[i];
        ka[i].pos = i;
    }
    qsort(ka, kl, sizeof(ki), cmp1);
    scanf("%s", crypt);
    if (strlen(crypt) % kl) return 1;
    h = strlen(crypt) / kl;
    for (int i = 0; crypt[i]; i++) {
        uncry[(i % h) * kl + ka[i / h].pos] = crypt[i];
    }
    printf("%s", uncry);
    return 0;
}