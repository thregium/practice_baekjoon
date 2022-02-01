#include <stdio.h>

/*
���� : N(N <= 10000)���� ������ ���� ����� �־��� ��, ��ü ���� ����� ���Ѵ�.
�������� ũ��� C(C <= 1000)�� ���������̸�, �� ���� ���̿� ���߾� ���� �����(���� ����) ���� �����ȴ�.
������ ������ ���ҷ� ������� 10 ����� ����. ������ �Ұ����� �� ������ �����ϰ�
��������� ���� �ʴ´�. �����ÿ��� ���ٸ� ��� ���� �ش� ���� ������ ������ ������.

�ذ� ��� : �������� �� ��ġ���� �����Ǿ��� �� ���ο� �� ������ ���� ��ġ�� �����صΰ�,
�� ���� �̵��� �ùķ��̼��ϸ� �ȴ�. 

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : Brasil 2011 E��
*/

int park[1024], car[10240];

int main(void) {
    int c, n, p, q, r, t;
    char ch;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2011\\estacionamento.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2011\\estacionamento_t.out", "w", stdout);
    while (scanf("%d %d", &c, &n) != EOF) {
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf(" %c %d", &ch, &p);
            if (ch == 'S') {
                for (int j = car[p] + 1; park[j] == park[car[p]]; j++) park[j] = 0;
                park[car[p]] = 0;
            }
            else {
                scanf("%d", &q);
                t = 0;
                for (int j = 0; j < c; j++) {
                    if (park[j]) t = 0;
                    else t++;
                    if (t == q) {
                        for (int k = j - q + 1; k <= j; k++) park[k] = p;
                        car[p] = j - q + 1;
                        r += 10;
                        break;
                    }
                }
            }
        }
        printf("%d\n", r);
        for (int i = 0; i < c; i++) park[i] = 0;
    }
    return 0;
}