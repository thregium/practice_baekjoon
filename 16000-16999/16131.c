#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� �л����� ����簡 �����Ǿ� �ִ�. �� ����� ����縦 ������ �־��� ���Ǵ��
�� �ָ��� ������ ������ ���� ���� �ٲ۴�. �̶�, 1�� �л��� A�� �л��� ����� ��ġ ���̰�
B ������ ���� ������ �׷��� ���� �ִ� ���� ���� ���� ���Ѵ�.

�ذ� ��� : ������ �־��� �͵��� �����Ѵ�. ����� �����ϹǷ� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : ������� 2018_01 B��
*/

int score[128], dorm[128], stu[128]; //score: �л��� ����, dorm: x�� ���� �л� ��ȣ, stu: �л��� �� ��ȣ

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, a, b, m, tmp, con = 0, conr = 0, cnt = 0; //con: ���� ���Ӱ�, conr: ���� �ִ�, cnt: Ƚ��
    scanf("%d %d %d %d", &n, &a, &b, &m);
    for (int i = 1; i <= n; i++) {
        dorm[i] = i;
        stu[i] = i;
    }
    if (abs(stu[a] - stu[1]) <= b) {
        cnt++;
        con = 1;
        conr = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &score[j]);
        }
        for (int j = 1; j <= n; j++) {
            scanf("%d", &tmp);
            score[j] -= tmp; //������ ���� �ǹǷ� ���� - ������ ��
        }

        for (int j = 1; j < n; j++) {
            //1������ N������ ���� ���ʷ� ���캽
            if ((score[dorm[j]] >= 0 && score[dorm[j + 1]] >= 0 && score[dorm[j + 1]] - score[dorm[j]] >= 2)
                || (score[dorm[j]] < 0 && score[dorm[j + 1]] < 0 && score[dorm[j + 1]] - score[dorm[j]] >= 4)
                || (score[dorm[j]] < 0 && score[dorm[j + 1]] >= 0)) {
                //�Ѵ� ����� ��� 2����, �Ѵ� ������ ��� 4����, ��/���� ��� �׻� ���� �ٲ�
                score[dorm[j]] += 2;
                score[dorm[j + 1]] -= 2; //�� ���� ���� ���� ���

                swap(&dorm[j], &dorm[j + 1]); //�� ������� �л��� �ٲ�
                swap(&stu[dorm[j]], &stu[dorm[j + 1]]); //�� �л��� ����縦 �ٲ�
            }
        }

        if (abs(stu[a] - stu[1]) <= b) {
            //�� ���� �� ��ȣ ���̰� B ������ ���
            cnt++;
            con++;
            if (con > conr) conr = con; //�ִ� ����ġ�� ����
        }
        else con = 0; //����ġ�� 0���� �ٲ�
    }
    printf("%d %d", cnt, conr);
    return 0;
}