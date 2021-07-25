#include <stdio.h>
#include <ctype.h>

/*
문제 : N(N <= 36)이 주어지고, N 미만인 자연수 N * N개가 36진법으로 주어진다. 이때, 이 자연수들이 가로나 세로로 겹치지 않는지 확인하고,
겹치지 않는다면, 다시 맨 왼쪽/윗줄이 정렬된 상태인지 구한다.

해결 방법 : 두 가지에 대해 직접 구한다. 겹치는 수가 없는지는 카운팅 배열을 사용하면 되고,
정렬된 상태인지는 2번째 수부터 순서대로 이동하며 앞쪽 수보다 작지 않은지 확인하면 된다.

주요 알고리즘 : 구현

출처 : PacNW 2017 O번
*/

int sqr[64][64], cnt[64];

int main(void) {
    int n, r = 1;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &c);
            if (isdigit(c)) sqr[i][j] = c - '0';
            else if (isupper(c)) sqr[i][j] = c - 'A' + 10;
            else return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cnt[j] = 0;
        for (int j = 0; j < n; j++) {
            cnt[sqr[i][j]]++;
            if (cnt[sqr[i][j]] > 1) r = 0;
        }
        for (int j = 0; j < n; j++) cnt[j] = 0;
        for (int j = 0; j < n; j++) {
            cnt[sqr[j][i]]++;
            if (cnt[sqr[j][i]] > 1) r = 0;
        }
    }
    if (!r) {
        printf("No");
    }
    else {
        for (int i = 1; i < n; i++) {
            if (sqr[0][i] <= sqr[0][i - 1] || sqr[i][0] <= sqr[i - 1][0]) r = 0;
        }
        if (r) printf("Reduced");
        else printf("Not Reduced");
    }
    return 0;
}