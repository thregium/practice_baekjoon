#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 마을이 일직선상에 있다. 각 마을의 좌표는 절댓값이 10^9 이하인 정수이며,
살고 있는 인원수는 10^9명 이하의 자연수이다. 이때, 수직선상에 각 인구와의 거리 합이 최소가 되는
지점 가운데 가장 왼쪽에 있는 점을 찾는다.

해결 방법 : 점을 옮길 때 인구와의 거리 합을 생각해보면 그 점의 양쪽 인구수가 같아야 함을 알 수 있다.
따라서, 좌표 순서대로 정렬한 다음 왼쪽 인구수의 합이 전체의 절반 이상이 되는 첫 지점을 찾아 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬
*/

int post[103000][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long sum = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &post[i][0], &post[i][1]);
        sum += post[i][1];
    }
    qsort(post, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        cnt += post[i][1];
        if (cnt * 2 >= sum) {
            printf("%d", post[i][0]);
            return 0;
        }
    }
    return 1;
}