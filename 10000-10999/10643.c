#include <stdio.h>

/*
���� : 8���� ������ �� ������ �ִ� ������ ����(<= 50)�� �־��� ��, ���ڸ� ������ ������ ���� ���� ������ �ֵ��� �ϴ� �����
���� ���� ���Ѵ�. ��, ���ڴ� ���� �����θ� �ڸ� �� �ִ�.

�ذ� ��� : 

�ֿ� �˰��� : ���Ʈ ����

��ó : COCI 14/15#5 1��
*/

int mush[8];

int main(void) {
    int best = -1, sum;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &mush[i]);
    }
    for (int i = 0; i < 8; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += mush[(i + j) & 7];
        }
        if (sum > best) best = sum;
    }
    if (best < 0) return 1;
    printf("%d", best);
    return 0;
}