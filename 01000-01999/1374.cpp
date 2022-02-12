#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� ���� ���۰� �� �ð�(<= 10^9)�� �־��� ��, ��� ���Ǹ� ���ǽǿ��� �ϱ� ����
�ʿ��� ���ǽ� �ּ� ������ ���Ѵ�. �� �ð��� ���� �ð����� ���İ�, ���ǽ� ����� ������ ����
���� ���Ǹ� �ϴ� ���� �����ϴ�.

�ذ� ��� : ���ǵ��� ���� �ð� ������� ������ ����, �켱���� ť�� ����� ���� ���ǽǵ���
�� �ð��� ���� ������� �����صд�. �� �ð��� ���� ������ ���� �ð� ������ ���
�� ���ǽ��� ����ϰ�, ���Ķ�� ���ο� ���ǽǿ��� ���Ǹ� �ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť
*/

int lect[103000][2];
priority_queue<int, vector<int>, greater<int>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &lect[i][0], &lect[i][1]);
    }
    qsort(lect, n, sizeof(int) * 2, cmp1);

    for (int i = 0; i < n; i++) {
        if (pq.size() == 0 || pq.top() > lect[i][0]) {
            pq.push(lect[i][1]);
            r++;
        }
        else {
            pq.pop();
            pq.push(lect[i][1]);
        }
    }
    printf("%d", r);
    return 0;
}