#include <stdio.h>

/*
���� : �� �����鿡 ���� �׽�Ʈ ���̽��� ��� ��µ� ���� �־��� ��, �������� üũ�Ǵ��� ���θ� ���Ѵ�.

�ذ� ��� : ��� ���� ����� ���ٸ� �����̰�, �ϳ��� �ƴ� ���� �ִٸ� �ƴϴ�.

�ֿ� �˰��� : ����

��ó : ���ִ� 2018D1 A�� / 2018D2 A��
*/

int main(void) {
    int s1, s2, tc, ans;
    scanf("%d %d", &s1, &s2);
    for (int i = 0; i < s1; i++) {
        scanf("%d %d", &tc, &ans);
        if (tc != ans) {
            printf("Wrong Answer");
            return 0;
        }
    }
    for (int i = 0; i < s2; i++) {
        scanf("%d %d", &tc, &ans);
        if (tc != ans) {
            printf("Why Wrong!!!");
            return 0;
        }
    }
    printf("Accepted");
    return 0;
}