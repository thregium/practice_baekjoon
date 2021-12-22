#include <stdio.h>

/*
���� : D(D <= 100000)��ŭ�� �ð����� ������ �Ѵ�. �⳻���� M(M <= 1000)�� ������, �ð� ������ 0���� D �������� ���´�.
�̶�, �⳻���� ������ �ʴ� ���� �ܴٸ� T(T <= 100000)��ŭ�� �ð����� �������� �� �� �ִ��� ���Ѵ�.

�ذ� ��� : �ֱ� �⳻���� ���� �ð��� ���� �ð��� ���ؼ� �� ��� ���� �� ���� ������ �ȴ�.
�̶�, ó���� ������ ���ؾ� �Կ� �����Ѵ�.

�ֿ� �˰����� : ����?

��ó : Brasil 2021 K��
*/

int main(void) {
    int t, d, m, y, last = 0, best = 0;
    scanf("%d %d %d", &t, &d, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &y);
        if (y - last > best) best = y - last;
        last = y;
    }
    if (d - last > best) best = d - last;
    printf("%c", best >= t ? 'Y' : 'N');
    return 0;
}