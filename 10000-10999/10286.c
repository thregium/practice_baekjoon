#include <stdio.h>

/*
���� : ���׿��� ���� �ִ� ���⿡ ���� Ȱ�ַ� ��ȣ�� ���Ѵ�. ������ 360���� ���� ������ �־�����,
0�� ������� ������ Ŀ�� ���� ��ȣ�� Ŀ����. ��ȣ�� 1������ 18������ �ִµ�, 0�� ������ 18������ �����Ѵ�.
�ݴ� ������ ���� ���� �������� �����ؾ� �Ѵ�.

�ذ� ��� : N�� 180���� ���� �������� ���ؼ� �������� ���� ���� 5�� ���ϰ� 10���� ������ ���� ���Ѵ�.
���� 0�� ��� 18�� �ٲٰ� �� �ܿ��� �״�� ����ϸ� �ȴ�.

�ֿ� �˰����� : ����

��ó : BAPC 2014P F��
*/

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = (n % 180 + 5) / 10;
        if (r == 0) r = 18;
        printf("%02d\n", r);
    }
    return 0;
}