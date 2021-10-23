#include <stdio.h>
#include <stdlib.h>

/*
���� : �� ���� ���ǽǿ� N(N <= 10000)���� ���ǰ� ���� �� �ִ�. �� ���� �ð��� 30000 ������ ���� �ƴ� ���� �����̶� �� ��,
���� �ð��� �ִ밡 �ǵ��� �����ϴ� ����� ���Ѵ�.

�ذ� ��� : ���Ǹ� ���� �ð� �������� ������ ����, ������� ���Ǹ� Ȯ���ϸ� ���ǰ� ������ �ð��� ���� ���� ������
�ð��� �����ذ��� ���̳��� ���α׷����� �����Ѵ�. �̶�, ���� �ð����� ���� �ð��� ���� �۴ٸ�
���� �ð��� ������ ���� �ٲ���� �Ѵ�.

�ֿ� �˰��� : DP, ����

��ó : POI 1996/1997S3 6��
*/

int lec[10240][2], mem[32768];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, p = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lec[i][0], &lec[i][1]);
    }
    lec[n][0] = 32767;
    qsort(lec, n + 1, sizeof(int) * 2, cmp1);

    for (int i = 0; i <= n; i++) {
        while (p < lec[i][0]) {
            p++;
            if (mem[p] < mem[p - 1]) mem[p] = mem[p - 1];
        }
        if (i == n) break;
        if (mem[p] + (lec[i][1] - lec[i][0]) > mem[lec[i][1]]) mem[lec[i][1]] = mem[p] + (lec[i][1] - lec[i][0]);
    }
    printf("%d", mem[32767]);
    return 0;
}