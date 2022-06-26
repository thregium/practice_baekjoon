#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 200000)���� �ܹ��� ���� {a, b}�� ���� (1 <= a < b <= 100000)
�� ������ �°����� ���Ƿ� �ڸ��� �����ϴ� ���� �ڸ��� �������ִ� ��� ������ ����
�ʿ��� �ڸ��� ���� ���� ���Ѵ�.

�ذ� ��� : ������� �����ϴ� ��츦 �����غ��� ������ ������ ���� ��ġ�� ��� ������ ���� �ٸ� �ڸ���
���ŵ� ��찡 �־��� ���� �� �� ��ġ�� ���� �� + 1�� �ִ� �ڸ� ���� �ȴ�.
���� ���� ���� �� �������� ���ʰ� ������ �κ��� �� �������� ���� ������ ��ġ�� ���� �� + 1�� �� �� �ְ�,
�� �� �ִ��� ���� �ȴ�.
������ �ִ� ��쿡�� ��ġ ������� ������ ����, ������ �� ��ġ�� ���ذ��� �ڸ��� ���� ��쿡��
���ο� �ڸ��� ������ ������ �ȴ�. �� ��� ���� ���� ���� �ڸ� ������ ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť, ���� ��

��ó : Tsukuba 2017 I��
*/

int pass[204800][2], psums[103000], psume[103000];
priority_queue<int, vector<int>, greater<>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, res1 = 0, res2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pass[i][0], &pass[i][1]);
        psums[pass[i][0]]++;
        psume[pass[i][1]]++;
    }
    for (int i = 1; i <= 100000; i++) {
        psums[i] += psums[i - 1];
        psume[i] += psume[i - 1];
    }
    qsort(pass, n, sizeof(int) * 2, cmp1);
    
    for (int i = 0; i < n; i++) {
        if (psums[pass[i][1] - 1] - psume[pass[i][0]] > res1) {
            res1 = psums[pass[i][1] - 1] - psume[pass[i][0]];
        }
    }
    for (int i = 0; i < n; i++) {
        if (pq.size() == 0 || pq.top() > pass[i][0]) {
            pq.push(pass[i][1]);
        }
        else {
            pq.pop();
            pq.push(pass[i][1]);
        }
    }
    res2 = pq.size();

    printf("%d %d\n", res1, res2);
    return 0;
}