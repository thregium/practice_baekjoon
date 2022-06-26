#include <stdio.h>

/*
���� : N(N <= 50)���� ���ڿ��� ���ڸ� �߰��ϰų� �ֱ� ���� ������ ������� �ǵ����� ������ �־�����,
�� ������ ����� ���� ���ڿ��� ����Ѵ�.

�ذ� ��� : ����� �������� ���캸�鼭 �ǵ����� ������ ���� �� ���� �ǵ����� �� ������ �������� ���ư���.
���ڸ� �߰��ϴ� ������ �ִٸ� ��� �迭�� ���� �߰��Ѵ�.
�̸� �ݺ��� �� ��� �迭�� �������� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����?

��ó : SRM 419D1 1�� / 419D2 2��
*/

typedef struct oper {
    int type;
    char c;
    int ct;
    int time;
} oper;

oper op[64];
char buff[8], res[64];
int rlen = 0;

int main(void) {
    int n, nxt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (buff[0] == 't') {
            op[i].type = 1;
            scanf(" %c %d", &op[i].c, &op[i].time);
        }
        else {
            op[i].type = 2;
            scanf("%d %d", &op[i].ct, &op[i].time);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (op[i].type == 1) res[rlen++] = op[i].c;
        else {
            nxt = i;
            for (int j = i - 1; j >= 0; j--) {
                if (op[j].time + op[i].ct >= op[i].time) nxt = j;
                else break;
            }
            i = nxt;
        }
    }
    for (int i = rlen - 1; i >= 0; i--) printf("%c", res[i]);
    return 0;
}