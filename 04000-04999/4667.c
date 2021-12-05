#include <stdio.h>

/*
���� : ���� �Ⱓ�� �Ͻñ�, ������� �־��� ��, �㺸 ����� ��ġ�� ����� �̻��� �Ǵ� ������ ���Ѵ�.
�������� Ư�� ������ �������� �־�����, �ش� ������ ������ ������ �ش� ���� ������ ���� ������ �������� �����Ѵ�.
���� �Ⱓ�� 100���� ����, �Ͻñ� + ������� 75000$ ���Ϸ� �־�����. �ݵ�� 0�������� �����󰢾��� �־�����.

�ذ� ��� : ó���� �㺸 ����� ��ġ�� �Ͻñ� + ������̴�. �Ŵ� ���ƾ� �� ���� ����� / �Ⱓ�̴�.
���� �Ŵ� �������� �����ϰ�, ������ ��ȯ�� ������ �� ���� �����ϰ� �Ǵ� ������ �������� ���ϸ� �ȴ�.
�ݵ�� �� ���� ���� �Ⱓ ���� ������ �ȴ�.(�㺸 ��ġ�� ��������� �ܾ��� 0�̹Ƿ�)

�ֿ� �˰��� : ����, ����, �ùķ��̼�

��ó : MidC 1999 D��
*/

typedef struct deprication {
    int month;
    double drop;
} deprication;

deprication depr[128];

int main(void) {
    int duration, n, p;
    double payment, loan, car;
    while (1) {
        scanf("%d %lf %lf %d", &duration, &payment, &loan, &n);
        if (duration < 0) break;
        car = loan + payment;
        for (int i = 0; i < n; i++) {
            scanf("%d %lf", &depr[i].month, &depr[i].drop);
        }
        depr[n].month = -1;
        p = 0;
        payment = loan / duration;
        for (int i = 0; i <= duration; i++) {
            if (i == depr[p + 1].month) p++;
            car *= (1.0 - depr[p].drop);
            if (loan < car) {
                if (i == 1) printf("1 month\n");
                else printf("%d months\n", i);
                break;
            }
            loan -= payment;
        }
    }
    return 0;
}