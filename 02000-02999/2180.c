#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 200000)���� ȭ�縦 �����ؾ� �Ѵ�. �� ���� ���µ� �ɸ��� �ð��� ������� �ҿ�� �ð� * a + b��� �������� ������.
�̵��ϴµ��� �ð��� �ɸ��� �ʴ´ٸ� ���� ���µ� �ʿ��� �ּ� �ð��� ���Ѵ�. a�� b�� ���� �ƴ� 40000 ������ �����̴�.

�ذ� ��� : �� ȭ�縦 �����ϴµ� �켱������ Ȯ���غ��� a / b�� ū ���� �켱�� �Ǵ� ���� �� ������ �� �� �ִ�.
�̸� ��ü ȭ�翡 �����غ��� a / b ������ ������ �صΰ� ������� ȭ�縦 ������ ���� �ð��� ���ϸ� �ȴ�.
��, �� �������� a�� b�� ��� 0�� ȭ�翡 ���ؼ��� ����ó���� ����� �Ѵ�. ���� ó���ǵ� ��� ���� ������
������ ���� �ٲپ� �ָ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ����
*/

int fires[204800][2], chk[16], perm[16];
long long correct = 1234567890987654321;

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int bx = *(int*)b;
    int ay = *((int*)a + 1);
    int by = *((int*)b + 1);
    if (ax == 0 && ay == 0) ay = 1;
    if (bx == 0 && by == 0) by = 1;
    int r = ay * bx - ax * by;
    return r;
}

void check(int n) {
    long long r = 0;
    for (int i = 0; i < n; i++) {
        r = (r + fires[perm[i]][0] * r + fires[perm[i]][1]);
    }
    if (r < correct) correct = r;
}

int track(int n, int x) {
    if (n == x) {
        check(n);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        perm[x] = i;
        chk[i] = 1;
        track(n, x + 1);
        chk[i] = 0;
    }
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &fires[i][0], &fires[i][1]);
    }
    qsort(fires, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        r = (r + fires[i][0] * r + fires[i][1]) % 40000;
    }
    printf("%d", r);
    
    /*
    scanf("%d", &n);
    for (long long i = 0; i < 100; i++) {
        for (int j = 0; j < n; j++) {
            fires[j][0] = (rand() & 15);
            fires[j][1] = (rand() & 15);
        }
        correct = 1234567890987654321;
        r = 0;
        track(n, 0);
        qsort(fires, n, sizeof(int) * 2, cmp1);
        for (int j = 0; j < n; j++) {
            r = (r + fires[j][0] * r + fires[j][1]);
        }
        if (r != correct) {
            printf("ERROR! at %d ---- %lld : %lld\n", i, r, correct);
            for (int j = 0; j < n; j++) {
                printf("%d %d / ", fires[j][0], fires[j][1]);
            }
            printf("\n");
        }
    }
    */
    return 0;
}