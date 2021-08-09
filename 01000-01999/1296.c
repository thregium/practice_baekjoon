#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 50)명 가운데 가장 궁합이 잘 맞는 사람 중 알파벳 순으로 가장 빠른 사람을 찾는다. (궁합 점수 설명 생략)

해결 방법 : 두 사람의 이름에 있는 L, O, V, E의 개수를 센 다음 궁합 점수를 계산한 다음 가장 높은 사람을 찾으면 된다.
이때, 알파벳순으로 빠른 사람을 찾아야 하기 때문에 정렬한 다음 순서대로 찾는 것이 좋다.

주요 알고리즘 : 구현, 문자열, 정렬
*/

char oms[32], girls[64][32];

int main(void) {
    int n, r = 0;
    long long l, o, v, e, p, rp = -1;
    scanf("%s%d", oms, &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", girls[i]);
    }
    qsort(girls, n, sizeof(char) * 32, strcmp);
    for (int i = 0; i < n; i++) {
        l = 0, o = 0, v = 0, e = 0;
        for (int j = 0; oms[j]; j++) {
            if (oms[j] == 'L') l++;
            if (oms[j] == 'O') o++;
            if (oms[j] == 'V') v++;
            if (oms[j] == 'E') e++;
        }
        for (int j = 0; girls[i][j]; j++) {
            if (girls[i][j] == 'L') l++;
            if (girls[i][j] == 'O') o++;
            if (girls[i][j] == 'V') v++;
            if (girls[i][j] == 'E') e++;
        }
        p = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;
        if (p > rp) {
            r = i;
            rp = p;
        }
    }
    printf("%s", girls[r]);
    return 0;
}