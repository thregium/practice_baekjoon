#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <unordered_map>
using namespace std;

/*
���� : 40�� ������ ��Ʈ�� �̷���� ���ڿ��� �־�����. �̶�, �� �ܰ踶�� ������ K�� ���ؼ� K��
���� ��Ʈ�� 1�̰ų� ���� ��Ʈ�� 1�� ��� 1�� �ǵ��� �� ��, ��� ��Ʈ�� 1�� ���� �� �ִ� ��
Ȯ���ϰ�, �׷��� ��� �׷��� �ϱ� ���� �ʿ��� �ּ� �ܰ� ���� ���Ѵ�.

�ذ� ��� : BFS�� �ð� ���� ���ư��� ���� �����ϴ�. ��, ��Ʈ����ŷ�� ���� �ð��� �����ؾ� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ��Ʈ����ŷ

��ó : CERC 2018 C��
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