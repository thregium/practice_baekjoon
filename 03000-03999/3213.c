#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 10000)개의 1/4 단위로 된 조각들이 주어질 때, 조각을 합치지 않고 주어진 모든 것을 하기 위한 전체의 수를 구한다.

해결 방법 : 큰 조각부터 채워나간다. 그 동안 필요한 전체의 수를 구하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : CHCI 2004N1S 1번
*/

char buff[8];
int cnt[4];

int main(void) {
    int n, r = 0, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "1/4")) cnt[1]++;
        else if (!strcmp(buff, "1/2")) cnt[2]++;
        else if (!strcmp(buff, "3/4")) cnt[3]++;
        else return 1;
    }
    while (cnt[1] + cnt[2] + cnt[3] > 0) {
        c = 0;
        if (cnt[3]) {
            cnt[3]--;
            c += 3;
        }
        while (c <= 2 && cnt[2] > 0) {
            cnt[2]--;
            c += 2;
        }
        while (c <= 3 && cnt[1] > 0) {
            cnt[1]--;
            c++;
        }
        r++;
    }
    printf("%d", r);
    return 0;
}