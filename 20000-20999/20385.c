#include <stdio.h>
#include <string.h>

/*
���� : N * N(N <= 50) ũ���� ���ڿ� ���ڵ��� �����ִ�. ���⼭ ã������ �ܾ���� �־��� ��, ���ڿ��� �ܾ���� ã��
�� �ִ� ��ġ�� ������ ��� ���Ѵ�. ������ �����¿�밢������ 8������ �����ϰ�, �ܾ� �߰��� ������ ������ �� �ִ�.
�ܾ��� ������ ��->��->���ʺ��� �ð���� ������ ����Ѵ�.

�ذ� ��� : ���� ���ڸ� �Է¹��� ��, ��� ��ġ�� ���⿡ ���� �ܾ ã�� �� �ִ��� ���캸�� �ȴ�.
�߰��� �ٸ� ���ڰ� �����ų� ���ڸ� ����ų� ó���� ������ ������ �ܾ ã�� �� ���� ���̰�,
�׷��� �ʰ� �ܾ��� ������ ���� ã�� �� �ִ� ���̴�.

�ֿ� �˰��� : ����, ���Ʈ ����, ���ڿ�

��ó : MidC 1993 3��
*/

char s[64][64], find[64];
char* dir[8] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int main(void) {
    int n, len, x, y, t, p, cnt = 0; //len = ã�� �ܾ��� ����, (x, y) = ���� Ž�� ���� ��ġ�� ��ǥ, //t = ���� ���� ����
    //p = ���� ã�� ������ ��ȣ, cnt = �ܾ ã�� Ƚ��

    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\space1.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\space1_t.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &s[i][j]);
            if (s[i][j] == '\n' || s[i][j] == '\r') j--; //���� ���ڴ� �����Ѵ�.
        }
    }
    while (scanf("%s", find) != EOF) {
        len = strlen(find);
        cnt = 0;
        printf("%s\n", find);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int d = 0; d < 8; d++) {
                    t = 1, x = i, y = j, p = 0;
                    if (s[x][y] == ' ') continue;
                    while (p < len) {
                        if (x < 0 || y < 0 || x >= n || y >= n) {
                            t = 0;
                            break;
                        }
                        if (s[x][y] == ' ');
                        else if (s[x][y] == find[p]) p++;
                        else {
                            t = 0;
                            break;
                        }
                        x += dxy[d][0];
                        y += dxy[d][1];
                    }
                    if (t) {
                        printf("(%d,%d) - %s\n", i + 1, j + 1, dir[d]);
                        cnt++;
                    }
                }
            }
        }

        if (!cnt) printf("not found\n");
        printf("\n");
    }
    return 0;
}