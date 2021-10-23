#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 3000)���� ���� �̷���� ������ �־��� ��, �� ������ Jolly jumper���� ���Ѵ�. Jolly jumper�� ����
������ �� ���� ���̷� 1���� N - 1���� ��� ���� ������ ����̴�.

�ذ� ��� : �� ������ ���� ���鼭 ������ �� ���� ���̸� ���ɴ�. ���� 0�̰ų� N �̻��� ��쿡�� ������ ������Ƿ�
��� ���� ������ �� �� ����, Jolly jumper�� �ƴϴ�. ����, �̹� ���� �� ���� ���̰� ���� ��쿡�� Jolly jumper�� �ƴϴ�.
������ ���� ���� �� ���� ���Դٸ� �������� ǥ���صд�. ������ �� �� ��찡 ������ �ʾҴٸ� Jolly jumper�̴�.

�ֿ� �˰��� : ����?

��ó : Waterloo 000930 C��
*/

int num[3200], chk[3200];

int main(void) {
    int n, r;
    //freopen("E:\\PS\\Contest\\waterloo\\20000930\\data\\C.1.dat", "r", stdin);
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        r = 1;
        for (int i = 1; i < n; i++) {
            if (abs(num[i] - num[i - 1]) >= n || num[i] == num[i - 1]) {
                r = 0;
                break;
            }
            else if (chk[abs(num[i] - num[i - 1])]) {
                r = 0;
                break;
            }
            else chk[abs(num[i] - num[i - 1])] = 1;
        }
        for (int i = 1; i < n; i++) chk[i] = 0;
        printf("%s\n", r ? "Jolly" : "Not jolly");
    }
    return 0;
}