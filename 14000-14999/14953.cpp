#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 300000)개의 간선으로 이루어진 연결 그래프가 주어진다.
이때, 주변 정점의 개수가 오름차순으로 증가하는 경로 가운데 가장 긴 것의 길이를 구한다.

해결 방법 : 각 정점을 주변 정점의 개수가 적은 순서대로 정렬한 다음, 순서대로 주변 정점 가운데
가장 경로의 길이가 긴 정점 + 1을 계산해 나간다. 그 후 가장 길이가 긴 정점의 경로 길이를 출력한다.

주요 알고리즘 : 그래프 이론, DP, 정렬

출처 : Daejeon 2017 C번
*/

int vsize[103000], nsort[103000], mem[103000];
vector<int> ed[103000];

int cmp1(const void* a, const void* b) {
    int ai = vsize[*(int*)a];
    int bi = vsize[*(int*)b];
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, a, b, r = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
        vsize[a]++;
        vsize[b]++;
    }
    for (int i = 0; i < n; i++) nsort[i] = i;
    qsort(nsort, n, sizeof(int), cmp1);

    for (int i = 0; i < n; i++) {
        a = nsort[i];
        mem[a] = 1;
        for (int j : ed[a]) {
            if (vsize[j] < vsize[a] && mem[j] + 1 > mem[a]) mem[a] = mem[j] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mem[i] > r) r = mem[i];
    }
    if (r <= 0) return 1;
    printf("%d", r);
    return 0;
}