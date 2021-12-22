#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 일 있다. 각 일의 수행 시간(<= 1000)과 마감일(<= 10^6)이 주어질 때, 마감 이내에 모든 일을
하기 위해 일을 시작해야 하는 최소 날을 구한다. 단, 한번에 한 일만 할 수 있다.
불가능한 경우 -1을 출력한다.

해결 방법 : 각 일 마감일의 역순으로 정렬한 후, 그 일을 하려면 시작해야 하는 날을 확인한다.
만약 시작해야 하는 날 이후에 끝난다면 시작해야 하는 날에서 수행 시간을 빼고, 그 외에는 마감일에서 수행 시간을 뺀다.
첫 번째 일의 시작일까지 확인한 후 그 날을 출력하면 된다. 단, 답이 음수인 경우에는 -1을 출력해야 한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2008N S3번
*/

int hw[1048576][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &hw[i][1], &hw[i][0]);
    }
    qsort(hw, n, sizeof(int) * 2, cmp1);
    r = hw[0][0] - hw[0][1];
    for (int i = 1; i < n; i++) {
        if (hw[i][0] < r) r = hw[i][0] - hw[i][1];
        else r -= hw[i][1];
    }
    printf("%d", r < 0 ? -1 : r);
    return 0;
}