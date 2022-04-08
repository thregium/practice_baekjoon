#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������� ���� ���� ����� ��(<= 10^6) ��Ʈ �� �־��� ��,
��� ����� �� ���̸� 1��Ʈ �̳��� ���� �� ���� �Űܾ� �ϴ� ���� �ּڰ��� ���Ѵ�.

�ذ� ��� : �켱 �������� ������ �� �ִ��� ���� �ű��. �� ���� ���� ��� �̻��� ����鿡 ����
�ִ��� ������ ���� �ű��, �������� �ٽ� �ű�� �ȴ�. ��ü �ű� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ����, �׸��� �˰���

��ó : Waterloo 19990131 A��
*/

int mon[1024];

int main(void) {
    int n, dol, cen, sum, ave, rem;
    //freopen("E:\\PS\\Contest\\waterloo\\19990131\\A.3.dat", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d.%d", &dol, &cen);
            mon[i] = dol * 100 + cen;
            sum += mon[i];
        }
        //if (sum % n) return 1;
        ave = sum / n;
        rem = sum % n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += abs(mon[i] - ave);
        }
        for (int i = 0; i < n; i++) {
            if (rem > 0 && mon[i] > ave) {
                sum--;
                rem--;
            }
        }
        sum += rem;
        if (sum & 1) return 2;
        sum >>= 1;
        printf("$%d.%02d\n", sum / 100, sum % 100);
    }
    return 0;
}