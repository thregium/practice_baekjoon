#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 5000)���� ����� �ְ�, �� ����� ���� ��簡 �� �� �ִ� ������� �־�����.
�̶�, ����鰣�� ���踦 �����ؼ� Ʈ�� ���·� ����� �׶��� ������ ���ؾ� �Ѵ�. Ʈ������ ��� ����� ������ �ڿ������� �ϰ�,
��� �ڽ� ���(�ٷ� ���� �ܰ� ���)�� ������ �պ��� Ŀ�� �Ѵ�. �ʿ��� ������ �ּڰ��� ���Ѵ�.
��, �׻� Ʈ���� ���� �� �ִ� ��츸 �־�����.

�ذ� ��� : ��� ������ Ʈ������ ���ο� ��尡 �߰��� ���� ���� ��ȭ�� �����غ��� ��尡 �߰��� ����
�� ����� ������ŭ ������ �������ٴ� ����� �� �� �ִ�. ����, �׻� ���ο� ��带 Ʈ���� �ִ��� ���� ����
���̴� ���� �̵��� �Ǵµ�, �̷��� ������δ� BFS�� �ִ�.

ó���� �� ����鿡 ���� ���ϰ� �� �� �ִ� ������� �������� ������ ����,
N�� ���� �ѹ��� BFS�� ���� �ش� ����� ��Ʈ�� �ϴ� Ʈ���� BFS�� �����.
���� ��� ������� ������ �� ���ٸ� Ʈ���� ���� �� �����Ƿ� �Ѿ��.
��� ������� ���� �����ϴٸ� �׶��� ��� ����� ������(��Ʈ ��尡 1) ���� ���� Ȯ���� �ᱣ���� ���ϴٰ�
�ּڰ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ���Ʈ ����

��ó : BtOI 2016 1��
*/

int level[5120];
vector<int> ed[5120];
queue<int> q;

int bfs(int n, int x) {
    int r = 0;
    level[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (!level[i]) {
                level[i] = level[x] + 1;
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (level[i] == 0) return -1;
        else r += level[i];
    }
    return r;
}

int main(void) {
    int n, k, x, r = INF;
    //freopen("E:\\PS\\Olympiad\\Baltic\\2016\\day1_tests\\bosses\\t.in.6", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            ed[x].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) level[j] = 0;
        x = bfs(n, i);
        if (x < 0) continue;
        else if (x < r) r = x;
    }
    printf("%d", r);
    return 0;
}