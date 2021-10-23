#include <stdio.h>

/*
���� : ���� 6���� �� �ֻ����� �� �鿡 ���� ������ �־��� ��, ù ��° �ֻ����� ���� �����
�� ��° �ֻ����� ���� ������� Ŭ Ȯ���� ���м��� ���Ѵ�.

�ذ� ��� : �ֻ����� �� �鸶�� ���� ���� ��� ������ ���Ʈ ������ ã�´�. �� ����, �׷��� ���� ���
ù ��° �ֻ����� ����� �� ū ���� ������ ����. �� ���� �����̰�, 36�� �и��� �м��� ����Ͽ� ���м��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����, Ȯ����, ��Ŭ���� ȣ����

��ó : Seoul 2020 B��
*/

int first[6], sec[6];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &first[i]);
    }
    for (int i = 0; i < 6; i++) {
        scanf("%d", &sec[i]);
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (first[i] > sec[j]) cnt++;
        }
    }
    printf("%d/%d", cnt / gcd(cnt, 36), 36 / gcd(cnt, 36));
    return 0;
}