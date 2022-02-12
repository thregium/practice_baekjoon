#include <stdio.h>

/*
문제 : N(N <= 1000)명의 사람들이 하루동안 도서관을 이용한 기록이 시:분:초 형태로 주어진다.
이때, 가장 많은 사람이 도서관을 이용한 순간의 이용자 수를 구한다.
들어가거나 나가는 순간도 이용한 순간으로 생각한다.

해결 방법 : 주어진 값들을 초 단위로 변환한 다음 1차원 배열에 이용한 기록들을 추가해 나간다.
가장 많이 사용한 순간을 배열에서 찾아서 이용자 수를 출력하면 된다.

주요 알고리즘 : 구현

출처 : JBOI 2007 5번
*/

int count[103000];

int main(void) {
    int n, hi, mi, si, ho, mo, so, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d:%d:%d", &hi, &mi, &si, &ho, &mo, &so);
        for (int j = hi * 3600 + mi * 60 + si; j <= ho * 3600 + mo * 60 + so; j++) count[j]++;
    }
    for (int i = 0; i < 103000; i++) {
        if (count[i] > res) res = count[i];
    }
    printf("%d", res);
    return 0;
}