#include <stdio.h>
#include <stdlib.h>

/*
���� : �־��� ���� N(N <= 15)�� ������ ���� ������ ���� ���� ���� ���� ���ο� ������ �ϴ� ������ �ݺ��ϸ�
��� ���� 0�� �ǰų� ������ ������ �ݺ��ȴٰ� �Ѵ�. �־��� ������ ��� ���� �Ǵ��� ���Ѵ�.
��, �־����� ��� ������ 1000ȸ �ȿ� �� �� �ϳ��� �����Ѵ�.

�ذ� ��� : 1000ȸ���� �ش� ������ �ݺ��� ���� ��� ���� 0���� Ȯ���Ѵ�. 0�� �ȴٸ� ��� ���� 0�� ���̴�.

�ֿ� �˰����� : ����, �ùķ��̼�

��ó : Seoul 2009 A��
*/

int a[16];

int main(void) {
    int t, n, x;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < 1030; i++) {
            x = a[0];
            for (int j = 0; j < n - 1; j++) {
                a[j] = abs(a[j] - a[j + 1]);
            }
            a[n - 1] = abs(a[n - 1] - x);
        }
        x = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) x = 0;
        }
        printf("%s\n", x ? "ZERO" : "LOOP");
    }
    return 0;
}