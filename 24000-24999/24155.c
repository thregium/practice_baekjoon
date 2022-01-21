#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ����(0 <=, <= 100, ����)�� �־��� ��, ���� ������� ������ ���Ѵ�.
������ ��� �������� ����ϰ� ���� ������ ������� ����.

�ذ� ��� : ����, ������ ������ ������ �迭�� �����ϰ� ���� ������ ������ ����,
������ ���ϰ�(�迭 ��ȣ�� ���ϵ�, �հ� ���� ��� �հ� ���� ����), �ٽ� ���� ������ ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : JOIC 06/07 1-1��
*/

int score[103000][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i][0]);
        score[i][1] = i;
    }
    qsort(score, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        score[i][2] = i + 1;
        if (i > 0 && score[i][0] == score[i - 1][0]) score[i][2] = score[i - 1][2];
    }
    qsort(score, n, sizeof(int) * 3, cmp2);
    for (int i = 0; i < n; i++) {
        printf("%d\n", score[i][2]);
    }
    return 0;
}