#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 N(N <= 20000)의 1부터 N까지의 자연수로 이루어진 순열이 5개 주어진다. 이때, 각 순열들은 원래 순열에서
한 수를 임의의 다른 위치로 옮긴 것이라고 하면, 원래의 순열을 구한다. 한 번 옮겨진 수는 다른 순열에서는 옮겨지지 않는다.

해결 방법 : 전체 순열에서 두 수를 비교했을 때, 원래 순열과 순서가 바뀌는 경우는 5개의 순열 가운데 많아야 2번 뿐이다.
(두 수 중 하나는 이동해야 하므로) 따라서, 5번의 순열에서 각각의 위치를 기록한 다음, 정렬하며 두 수의 위치를 비교한다.
5번의 비교 가운데 더 많이 나온 쪽을 맞는 것으로 보고 해당 순서로 정렬한 다음 정렬된 순열을 출력하면 된다.

주요 알고리즘 : 애드 혹, 정렬

출처 : USACO 2011D B2번
*/

int pos[5][20480], res[20480];
int n;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int r = 0;

    for (int i = 0; i < 5; i++) {
        if (pos[i][ai] > pos[i][bi]) r++;
        else r--;
    }
    return r;
}

int main(void) {
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2011_12\\photo_bronze\\I.6", "r", stdin);
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2011_12\\photo_bronze\\O_t.6", "w", stdout);
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            pos[i][x] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        res[i] = i + 1;
    }
    qsort(res, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}