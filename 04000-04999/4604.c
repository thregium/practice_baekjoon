#include <stdio.h>
#include <string.h>

/*
���� : 80�� ������ ���ڷ� �̷���� ���� 1�� �̻� �־�����. �̶�, �� �ٿ��� ������ ������ ���̰�
¦���� ��츦 ��Ʈ 1, Ȧ���� ��츦 ��Ʈ 0���� �ϰ�, ���� �տ������� 5�� ��Ʈ�� �߶󰡸�
������ �־��� ��ȯǥ�� �̿��� ���ڿ��� ��ȯ�� ����� ����Ѵ�.
���� ��Ʈ�� 0���� ä���.

�ذ� ��� : ������ �־��� �͵��� �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����

��ó : MidC 2008 H��
*/

char bit[103000], mess[128];

int main(void) {
    int p, s;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\2008\\mcpc2008\\steg\\in.txt", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\2008\\mcpc2008\\steg\\out_t.out", "w", stdout);
    while (1) {
        p = 0;
        while (1) {
            fgets(mess, 100, stdin);
            if (mess[0] == '#') return 0;
            else if (mess[0] == '*') break;

            if (mess[strlen(mess) - 1] == '\n') mess[strlen(mess) - 1] = '\0';
            s = 0;
            for (int i = 0; mess[i]; i++) {
                if (mess[i] == ' ') s++;
                else {
                    if (s > 0 && (s & 1)) bit[p++] = 0;
                    else if (s > 0) bit[p++] = 1;
                    s = 0;
                }
            }
            if (s > 0 && (s & 1)) bit[p++] = 0;
            else if (s > 0) bit[p++] = 1;
        }
        for (int i = 0; i < (p + 4) / 5; i++) {
            s = 0;
            for (int j = 0; j < 5; j++) {
                s += bit[i * 5 + j] * (1 << (4 - j));
                bit[i * 5 + j] = '\0';
            }
            if (s == 0) printf(" ");
            else if (s <= 26) printf("%c", 'A' + s - 1);
            else if (s == 27) printf("'");
            else if (s == 28) printf(",");
            else if (s == 29) printf("-");
            else if (s == 30) printf(".");
            else if (s == 31) printf("?");
        }
        printf("\n");
    }
    return 0;
}