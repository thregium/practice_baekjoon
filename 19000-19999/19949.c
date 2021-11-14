#include <stdio.h>

/*
���� : 10���� 5������ ����� �־��� ��, 3���� ���� �����ϰ� ���� �����鼭 5�� �̻� �޴� ����� ���� ���Ѵ�.

�ذ� ��� : ���Ʈ ������ ���� ��� ��츦 �غ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : ���ϴ� 2020N F��
*/

int ans[16], chk[16];

int track(int x) {
    if (x == 10) {
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            if (chk[i] == ans[i]) cnt++;
        }
        return (cnt >= 5);
    }
    int r = 0;
    for (int i = 1; i <= 5; i++) {
        chk[x] = i;
        if (x >= 2 && chk[x] == chk[x - 1] && chk[x] == chk[x - 2]) continue;
        r += track(x + 1);
    }
    return r;
}

int main(void) {
    for (int i = 0; i < 10; i++) {
        scanf("%d", &ans[i]);
    }
    printf("%d", track(0));
    return 0;
}