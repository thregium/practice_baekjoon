#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������ �̷���� �迭�� Ȧ���� ������������, ¦���� ������������ �����Ѵ�.
�̶�, Ȧ���� ¦���� ������ �����ؾ� �Ѵ�. �־����� ������ +- 1000 �̳� ������ �ִ�.

�ذ� ��� : �迭�� Ȧ���� ¦���� ���� �� ���� �����Ѵ�. �׸��� �ٽ� ���� �迭�� ���ƿͼ� Ȧ ¦ ���θ� Ȯ���ϸ� ��ġ�� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : GGCT 2014A C2�� // GKS 2013A A2��
*/

int s[1024], odd[1024], even[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, o, e;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        o = 0, e = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            if (s[i] & 1) odd[o++] = s[i];
            else even[e++] = s[i];
        }
        qsort(odd, o, sizeof(int), cmp1);
        qsort(even, e, sizeof(int), cmp2);
        o = 0, e = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] & 1) s[i] = odd[o++];
            else s[i] = even[e++];
        }
        printf("Case #%d: ", tt);
        for (int i = 0; i < n; i++) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
    return 0;
}