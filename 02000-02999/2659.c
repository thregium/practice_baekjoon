#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� ������� 4���� ����(1 ~ 9)�� ���� ���� ��, �ð�������� 4���� ���� ���� �� �� ���� ���� ���� �ð� ���� �Ѵٸ�
�־��� ���� ������� �ð� ���� �� ��°�� ���� �ð� ������ ���Ѵ�.

�ذ� ��� : 4���� ���� ������ ��� ���տ� ���� �ð� ���� ����� ����.
�� ����, ������� �ð� ���� �����ϰ� �ߺ��� ���� ���� ���� �����. �� �迭���� �־��� ���� ���� �ð� ����
�� ��°���� ã���� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����, ����

��ó : ���� 1997 ��2��
*/

int clock[10240], nclock[10240], arr[4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int p = 0, best = 103000, t;
    for (arr[0] = 1; arr[0] <= 9; arr[0]++) {
        for (arr[1] = 1; arr[1] <= 9; arr[1]++) {
            for (arr[2] = 1; arr[2] <= 9; arr[2]++) {
                for (arr[3] = 1; arr[3] <= 9; arr[3]++) {
                    best = 103000;
                    for (int i = 0; i < 4; i++) {
                        t = 0;
                        for (int j = 0; j < 4; j++) {
                            t *= 10;
                            t += arr[(j + i) % 4];
                        }
                        if (t < best) best = t;
                    }
                    clock[(arr[0] - 1) * 729 + (arr[1] - 1) * 81 + (arr[2] - 1) * 9 + (arr[3] - 1)] = best;
                }
            }
        }
    }
    qsort(clock, 6561, sizeof(int), cmp1);
    for (int i = 0; i < 6561; i++) {
        if (i > 0 && clock[i] == clock[i - 1]) continue;
        else nclock[p++] = clock[i];
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 4; i++) {
        t = 0;
        for (int j = 0; j < 4; j++) {
            t *= 10;
            t += arr[(j + i) % 4];
        }
        if (t < best) best = t;
    }
    for (int i = 0; i < p; i++) {
        if (best == nclock[i]) {
            printf("%d", i + 1);
            return 0;
        }
    }
    return 1;
}