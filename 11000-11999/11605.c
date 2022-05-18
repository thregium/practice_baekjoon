#include <stdio.h>

/*
���� : N(N <= 10)���� ��Ģ���� ��(<= 5)�� �־��� ��, ���� ������ ������ �м��� ������ ���� ������ ���Ѵ�.

�ذ� ��� : �� ���� ������ ����, ���� �ƴ� ������ �ƴ� ���� ������ ���궧 ����
�׷��� �����ϴ� ���� ������ ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : PacNW 2015 M��
*/

char buff[16];
int op[16][2];

int main(void) {
    int n, res = 0, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buff, &op[i][1]);
        if (buff[0] == 'A') op[i][0] = 1;
        else if (buff[0] == 'S') op[i][0] = 2;
        else if (buff[0] == 'M') op[i][0] = 3;
        else if (buff[0] == 'D') op[i][0] = 4;
        else return 1;
    }
    for (int i = 1; i <= 100; i++) {
        x = i;
        for (int i = 0; i < n; i++) {
            if (op[i][0] == 1) x += op[i][1];
            else if (op[i][0] == 2) {
                if (x < op[i][1]) {
                    res++;
                    break;
                }
                else x -= op[i][1];
            }
            else if (op[i][0] == 3) x *= op[i][1];
            else if (op[i][0] == 4) {
                if (x % op[i][1]) {
                    res++;
                    break;
                }
                else x /= op[i][1];
            }
        }
    }
    printf("%d", res);
    return 0;
}