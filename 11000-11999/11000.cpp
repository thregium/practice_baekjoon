#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 200000)���� ������ �ִ�. �� ������ S���� �����ؼ� T(S < T <= 10^9)���� ������. �̶� �� �������� �� 1������
�ٸ� ������ ��ġ�� �ʰ� ��� �Ѵٸ� �ʿ��� ������ ���� ���Ѵ�. �̶�, �� ������ ������ ���ÿ� ���� �濡�� �ٸ� ������ ������ �� �ִ�.

�ذ� ��� : �� ������ ���� �ð����� ������ ���� �� ������ ������ �� ���� �� �� �ִ� ���� ã�ƺ���.
�� ������ �� �� ���� ���̶�� �ٸ� ������ �ƹ��� �����ϴ��� ������ �� �� ���� ���̱� ������ ���� �����θ� ���� �ȴ�.

�׷���, �� �������� �Ϲ����� Ž�����δ� ��� ���ǽ��� �� �ִ� ��� Ž�� �ð��� ����ġ�� ������Ƿ� �켱���� ť�� �����
������ �ð��� ���� ���� ���� ������ �ð��� �����Ѵ�. �翬�� �� ��� ������ �ð��� ���� ���� �濡 �� �� ���ٸ�
�ٸ� ��鵵 �� �� ���� ���̹Ƿ� �ð��� ������ �� �ִ�. �� �� �ִٸ� �ش� ���� �����ϰ� �� ������ �ٲٸ� �ǰ�,
�� �� ���ٸ� �켱���� ť�� ���� �߰��ϸ� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����, �켱���� ť
*/

int schedule[204800][2];
priority_queue<int, vector<int>, greater<int>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &schedule[i][0], &schedule[i][1]);
    }
    qsort(schedule, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (pq.size() && pq.top() <= schedule[i][0]) {
            pq.pop();
        }
        pq.push(schedule[i][1]);
    }
    printf("%d", pq.size());
    return 0;
}