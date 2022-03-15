#include <stdio.h>

/*
���� : R(R <= 100000)���� �����ǿ� K(K <= 100000)���� ��ᰡ �ִ�.(R * K <= 100000)
�̶�, �� ����� ���� ������ �� �������� ����ϴ� ��� �� �� ������ �־��� ��,
������ 1���������� ���� �� �ִ� �ִ� ������� ���Ѵ�. ���� ����, ��� ��, ������ ��� 10000 ���ϴ�.
����, ��� �����ǿ��� 1�� �̻��� ��Ḧ ����Ѵ�.

�ذ� ��� : �� �����Ǹ��� ��Ḧ �ִ� �󸶳� ��� ������ �� Ȯ���Ѵ�.
�׸��� ���� �� �ִ� �ִ뷮�� ���ϰ� �� ���� ������ ���� ���� ���� ���� ã���� �ȴ�.
��, 0���� ������ �ʵ��� �����Ѵ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : MidC 2020 O��
*/

int amount[103000];

int main(void) {
    int k, r, best = 0, smlst, usg, price;
    scanf("%d %d", &k, &r);
    for (int i = 0; i < k; i++) {
        scanf("%d", &amount[i]);
    }
    for (int i = 0; i < r; i++) {
        smlst = 10000;
        for (int j = 0; j < k; j++) {
            scanf("%d", &usg);
            if (usg == 0) continue;
            if (amount[j] / usg < smlst) smlst = amount[j] / usg;
        }
        scanf("%d", &price);
        if (smlst * price > best) best = smlst * price;
    }
    printf("%d", best);
    return 0;
}