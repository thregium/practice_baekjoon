#include <stdio.h>

/*
���� : �� ���ɵ��� ��� ����� �־��� ��, ���� ���� ��ư�� �� ȸ ������ �ش� ������ ���ɵ��� ����� �� �ִ��� ���Ѵ�.
��, �־����� ����� ������ ó�� ���¿��� �ش� ������ �����ϱ� ���� ���� ���� ��ư�� ������ �ϴ� Ƚ����.

�ذ� ��� : �־��� ���ɵ��� ������� �迭�� ������ ���´�. ������ �Է¹����� �迭�� �������� ���󰡸�
����� ���ɵ� �߿� �ִ��� Ȯ���Ѵ�. �ִٸ� �ش� ��ġ���� Ž���� �����ϰ� ������ �ٽ� �޴´�.
���� ��쿡�� �ش� ������ ��ȣ��ŭ ���� �߰��� ���� �ٽ� ������ �޾ƾ� �Ѵ�.

�ֿ� �˰����� : ����

��ó : Brasil 2007 E��
*/

int hist[1024];

int main(void) {
    int n, r, found;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2007\\hist.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &hist[i]);
            found = 0;
            for (int j = i - 1; j >= 0; j--) {
                r++;
                if (hist[j] == hist[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) r += hist[i];
        }
        printf("%d\n", r);
    }
    return 0;
}