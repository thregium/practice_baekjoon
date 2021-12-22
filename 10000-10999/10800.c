#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)개의 컬러볼이 있다. 각 컬러볼은 Ci(Ci <= N)가지 색상으로 이루어져 있으며, 
크기는 Si(Si <= 2000) 이하다. 이때, 각 컬러볼이 자신의 색과 다른 색이며 크기가 자신보다 작은 컬러볼을 잡을 수 있다면,
각 컬러볼마다 잡을 수 있는 컬러볼의 크기 합을 구한다.

해결 방법 : 먼저 컬러볼들을 크기 순(오름차순)으로 정렬해준다. 그리고 크기 순으로 컬러볼들을 확인한다.
이 때 같은 크기인 구간을 투 포인터로 찾아서 한번에 확인해야 한다. 해당 구간에서 먼저 각 컬러볼이 잡을 수 있는
컬러볼의 크기 합을 구한다. 이는 해당 구간 이전까지의 컬러볼 크기 합 - 해당 구간 이전까지의 같은 색인 컬러볼 크기 합과 같다.
그리고 난 후 다시 해당 구간에 대해 컬러볼 크기 합을 업데이트해준다. 색상별 크기 합과 전체 크기 합에 해당 컬러볼의
크기를 더해주면 된다.
전체 작업이 끝난 후 구해둔 잡을 수 있는 컬러볼의 크기 합을 각각 출력하면 된다.

주요 알고리즘 : 정렬, 스위핑, 투 포인터, 누적 합

출처 : 정올 2015지 초4/고2번
*/

int ball[204800][3], csum[204800], res[204800];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ball[i][0], &ball[i][1]);
        ball[i][2] = i;
    }
    qsort(ball, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        e = i;
        for (int j = i; j < n; j++) {
            if (ball[j][1] != ball[i][1]) break;
            e = j;
        }
        for (int j = i; j <= e; j++) {
            res[ball[j][2]] = csum[0] - csum[ball[j][0]];
        }
        for (int j = i; j <= e; j++) {
            csum[0] += ball[j][1];
            csum[ball[j][0]] += ball[j][1];
        }
        i = e;
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}