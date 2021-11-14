#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ����Ʈ�� �߰�/����/���� �� �� ���� ����� �־�����, �� ����� ���� �� ����
����Ʈ���� ���¸� ����Ѵ�. ����Ʈ���� ���ٸ� "sleep"�� ����Ѵ�.

�ذ� ��� : �� ��ɸ��� ����Ʈ���� ���¸� �ٲپ� ���� ����ϸ� �ȴ�. ���� ��ɽÿ��� O(N) ������ �ϴ���
����� �ð� ���� Ǯ �� �ִ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ����

��ó : ���ϴ� 2017 A��
*/

char buff[16];
int pit[320][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int aj = *((int*)a + 1);
    int bj = *((int*)b + 1);
    if (aj != bj) return aj > bj ? 1 : -1;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, top = 0, x, y;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "order")) {
            scanf("%d %d", &x, &y);
            pit[top][0] = x;
            pit[top++][1] = y;
        }
        else if (!strcmp(buff, "sort")) {
            qsort(pit, top, sizeof(int) * 2, cmp1);
        }
        else if (!strcmp(buff, "complete")) {
            scanf("%d", &x);
            y = 1;
            for (int i = 0; i < top; i++) {
                if (pit[i][0] == x) {
                    for (int j = i; j < top - 1; j++) {
                        pit[j][0] = pit[j + 1][0];
                        pit[j][1] = pit[j + 1][1];
                    }
                    top--;
                    y = 0;
                    break;
                }
            }
            if (y) return 2;
        }
        else return 1;

        if (top == 0) printf("sleep\n");
        else {
            for (int i = 0; i < top; i++) {
                printf("%d ", pit[i][0]);
            }
            printf("\n");
        }
    }
    return 0;
}