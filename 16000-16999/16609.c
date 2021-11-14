#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)개의 헬륨통 용량(0<=, <= N)이 주어질 때, 용량이 1부터 N까지인 풍선을 터뜨리지 않고
헬륨을 채웠을 때 헬륨의 비율이 가장 낮은 풍선의 비율을 구한다. 터뜨리지 않는 방법이 없다면 impossible을 출력한다.
헬륨이 용량을 넘어가면 터진다.

해결 방법 : 헬륨통을 용량이 작은 것부터 오름차순으로 정렬한 다음, 풍선의 용량과 비교한다.
풍선의 용량보다 큰 것이 있다면 impossible을 출력하고, 그 외에는 헬륨의 비율을 찾아서 가장 낮은 것의 비율을 출력하면 된다.

주요 알고리즘 : 정렬

출처 : NWERC 2018 I번
*/

int c[103000 * 2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    double r = 1.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (c[i] > i + 1) r = -1.0;
        else if ((double)c[i] / (i + 1.0) < r) r = (double)c[i] / (i + 1.0);
    }
    if (r < 0) printf("impossible");
    else printf("%.9f", r);
    return 0;
}