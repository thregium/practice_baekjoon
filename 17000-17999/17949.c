#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 10^6 이하의 16진수 문자열이 주어질 때, 이를 N(N <= 500000)개의 특정 길이로 잘라 변환한
문자열의 10진수 값을 각각 구한다. 단, 변환한 10진수 값은 항상 음수가 되지 않는다.

해결 방법 : N개의 길이가 나올 때 마다 각각의 원하는 길이만큼 새 문자열에 자른 다음, 해당 문자열에 strtoll 함수를 통해
10진수 값을 알아내면 된다.

주요 알고리즘 : 문자열, 파싱

출처 : 한양대 6회B C번
*/

char cy[1048576], mv[32], buf[32];

int main(void) {
    int n, p = 0;
    long long r = -1;
    scanf("%s", cy);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        if (buf[0] == 'c') {
            for (int j = 0; j < 2; j++) mv[j] = cy[p + j];
            mv[2] = '\0';
            r = strtoll(mv, NULL, 16);
            p += 2;
        }
        else if (buf[0] == 'i') {
            for (int j = 0; j < 8; j++) mv[j] = cy[p + j];
            mv[8] = '\0';
            r = strtoll(mv, NULL, 16);
            p += 8;
        }
        else if (buf[0] == 'l') {
            for (int j = 0; j < 16; j++) mv[j] = cy[p + j];
            mv[16] = '\0';
            r = strtoll(mv, NULL, 16);
            p += 16;
        }
        else return 2;
        if (p > 0 && cy[p - 1] == '\0') return 3;
        if (r < 0) return 1;
        printf("%lld ", r);
    }
    return 0;
}