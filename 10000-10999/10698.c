#include <stdio.h>

/*
���� : �־��� ���� �Ǵ� ���� ���� �´��� ���Ѵ�.

�ذ� ��� : ���� �������� ���������� Ȯ���� ���� �´��� Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : Tunisia 2013 J��
*/

int main(void) {
    int t, x, y, z;
    char o;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %c %d = %d", &x, &o, &y, &z);
        printf("Case %d: ", tt);
        if (o == '+') {
            if (x + y == z) printf("YES\n");
            else printf("NO\n");
        }
        else {
            if (x - y == z) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}