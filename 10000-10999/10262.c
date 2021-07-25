#include <stdio.h>

/*
���� : 2���� ���� [A1, B1]�� [A2, B2]�� ������ ������ �ֻ��� 2���� ���� ������ �̱� ���ɼ��� �� ���� ����� ã�´�.
(A1, B1, A2, B2 <= 100)

�ذ� ��� : ��� ��쿡 ���� ���� ���� �̱���� Ȯ���ϰ� �� �̱� ���� ���� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : NCPC 2014 D��
*/

int main(void) {
    int ka1, kb1, ka2, kb2, sa1, sb1, sa2, sb2, kw = 0, sw = 0;
    scanf("%d %d %d %d%d %d %d %d", &ka1, &kb1, &ka2, &kb2, &sa1, &sb1, &sa2, &sb2);
    for (int a = ka1; a <= kb1; a++) {
        for (int b = ka2; b <= kb2; b++) {
            for (int c = sa1; c <= sb1; c++) {
                for (int d = sa2; d <= sb2; d++) {
                    if (a + b > c + d) kw++;
                    else if (a + b < c + d) sw++;
                }
            }
        }
    }
    if (kw > sw) printf("Gunnar");
    else if (kw < sw) printf("Emma");
    else printf("Tie");
    return 0;
}