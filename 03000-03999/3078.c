#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 300000)���� �̸��� ���� ������ �־��� ��, ���� ������ K ���ϸ� �̸��� ���̰� ���� ���� ������ ���Ѵ�.
�̸��� ���̴� 20 ���ϴ�.

�ذ� ��� : ����, ���� ������ �� ����� �̸��� ���̸� ������ �����. �� ����, ���� ������ �̸��� ���̸� ���Ǹ�
���� K���� �̸��� ������ �� ������. ����, ���� K�� ��� ���� �̸��� ���̿� ���� ����� ���� �ᱣ���� �߰��Ѵ�.
�̸� �ݺ��ϴٰ� K���� �Ѿ�� K�� ���� ��� �̸��� ���� ������ ������ 1�� ���̸� �ȴ�.
�̸� ��� ����� ���� �ݺ��ϸ� ��� ���� ���� ���� �� �ִ�.

�ֿ� �˰����� : �� ������

��ó : COCI 12/13#3 3��
*/

char buff[32];
int name[327680], cnt[32];

int main(void) {
    int n, k;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        name[i] = strlen(buff);
    }
    for (int i = 0; i < n; i++) {
        r += cnt[name[i]];
        cnt[name[i]]++;
        if (i >= k) cnt[name[i - k]]--;
    }
    printf("%lld", r);
    return 0;
}