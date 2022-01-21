#include <stdio.h>

/*
문제 : N(N <= 100000)개의 5지선다 문제가 있고, 정답과 답을 맞춘 문제들의 목록이 주어질 때,
인접한 두 문제의 답이 다르도록 하는 답안을 출력한다. 연속으로 답을 맞춘 두 문제의 답이
같은 경우는 주어지지 않는다.

해결 방법 : 앞에서부터 차례로 문제를 확인해 나간다. 만약 답을 맞췄다면 정답을 그대로 답안으로 하고,
틀린 경우 정답 + 1번을 선택해본다. 만약 양 옆(오른쪽은 그 문제를 맞춘 경우만)과 답이 같다면
계속해서 +1을 반복하다가 모두와 다른 경우가 나오면 그것을 답안으로 한다.
모든 문제의 답안을 정한 후 출력하면 된다.

주요 알고리즘 : 애드 혹, 구성적

출처 : UNIST 3회 A번
*/

int corr[103000], succ[103000], res[103000];

int main(void) {
    int n, m, x;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &corr[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        succ[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (succ[i]) res[i] = corr[i];
        else {
            res[i] = res[i - 1] % 5 + 1;
            while (corr[i] == res[i] || res[i] == res[i - 1] || (succ[i + 1] && res[i] == corr[i + 1])) {
                res[i] = res[i] % 5 + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}