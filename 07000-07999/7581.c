#include <stdio.h>

/*
���� : ������ü�� ����, �ʺ�, ����, ���� �� �ϳ��� ������ �ʾ��� ��, ������ ���� �ϳ��� ������ 4���� ���� ���Ѵ�.

�ذ� ��� : ������ ���� ���� Ȯ���ϰ� ����ϸ� �ȴ�. ���Ǵ� ������ 3���� ���ϸ� �ǰ�, �������� ���ǿ��� ���� 2���� ������ �ȴ�.

�ֿ� �˰��� : ����

��ó : NZPC 2009 B��
*/

int main(void) {
    int l, w, h, v;
    while (1) {
        scanf("%d %d %d %d", &l, &w, &h, &v);
        if (l == 0 && w == 0 && h == 0 && v == 0) break;
        if (v == 0) printf("%d %d %d %d\n", l, w, h, l * w * h);
        else if (h == 0) printf("%d %d %d %d\n", l, w, v / l / w, v);
        else if (w == 0) printf("%d %d %d %d\n", l, v / l / h, h, v);
        else printf("%d %d %d %d\n", v / w / h, w, h, v);
    }
    return 0;
}