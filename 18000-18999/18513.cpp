#include <stdio.h>
#include <queue>
#include <unordered_map>
using namespace std;

/*
���� : �������� N(N <= 100000)���� ���� ���� �ִ�. �� K(K <= 100000)���� ���� ����
N���� ���� ��ġ�� �ʰ� ���ε� ��ġ�� �ʰ� �ϸ鼭 N���� ���� �Ÿ� ���� �ּҰ� �ǵ��� ��ġ�� ��,
N���� ������ �Ÿ� ���� ���Ѵ�.

�ذ� ��� : N���� ������ BFS�� �� ������ �Ÿ��� ���� ���ϸ� �ȴ�. ��, BFS �������� �Ϲ� �迭�δ�
�Ÿ� �迭�� �����ϱ� �����Ƿ� �ؽø��� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �ؽø�
*/

unordered_map<int, int> dist;
queue<int> q;

int main(void) {
    int n, k, x;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        q.push(x);
        dist.insert({ x, 0 });
    }
    while (k > 0) {
        x = q.front();
        q.pop();
        if (dist.find(x + 1) == dist.end()) {
            k--;
            r += dist[x] + 1;
            dist.insert({ x + 1, dist[x] + 1 });
            q.push(x + 1);
        }
        if (k <= 0) break;
        if (dist.find(x - 1) == dist.end()) {
            k--;
            r += dist[x] + 1;
            dist.insert({ x - 1, dist[x] + 1 });
            q.push(x - 1);
        }
    }
    printf("%lld", r);
    return 0;
}