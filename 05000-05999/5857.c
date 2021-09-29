#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ��ǥ���� N(N <= 200)���� �ſ���� �ִ�. �� �ſ���� ��ǥ��� 45�� ������ ������(/, \ ����) �����ִ�.
�� �ſ��� ������ 90�� �ٲپ� (0, 0)���� +x �������� ���� ����� �� (a, b)�� ���� ���� �� �ִ� ���� ���� �ſ��� ��ȣ�� ���Ѵ�.
�ٲ��� �ʾƵ� �ȴٸ� 0�� ���, ��� �ٲپ ���� �� ���ٸ� 1�� ����Ѵ�. ��ǥ���� ������ +- 10^6 ���ϴ�.

�ذ� ��� : �ſ��� ������ �ʰ� ���� ��ƺ� ����, (a, b)�� �������� �ʴ´ٸ� �ϳ��� �������� ���� ��ƺ���.
(0, 0)���� +x ����� ���� �� ����, y�� ��ǥ�� 0�̸鼭 x���� ��ǥ�� 0���� ũ�� ���� x���� ��ǥ�� ���� �ſ￡
��� �Ǵ� ���� �� �� �ְ�, �� �ſ��� ��ǥ�� �̵��Ͽ� �ſ��� ���⿡ �°� ������ ���� ���� ���� �ش� �������� ���.
�̸� �ݺ��ϸ� (a, b)�� �ִ��� ã�Ƴ����� �ȴ�.
���� �ش��ϴ� �ſ��� ���ٸ� �߰��� (a, b)�� �ִ��� Ȯ���ϰ� ���ٸ� ���̻� �ſ��� ���� �� �����Ƿ� Ž���� �����Ѵ�.
����, �߰��� (0, 0)�� ������ +x�������� �̵��Ѵٸ� ��� �ݺ��ϰ� �ǹǷ�
�ش� �������� (a, b)�� �߰����� ���� ��Ȳ�̱⿡ Ž���� �����ؾ� �Ѵ�.
�ſ��� �������� �߰��� (a, b)�� ������ ��쵵 ���� ó���ؾ� �Կ� �����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ����, ���̽� ��ũ

��ó : USACO 2013J B1��
*/

int mirror[256][3];

int check(int n, int a, int b) {
    int x, y, d, t;
    //for (int dd = 0; dd < 4; dd++) {
        x = 0, y = 0, d = 1;
        while (1) {
            if (d < 2) t = 255; //���⿡ ���� �ӽ� ��ǥ�� ���Ѵ�
            else t = 0;
            for (int i = 1; i <= n; i++) {
                //�ſ��� Ȯ���Ѵ�.
                if (d == 0 && mirror[i][0] == x && mirror[i][1] > y && mirror[i][1] < mirror[t][1]) t = i; 
                if (d == 1 && mirror[i][0] > x && mirror[i][1] == y && mirror[i][0] < mirror[t][0]) t = i;
                if (d == 2 && mirror[i][0] == x && mirror[i][1] < y && mirror[i][1] > mirror[t][1]) t = i;
                if (d == 3 && mirror[i][0] < x && mirror[i][1] == y && mirror[i][0] > mirror[t][0]) t = i;
            }
            if (t == 255 || t == 0) {
                if (d == 0 && x == a && y < b) return 1; //�ſ��� ������ ���߰� �߰��� (a, b)�� �ִ� ���
                if (d == 1 && x < a && y == b) return 1;
                if (d == 2 && x == a && y > b) return 1;
                if (d == 3 && x > a && y == b) return 1;
                break;
            }
            if (d == 0 && x == a && y < b && mirror[t][1] > b) return 1; //�ſ��� �������� �߰��� (a, b)�� �ִ� ���
            if (d == 1 && x < a && y == b && mirror[t][0] > a) return 1;
            if (d == 2 && x == a && y > b && mirror[t][1] < b) return 1;
            if (d == 3 && x > a && y == b && mirror[t][0] < a) return 1;
            if (d == 1 && mirror[t][0] > 0 && x < 0 && y == 0) break; //��� �ݺ��ϰ� �Ǵ� ��� �����Ѵ�.
            
            x = mirror[t][0];
            y = mirror[t][1];
            if ((d & 1) ^ mirror[t][2]) d = ((d + 3) & 3); //������ �ſ��� ���⿡ �°� �ٲ۴�.
            else d = ((d + 1) & 3);
        }
        
    //}
    return 0;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("mirrors.in", "r");
        fo = fopen("mirrors.out", "w");
    }
    int n, a, b;
    char c;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %c", &mirror[i][0], &mirror[i][1], &c);
        if (c == '\\') mirror[i][2] = 1;
    }
    mirror[0][0] = -INF, mirror[0][1] = -INF, mirror[255][0] = INF, mirror[255][1] = INF; //�ӽ� ��ǥ���� �迭�� �߰��Ѵ�.

    if (check(n, a, b)) {
        //�ſ��� ������ �ʾƵ� �Ǵ� ���
        printf("%d", 0);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        mirror[i][2] = !mirror[i][2]; //�ſ��� �ϳ��� ������ �����ذ��� (a, b)�� ���� �� �ִ� ��츦 ã�´�.
        if (check(n, a, b)) {
            printf("%d", i);
            return 0;
        }
        mirror[i][2] = !mirror[i][2];
    }
    printf("%d", -1); //��� �ص� ���� �ʴ� ���
    return 0;
}