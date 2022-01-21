#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : ���� 10000 ������ []�� ���ڷ� �̷���� ���ڿ��� �־�����. ���ڴ� ���� ���� [] �ȿ��� �����ϸ�,
�� [] �ȿ��� Ȧ�� ���� [] �Ǵ� ���ڵ��� �־�����. ���ڵ��� �����ϸ� 9999 ������ Ȧ�� �ڿ����� �ȴ�.
�̶�, �� �ܰ踶�� [] ���� �ο����� ��ǥ�� �����Ͽ� ���� ��ǥ�� ���� ���� �ܰ��� ����� �̴´�.
�� �ܰ踶�� �Ʒ� �ܰ��� []���� ��ǥ�� ������ ��, ��ǥ���� �¸��ϱ� ���� ��ǥ�ؾ� �� 1�ܰ� ��ǥ����
��ǥ ���� ���Ѵ�.

�ذ� ��� : �� �ܰ踶�� ��ǥ�� �¸��ϱ� ���ؼ��� ���� �ܰ� �� ���ݼ��� ������ ����� �Ѵ�.
�� �� 1�ܰ� ��ǥ�� ���� ���� ���� ���� ���� ���� ���ű� ceil(N / 2)������ �̱�� ���̰�,
�̴� ������ ���� �ذ��� �� �ִ�. ����, 1�ܰ��� ��ǥ�� ���� strtoll() �Լ��� �̿��� �� ���� + 1��
�Ͽ� ���Ѵ�. �� �ܰ� ���� ���� �ܰ��� ��ǥ�� ���� ��������� Ȯ���ϸ� ���� ���س����� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ���� ����, ����

��ó : JDC 2013 C��
*/

char data[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int vote(int s, int e) {
    if (data[s + 1] != '[') return (strtoll(&data[s + 1], NULL, 10) + 1) >> 1;
    int stage[4096];
    int voter = 0, cnt = 0, ss = -1, res = 0;
    for (int i = s + 1; i < e; i++) {
        if (cnt == 0 && data[i] == '[') ss = i;
        else if (cnt == 1 && data[i] == ']') stage[voter++] = vote(ss, i);
        if (data[i] == '[') cnt++;
        else if (data[i] == ']') cnt--;
    }
    qsort(stage, voter, sizeof(int), cmp1);
    for (int i = 0; i <= (voter >> 1); i++) res += stage[i];
    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", data);
        printf("%d\n", vote(0, strlen(data) - 1));
    }
    return 0;
}