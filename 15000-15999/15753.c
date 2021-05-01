#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ���������� ����� �Ͼ�� X�� �����ٴ� N(N <= 100)�ϰ��� ����� �ִٰ� �Ѵ�. �̶�, �Ϻ� ����� ���ǵǾ��ٰ� �ϸ�,
����� �Ͼ �� �ִ� ���� ���� �� ���� ���� ���� �� ���� ����Ѵ�. �׷��� ���� �Ұ����ϴٸ� -1�� ����Ѵ�.

�ذ� ��� : ����� �� �ں��� ������� ������ ���鼭 ������ ����� �������� ����. �� ����, ����� �Ͼ ������ �� ����� ������
������ ����� �Ͼ ���� ����صд�. ���� ����� ��� ī���� ���� 1 �ø���. �̸� ����� �� �ձ��� �ݺ��Ѵ�.
�߰��� �Ұ����� ��찡 ���� ��� -1�� ����ϰ�, ������ �������� ��� ���� ���� �� ���� ī������ ���� ����.
���� ���� �� ���� ī���� ���� ������ ����� �Ͼ ���� �𸣴� ���� ���� ���� ���� ����.

�ֿ� �˰��� : ����

��ó : USACO 2018F B3��
*/

int log[128], last[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("taming.in", "r");
        fo = fopen("taming.out", "w");
    }
    int n, r = 1, c1 = 1, c2 = 0;
    scanf("%d", &n);
    last[1] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &log[i]);
    }
    for (int i = n; i > 0; i--) {
        if (log[i] >= 0) {
            if (last[i] && last[i] != i - log[i]) {
                r = 0;
            }
            else if (!last[i]) {
                if (!last[i - log[i]]) c1++;
                for (int j = i - log[i]; j <= i; j++) {
                    last[j] = i - log[i];
                }
            }
        }
    }
    if (!r) {
        printf("%d", -1);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!last[i]) c2++;
    }
    printf("%d %d", c1, c1 + c2);
    return 0;
}