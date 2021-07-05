#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : ��� ������ ��ȣ���� �Ÿ��� �־��� ��, �� ������ ������Ű�� ������ ���� ���� �ּڰ��� ���Ѵ�.
�׷��� ���� ������ ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : ���� ª�� �Ÿ����� ���ʴ�� ���캸�� �ִܰŸ��� Ȯ���Ѵ�. ���� �ش� �� ���� ���� �Ÿ��� �־��� �Ÿ��� ���ٸ�
������ �߰����� �ʰ� �Ѿ��. �� �ִٸ� ������ �߰��ϰ� �Ѿ��. �� ª�� ���� ����̹Ƿ� -1�� ����Ѵ�.
�ִܰŸ��� ���ͽ�Ʈ�� ���� �˰����� �̿��Ѵ�.
�̸� �ݺ��� ��� ������ ���� Ȯ���� ���� �ᱣ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, �׸��� �˰���
*/

int dists[512][3], tdist[32];
int dip = 0;
vector<pair<int, int>> road[32];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, d, p, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &d);
            if (i >= j) continue;
            dists[dip][0] = d;
            dists[dip][1] = i;
            dists[dip][2] = j;
            dip++;
        }
    }
    qsort(dists, dip, sizeof(int) * 3, cmp1);
    for (int i = 0; i < dip; i++) {
        for (int j = 0; j < n; j++) {
            tdist[j] = INF;
        }
        pq.push(pair<int, int>(0, dists[i][1]));
        while (pq.size()) {
            p = pq.top().second;
            d = pq.top().first;
            pq.pop();
            if (d >= tdist[p]) continue;
            tdist[p] = d;
            for (auto rd : road[p]) {
                pq.push(pair<int, int>(d + rd.first, rd.second));
            }
        }
        if (tdist[dists[i][2]] == dists[i][0]) continue;
        else if (tdist[dists[i][2]] < dists[i][0]) {
            printf("-1");
            return 0;
        }
        r += dists[i][0];
        road[dists[i][1]].push_back(pair<int, int>(dists[i][0], dists[i][2]));
        road[dists[i][2]].push_back(pair<int, int>(dists[i][0], dists[i][1]));
    }
    printf("%d", r);
    return 0;
}