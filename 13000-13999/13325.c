#include <stdio.h>

/*
문제 : 높이 K(K <= 20)인 포화 이진 트리에서 각 간선의 가중치(<= 1000)가 주어질 때,
루트에서 모든 리프 노드로 이동하는 경로의 가중치를 같도록 각 간선의 가중치를 증가시켰을 때,
전체 간선의 가중치 합이 최소라면 그때의 전체 간선의 가중치 합을 구한다.

해결 방법 : 각 노드별로 해당 노드로 가는 간선과 그 이하 간선들의 가중치 합을 구하고,
양쪽 합을 같도록 맞춰주는 연산을 반복하면 풀 수 있다. 맞춰주며 가중치 배열은 따로 관리해 둔다.

주요 알고리즘 : DP

출처 : Daejeon 2016I A번
*/

int a[2621440], mem[2621440];

int main(void) {
    int n, l;
    long long r = 0;
    scanf("%d", &n);
    l = (2 << n) - 2;
    for (int i = 2; i <= l + 1; i++) {
        scanf("%d", &a[i]);
        mem[i] = a[i];
    }
    for (int i = (l >> 1); i >= 1; i--) {
        if (mem[i << 1] > mem[(i << 1) + 1]) {
            a[(i << 1) + 1] += mem[i << 1] - mem[(i << 1) + 1];
        }
        else if (mem[i << 1] < mem[(i << 1) + 1]) {
            a[i << 1] += mem[(i << 1) + 1] - mem[i << 1];
        }
        for (int j = i << 1; j <= l; j <<= 1) mem[i] += a[j];
    }
    for (int i = 2; i <= l + 1; i++) {
        r += a[i];
    }
    printf("%lld", r);
    return 0;
}