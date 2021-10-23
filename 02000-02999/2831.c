#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 절댓값이 1500 이상 2500 이하의 정수들로 이루어진 두 배열이 주어진다.
이때, 각 배열에서 음수인 수들은 다른 배열에서 절댓값이 해당 수보다 작은 수와 짝을 지을 수 있고,
양수인 수들은 다른 배열에서 절댓값이 해당 수보다 큰 수와 짝을 지을 수 있을 때, 양쪽이 서로 짝을 지을 수 있는 쌍을 최대한
많이 만들었을 때의 쌍의 수를 구한다.

해결 방법 : 양쪽이 서로 짝을 지을 수 있기 위해선 한 쪽의 수는 음수이고 다른 한 쪽의 수는 양수여야 한다.
따라서, 먼저 양쪽 배열의 수를 짝을 지을 수 있는 쌍끼리 음수와 양수를 구분해 입력받는다.
그 다음, 각 배열을 정렬하고, 지을 수 있는 짝의 수를 확인한다. 지을 수 있는 짝의 수는 작은 쪽 부터 배열을 확인하면서
해당 수보다 큰 값 가운데 가장 작은 값을 확인하는 것으로 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 투 포인터

출처 : COCI 11/12#1 4번
*/

int mf[2][103000], fm[2][103000];
int mfs[2], fms[2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, r = 0, p = 0;
    //freopen("E:\\PS\\Contest\\COCI\\11-12\\contest1_testdata\\ples\\ples.in.10a", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > 0) mf[0][mfs[0]++] = x;
        else fm[0][fms[0]++] = -x;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x < 0) mf[1][mfs[1]++] = -x;
        else fm[1][fms[1]++] = x;
    }
    qsort(mf[0], mfs[0], sizeof(int), cmp1);
    qsort(mf[1], mfs[1], sizeof(int), cmp1);
    qsort(fm[0], fms[0], sizeof(int), cmp1);
    qsort(fm[1], fms[1], sizeof(int), cmp1);

    for (int i = 0; i < mfs[0]; i++) {
        while (p < mfs[1] && mf[0][i] >= mf[1][p]) p++;
        if (p++ < mfs[1]) r++;
        else break;
    }
    p = 0;
    for (int i = 0; i < fms[1]; i++) {
        while (p < fms[0] && fm[1][i] >= fm[0][p]) p++;
        if (p++ < fms[0]) r++;
        else break;
    }
    printf("%d", r);
    return 0;
}
