#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 30)���� ������� 0������ N - 1������ ��ȣ�� �������� �ִ�. ������ �Ǵ� �������� x��° ������� �����ϴٰ� undo x�� ������
�ֱ� x�� ���� ��ġ�� ���ư��� �ൿ�� K(K <= 100)�� �ݺ��� ��, ���������� �����ϴ� ��ġ�� ���Ѵ�.

�ذ� ��� : ���� �ڷᱸ���� �̿��Ͽ� ���ÿ� �� ��°�� ��ġ�� �׾Ƶд�. undo�� ���� �� ���� x��ŭ ������ ���̸� ���߸� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ����, �ùķ��̼�, �Ľ�

��ó : ECRC 2017 D��
*/

char buff[16];
int st[128];
int stt = 1;

int main(void) {
    int n, k, x, r = 0;
    //freopen("E:\\PS\\ICPC\\North America\\East Central\\2017\\throwns\\throwns\\data\\secret\\02.in", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "undo")) {
            scanf("%d", &x);
            stt -= x;
            if (stt <= 0) return 1;
            r = st[stt - 1];
        }
        else {
            r = (((r + strtoll(buff, NULL, 10)) % n) + n) % n;
            st[stt++] = r;
        }
    }
    printf("%d", r);
    return 0;
}