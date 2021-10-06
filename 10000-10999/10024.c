#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 길이 N(N <= 100)의 1부터 N까지의 자연수로 이루어진 순열 2개가 주어질 때, 첫 순열을 두 번째 순열로 바꾸기 위해
각 수들을 사이클 형태로 정렬을 하려고 한다. 어떠한 수가 있다면 그 수가 들어갈 자리로 옮기고 그 수가 있던
자리에 있는 수를 다시 옮기는 것을 반복하여 해당하는 사이클을 정리하는 방식이다.
이때, 사이클의 개수와 가장 긴 사이클의 크기를 구한다. 길이 1의 사이클은 포함하지 않는다.
사이클이 없다면 두 번째에 -1을 출력한다.

해결 방법 : 문제에 주어진대로 구현한다. 아직 방문하지 않은 위치가 나오면 옮길 위치로 옮기는 것을 반복해야 하므로
두 번째 순열의 위치를 각 원소별로 미리 저장해둔다. 방문하지 않은 위치가 나올 때 마다 옮겨야 하는지 확인하고
옮겨야 한다면 사이클의 개수를 1 늘리고, 사이클을 따라간다.

주요 알고리즘 : 구현

출처 : USACO 2014M B1번
*/

int a[128], b[128], order[128], vis[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("reorder.in", "r");
        fo = fopen("reorder.out", "w");
    }
    int n, shift = 0, longest = -1, len = 0, cur, nxt;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        order[b[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (order[a[i]] == i) continue;
        cur = i;
        len = 0;
        while (!vis[cur]) {
            nxt = order[a[cur]];
            vis[cur] = 1;
            cur = nxt;
            len++;
        }
        shift++;
        if (len > longest) longest = len;
    }
    printf("%d %d", shift, longest);
    return 0;
}