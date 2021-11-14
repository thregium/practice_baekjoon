#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 1000)개의 숫자로 이루어진 문자열에서 0부터 올라가며 각 수들을 찾을 때, 찾을 수 없는 첫 수를 구한다.

해결 방법 : 아무리 커도 3자리 수 이내로는 답이 나오는 것을 알 수 있다. 따라서, 문자열에서 1부터 올라가며
수들을 직접 찾아보다 보면 빠른 시간 내로 찾을 수 있다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : Tsukuba 2015 A번
*/

char d[1024], nd[1024];

void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &d[i]);
    }
    for (int i = 0;; i++) {
        p = 0;
        for (int j = i; j; j /= 10) nd[p++] = j % 10 + '0';
        if (i == 0) nd[p++] = '0';
        nd[p] = '\0';
        for (int j = 0, k = p - 1; j < k; j++, k--) swap(&nd[j], &nd[k]);
        if (strstr(d, nd) == NULL) {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}