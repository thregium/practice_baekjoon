#include <stdio.h>

/*
���� : 14�ϰ��� �ְ�(1 <=, <= 1000, ����)�� �־��� ��, ������ �־��� �� �Ÿ� ���� ��� �� ���� ������ ���Ѵ�.

�ذ� ��� : ������ �־������ �� ������ �ùķ��̼��Ѵ�. �������� ������ ������ �� �̿��ؾ� �Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : ���ϴ� 2020U H��
*/

int md[14];

int main(void) {
    int m, jhs = 0, jhm = 0, sms = 0, smm = 0;
    scanf("%d", &m);
    smm = m;
    jhm = m;
    for (int i = 0; i < 14; i++) {
        scanf("%d", &md[i]);
        if (jhm >= md[i]) {
            jhs += jhm / md[i];
            jhm %= md[i];
        }
        if (i >= 3 && md[i] < md[i - 1] && md[i - 1] < md[i - 2] && md[i - 2] < md[i - 3]) {
            sms += smm / md[i];
            smm %= md[i];
        }
        if (i >= 3 && md[i] > md[i - 1] && md[i - 1] > md[i - 2] && md[i - 2] > md[i - 3]) {
            smm += sms * md[i];
            sms = 0;
        }
    }
    if (jhs * md[13] + jhm > sms * md[13] + smm) printf("BNP");
    else if (jhs * md[13] + jhm == sms * md[13] + smm) printf("SAMESAME");
    else printf("TIMING");
    return 0;
}