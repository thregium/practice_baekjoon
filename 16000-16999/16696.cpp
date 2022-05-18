#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <unordered_map>
using namespace std;

/*
문제 : 40개 이하의 비트로 이루어진 문자열이 주어진다. 이때, 각 단계마다 임의의 K를 정해서 K개
이전 비트가 1이거나 현재 비트가 1인 경우 1이 되도록 할 때, 모든 비트를 1로 만들 수 있는 지
확인하고, 그러한 경우 그렇게 하기 위해 필요한 최소 단계 수를 구한다.

해결 방법 : BFS로 시간 내에 돌아가는 것이 가능하다. 단, 비트마스킹을 통해 시간을 절약해야 한다.

주요 알고리즘 : 그래프 이론, BFS, 비트마스킹

출처 : CERC 2018 C번
*/

char s[128];
unordered_map<long long, int> dist;
queue<long long> q;

int bfs(long long x, int n) {
    long long y;
    int d;
    q.push(x);
    dist.insert({ x, 0 });
    while (q.size()) {
        x = q.front();
        d = dist[x];
        if (x == (1LL << n) - 1) return d;
        q.pop();
        for (int i = 1; i < n; i++) {
            y = x;
            for (int j = i; j < n; j++) y |= ((x >> (j - i)) & 1LL) << j;
            if (dist.find(y) != dist.end()) continue;
            if (y == (1LL << n) - 1) return d + 1;
            dist.insert({ y, d + 1 });
            q.push(y);
        }
    }
    return -1;
}

int main(void) {
    int n;
    long long x = 0;
    scanf("%s", s);
    if (s[0] == '0') {
        printf("-1");
        return 0;
    }
    n = strlen(s);
    for (int i = 0; i < n; i++) x += ((long long)s[i] - '0') << i;
    printf("%d", bfs(x, n));
    return 0;
}