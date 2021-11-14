#include <stdio.h>

/*
문제 : N(N <= 1000)개의 정점으로 이루어진 이진 트리의 전위, 중위 순회가 주어지면 후위 순회를 출력한다.

해결 방법 : 전위 순위에서 구간의 첫 부분이 루트임과 중위 순회에서 서브트리가 양쪽으로 나누어짐을 이용한다.
처음에는 전체 구간에서 서브 트리를 나누어가며 순회를 하면 된다. 후위 순회이므로 마지막에 출력을 해야 한다.

주요 알고리즘 : 분할 정복, 트리

출처 : Daejeon 2013 L번
*/

int in[1024], pr[1024];

void find(int si, int ei, int sp, int ep) {
    int t = -1, r = pr[sp];
    for (int i = si; i <= ei; i++) {
        if (in[i] == r) {
            t = i;
            break;
        }
    }
    if (t > si) find(si, t - 1, sp + 1, sp + (t - si));
    if (t < ei) find(t + 1, ei, sp + (t - si + 1), ep);
    printf("%d ", r);
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &pr[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }
        find(0, n - 1, 0, n - 1);
        printf("\n");
    }
    return 0;
}