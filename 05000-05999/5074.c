#include <stdio.h>

/*
���� : ���� �ð��� ���� �Ⱓ�� �־��� ��, ������ �ð��� ���Ѵ�. ��¥�� �ٲ�ٸ� �ٲ�� ��¥�� ���� ���Ѵ�.

�ذ� ��� : ���� �ð��� ���� �Ⱓ�� ���� ������ �ð��� �� ������ ����� ����, ��¥, �ð�, �� ������ ������ ����Ѵ�.

�ֿ� �˰��� : ����, ����, ��Ģ����

��ó : NCPC 2012 C��
*/

int main(void) {
    int sh, sm, dh, dm, et, eh, em;
    while (1) {
        scanf("%d:%d %d:%d", &sh, &sm, &dh, &dm);
        if (sh == 0 && sm == 0 && dh == 0 && dm == 0) break;
        et = sh * 60 + sm + dh * 60 + dm;
        eh = et / 60;
        em = et % 60;
        if (eh >= 24) printf("%02d:%02d +%d\n", eh % 24, em, eh / 24);
        else printf("%02d:%02d\n", eh, em);
    }
    return 0;
}