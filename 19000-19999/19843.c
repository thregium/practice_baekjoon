#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 10)���� ���ϵ��� ���� ����� ���� �ð� ���� �ð��� ���·� �־�����. �̶�, �����Ͽ� T(T <= 168)�ð���
�ڱ� ���� �ָ��� �ھ� �� �ּ� �ð��� ���Ѵ�. �� ���� ����� ��ġ�� �ʰ� ������ ���� ���� �����̴�.
48�ð� ���� �ڴ��� ��ǥ �ð��� ���� ������ -1, ���� ���� �ʾƵ� �ȴٸ� 0�� ����Ѵ�.

�ذ� ��� : ���� ��ϸ��� �� ������ üũ�ϰ� �ð��� �ش� ���Ͽ� �ش��ϴ� ��¥�� �ð��� ���ؼ�
�ҿ�� ���� �ð��� ���ϰ� �̵��� ���� ���Ѵ�. �� ����, ���� T �̻����� üũ�Ѵ�.
�̻��� ��� �̹� T�ð��� �� ���̹Ƿ� 0�� ����ϸ� �ǰ�, �� ���� ���� T - S�� ����Ѵ�.
��, �� ���� 48���� ũ�ٸ� -1�� ����ؾ� �Ѵ�.

�ֿ� �˰����� : ����

��ó : ����� 2020 D2A��
*/

char ss[8], se[8];
const char* wd[5] = { "Mon", "Tue", "Wed", "Thu", "Fri" };

int main(void) {
    int t, n, s = 0, st, ed;
    scanf("%d %d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %s %d", ss, &st, se, &ed);
        for (int i = 0; i < 5; i++) {
            if (!strcmp(ss, wd[i])) st += i * 24;
            if (!strcmp(se, wd[i])) ed += i * 24;
        }
        s += ed - st;
    }
    if (s >= t) printf("0");
    else if (t - s > 48) printf("-1");
    else printf("%d", t - s);
    return 0;
}