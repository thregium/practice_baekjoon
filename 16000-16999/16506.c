#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 500)���� ����� �ڵ�� ������ �־��� ǥ�� �̿��Ͽ� ���� �ڵ�� ��ȯ�Ѵ�.

�ذ� ��� : opcode��� ��ȣ�� �̸� �ϵ��ڵ��� ���� �´� opcode�� Ȯ���Ͽ� ����� ����Ѵ�.
�� ����(�Ǵ� ���)���� ��ɾ Ȯ���ذ��� �׿� �°� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : �泲�� 2ȸ D��
*/

char buff[16];
char* opcode[] = { "ADD", "SUB", "MOV", "AND", "OR", "NOT", "MULT", "LSFTL",
"LSFTR", "ASFTR", "RL", "RR" };

int main(void) {
    int n, o, t, a, b, d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        o = -1;
        for (int j = 0; j < 12; j++) {
            t = 1;
            for (int k = 0; opcode[j][k]; k++) {
                if (buff[k] != opcode[j][k]) t = 0;
            }
            if (t) o = j;
        }
        if (o < 0) return 1;
        printf("%d%d%d%d", (o >> 3) & 1, (o >> 2) & 1, (o >> 1) & 1, o & 1);
        if (buff[strlen(buff) - 1] == 'C') {
            printf("10");
            scanf("%d %d %d", &d, &a, &b);
            printf("%d%d%d", (d >> 2) & 1, (d >> 1) & 1, d & 1);
            printf("%d%d%d", (a >> 2) & 1, (a >> 1) & 1, a & 1);
            printf("%d%d%d%d\n", (b >> 3) & 1, (b >> 2) & 1, (b >> 1) & 1, b & 1);
        }
        else {
            printf("00");
            scanf("%d %d %d", &d, &a, &b);
            printf("%d%d%d", (d >> 2) & 1, (d >> 1) & 1, d & 1);
            printf("%d%d%d", (a >> 2) & 1, (a >> 1) & 1, a & 1);
            printf("%d%d%d", (b >> 2) & 1, (b >> 1) & 1, b & 1);
            printf("0\n");
        }
    }
    return 0;
}