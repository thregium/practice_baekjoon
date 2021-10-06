#include <stdio.h>
#include <stdlib.h>
#define SZ 4096

/*
문제 : N(N <= 3000)개의 점이 있고, 각 점에는 각각의 값이 있다. 이때, 좌표축에 평행한 직사각형 형태로 특정한 구역을 골라
해당 지점 내의 모든 점의 값들의 합이 최대가 되게 하려고 한다면, 그때의 합을 구한다.

해결 방법 : 먼저 각 점들을 좌표 압축 해 준다. 각 시작 행과 각 끝 행에 대해 해당 구간의 부분 최대 합을 빠르게 구할 수
있다면 답을 시간 내에 얻을 수 있다. 세그먼트 트리를 이용하면 한 시작 행에 대해 모든 끝 행의 부분 최대 합을
O(NlogN)에 구할 수 있고, 따라서, 전체의 최대도 O(N^2logN)에 그할 수 있다.

세그먼트 트리를 이용해 부분 최대 합을 구하는 방법은 각 구간의 수 합에 대해 세그먼트 트리로 먼저 부분 합을 저장한다.
그 다음, 각 노드마다 해당 구간의 맨 왼쪽 부분에서 시작하는 부분 최대 합과 맨 오른쪽 부분에서 시작하는 부분 최대 합,
전체 구간의 부분 최대 합을 각각 구한다. 왼쪽과 오른쪽에서 시작하는 부분 최대 합은 (왼쪽 또는 오른쪽의 합) + 
(왼쪽/오른쪽의 오른쪽/왼쪽 부분 최대 합)과 (왼쪽/오른쪽의 왼쪽/오른쪽의 부분 최대 합) 중 더 큰 값이다.
전체 최대 합은 (왼쪽/오른쪽의 전체 최대 합 중 더 큰 것)과 (왼쪽의 오른쪽 부분 최대 합 + 오른쪽의 왼쪽 부분 최대 합)
가운데 더 큰 것이다. 리프노드에서는 네 값 모두 해당 위치의 원래 값과 같다.

각 위치의 값은 스위핑을 통해 빠르게 찾아낼 수 있다. 전체 점은 N개 뿐이므로 전체 점들을 행 순서로 정렬시킨 뒤,
해당 행에 있는 점들의 값을 배열에 더한 뒤, 세그먼트 트리를 업데이트 하면 되는 것이다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 분할 정복, 스위핑, 좌표 압축

출처 : 정올 2014 중4번
*/

int xs[3072][3], ys[3072][3], gold[3072]; //X좌표, Y좌표(원래 값, 원래 번째, 압축된 값), 각 좌표에 있던 값
long long seg[SZ * 2][4]; //합, 왼쪽 최대 부분합, 오른쪽 최대 부분합, 전체 최대 부분합

long long big(long long a, long long b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void segreset(void) {
    for (int i = 0; i < SZ * 2; i++) {
        for (int j = 0; j < 4; j++) seg[i][j] = 0;
    }
}

void segupd(int p, int x) {
    for (int i = 0; i < 4; i++) {
        seg[SZ + p][i] += x;
    }
    for (int i = ((SZ + p) >> 1); i > 0; i >>= 1) {
        seg[i][0] = seg[i << 1][0] + seg[(i << 1) + 1][0];
        seg[i][1] = big(seg[i << 1][1], seg[i << 1][0] + seg[(i << 1) + 1][1]);
        seg[i][2] = big(seg[(i << 1) + 1][2], seg[(i << 1) + 1][0] + seg[i << 1][2]);
        seg[i][3] = big(big(seg[i << 1][3], seg[(i << 1) + 1][3]), seg[i << 1][2] + seg[(i << 1) + 1][1]);
    }
}

int main(void) {
    int n, sx, xp;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &xs[i][0], &ys[i][0], &gold[i]);
        xs[i][1] = i, ys[i][1] = i;
    }
    //좌표 압축
    qsort(xs, n, sizeof(int) * 3, cmp1);
    qsort(ys, n, sizeof(int) * 3, cmp1);
    xs[0][2] = 1, ys[0][2] = 1;
    for (int i = 1; i < n; i++) {
        if (xs[i][0] == xs[i - 1][0]) xs[i][2] = xs[i - 1][2];
        else xs[i][2] = xs[i - 1][2] + 1;
        if (ys[i][0] == ys[i - 1][0]) ys[i][2] = ys[i - 1][2];
        else ys[i][2] = ys[i - 1][2] + 1;
    }
    sx = xs[n - 1][2];
    qsort(xs, n, sizeof(int) * 3, cmp1);
    qsort(ys, n, sizeof(int) * 3, cmp2);
    

    for (int i = 1; i <= sx; i++) {
        segreset(); //세그먼트 트리를 초기화한다.
        xp = 0;
        while (xs[xp][2] < i) xp++; //첫 값 이전의 값은 무시한다.
        for (int j = i; j <= sx; j++) {
            while (xs[xp][2] == j) {
                segupd(ys[xs[xp][1]][2], gold[xs[xp][1]]); //해당 행의 값을 배열에 더한 다음 세그먼트 트리를 업데이트한다.
                xp++;
            }
            if (seg[1][3] > r) r = seg[1][3]; //만약 해당 행 구간의 부분합 최댓값이 더 크다면 결괏값을 업데이트한다.
        }
    }
    printf("%lld", r);
    return 0;
}