#include <stdio.h>

/*
���� : ü������ ����� �־��� ���������� �������� ���� 4ȸ �̳��� �̵��ϴ� ��ΰ� �ִ� �� ã��
���ٸ� Impossible��, �ִٸ� �׷��� ��θ� ����Ѵ�.

�ذ� ��� : �� ĭ�� Ȧ¦���� �ٸ� ��� ���� ���� ���� �� �����Ƿ� Impossible�� ����ϸ� �ȴ�.
Ȧ¦���� ���ٸ� 1ĭ�� �̵��ߴٰ� ���ƿ��� ���� ���� �� �ִ� ���� �� �� �ִ�.
����, ��� ĭ�� ���� �߰����� ���� �� �ִ� �� Ȯ���ϰ� ���� �� �ִ� �� ĭ�� �߰������� �ϴ�
��θ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : GCPC 2013 C��
*/

int main(void) {
    int t, sy, ey, end;
    char sx, ex;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf(" %c %d %c %d", &sx, &sy, &ex, &ey);
        if (((sx + sy) - (ex + ey)) & 1) printf("Impossible\n");
        else if (sx == ex && sy == ey) printf("0 %c %d\n", sx, ey);
        else if (sx + sy == ex + ey || sx - sy == ex - ey) printf("1 %c %d %c %d\n", sx, sy, ex, ey);
        else {
            end = 0;
            for (char px = 'A'; px <= 'H'; px++) {
                for (int py = 1; py <= 8; py++) {
                    if ((sx + sy == px + py || sx - sy == px - py) &&
                        (px + py == ex + ey || px - py == ex - ey)) {
                        printf("2 %c %d %c %d %c %d\n", sx, sy, px, py, ex, ey);
                        end = 1;
                        break;
                    }
                }
                if (end) break;
            }
            if (!end) return 1;
        }
    }
    return 0;
}