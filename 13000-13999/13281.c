#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ��ǥ���� �־�����, �� ��ǥ������ ���ĺ� �빮�ڰ� ���� �ִ�. �̶�, 1���� �ϴ� �ĺ��� �ִ� �� ���ϰ�,
�ִٸ� �� �ĺ��� 1���� Ȯ���� ��ǥ�� ��ȣ��, ���ٸ� TIE�� ����Ѵ�.

�ذ� ��� : �� ��ǥ������ ��ǥ�� �ĺ��� ��ǥ���� 1 �ø��� ������ �����Ѵ�. �׸��� �Ź� 1�� �ĺ��� 2�� �ĺ��� ������
Ȯ���� ����, ���� ��ǥ�� ������ ������ �׶��� �ĺ��� ��ǥ�� ��ȣ�� ����Ѵ�. ������ �׷��� ���� ���ٸ�
TIE�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ����

��ó : JDC 2016 B��
*/

int cand[26][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r;
    char c;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < 26; i++) {
            cand[i][0] = 0;
            cand[i][1] = i;
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf(" %c", &c);
            for (int j = 0; j < 26; j++) {
                if (c - 'A' == cand[j][1]) cand[j][0]++;
            }
            qsort(cand, 26, sizeof(int) * 2, cmp1);
            if (cand[0][0] - cand[1][0] > n - i - 1 && !r) {
                printf("%c %d\n", cand[0][1] + 'A', i + 1);
                r = 1;
            }
        }
        if (r == 0) printf("TIE\n");
    }
    return 0;
}