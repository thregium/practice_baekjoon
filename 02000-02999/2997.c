#include <stdio.h>
#include <stdlib.h>

/*
���� : -100 �̻� 100 ������ ���� 3���� �־��� ��, ������ �� ���� ������ �߰��� �� ������ ���������� �ǵ��� �ϴ� ������ ���Ѵ�.
�̷��� ��찡 �ִ� ��츸 �־�����.

�ذ� ��� : 3���� ���� ��� �־����� ������ �� ���� -200 ���� 200 �̻��� ������ ã�� �� �ִ�.
����, �ش� ������ ���� ���� �߰��� ���� �����ϰ� ��� ������ ���� ���̰� ������ �Ź� Ȯ���� ���ٰ�
�׷��� ��츦 ã���� ����ϰ� ���α׷��� �����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : COCI 07/08#3 1��
*/

int num[3], nnum[4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    for (int i = 0; i < 3; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = -1000; i <= 1000; i++) {
        for (int j = 0; j < 3; j++) {
            nnum[j] = num[j];
        }
        nnum[3] = i;
        qsort(nnum, 4, sizeof(int), cmp1);
        if (nnum[1] - nnum[0] == nnum[2] - nnum[1] && nnum[2] - nnum[1] == nnum[3] - nnum[2]) {
            printf("%d", i);
            return 0;
        }
    }
    return 1;
}