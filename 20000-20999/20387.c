#include <stdio.h>
#include <ctype.h>

/*
���� : �ִ� 100 * 100 ũ���� ��ȸ���� ����� �־�����. �� ���ĺ�(�빮��)�� �Է��� ��Ÿ����, or�� and ����Ʈ�� ������,
�ҹ��� o�� not�� �ǹ��Ѵ�. ����, ����Ʈ�� �����ϸ� ��� ���� �� �پ� ���� ���� �̾��� �ִ�. �̶� �� �Է��� �־����� ���(����ǥ)�� ���Ѵ�.

�ذ� ��� : ����, ��ȸ�ΰ� �־����� �� ����Ʈ��� ����� ��ġ�� ������ ���´�. �� ����, �Է��� �־�����
�� �Է¿� ���� �Էº��� ����Ʈ �Ǵ� ��±����� ���� ���� ���� ������ ���´�. ���ķδ� ��� ����Ʈ�� ���� �� �Է��� ��� ���ǵ� ��쿡 ����
����� �� �� �����Ƿ� ���� ����Ʈ �Ǵ� ��±��� �ݺ��Ͽ� ������ ������ �ȴ�. ����� ���ǵǸ� ��μ� �� ���� ����ϰ� ���� �Է��� �޴´�.

�ֿ� �˰��� : ����, �׷��� Ž��

��ó : GNY 2001 E�� // MidC 1993 5��
*/

char logics[128][128], data[32];
int nums[128][128], vis[128][128], gates[256][2], result[2];
int gp = 0;
int dxy[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void move(int x, int y, int n, int d) {
    //���� ���� ������ �����Ѵ�.
    if (logics[x][y] == 'o') n = !n;
    nums[x][y] = n;
    vis[x][y] = 1;
    if (logics[x][y] == ':' || logics[x][y] == '?') {
        return;
    }
    if (logics[x][y] == '+') {
        if (logics[x + dxy[0][0]][y + dxy[0][1]] == '|' && d != 2) d = 0;
        else if (logics[x + dxy[1][0]][y + dxy[1][1]] == '-' && d != 3) d = 1;
        else if (logics[x + dxy[2][0]][y + dxy[2][1]] == '|' && d != 0) d = 2;
        else if (logics[x + dxy[3][0]][y + dxy[3][1]] == '-' && d != 1) d = 3;
    }
    move(x + dxy[d][0], y + dxy[d][1], n, d);
}

int main(void) {
    int row, t, end = 0;
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2001\\e\\logic.in", "r", stdin);
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Mid Central\\1993\\logic.in", "r", stdin);
    while (1) {
        gp = 0;
        for (int i = 0;; i++) {
            if (fgets(logics[i], 120, stdin) == NULL) {
                //���̻� ���� ���� �� ���ٸ� �����Ѵ�.
                end = 1;
                break;
            }
            for (int j = 0; logics[i][j]; j++) {
                if (logics[i][j] == '>' || logics[i][j] == ')') {
                    //����Ʈ�� ��ġ�� �����Ѵ�.
                    gates[gp][0] = i;
                    gates[gp][1] = j;
                    gp++;
                }
                if (logics[i][j] == '?') {
                    //����� ��ġ�� �����Ѵ�.
                    result[0] = i;
                    result[1] = j;
                }
            }
            //printf("%s", logics[i]);
            if (logics[i][0] == '*') {
                row = i;
                break;
            }
        }
        if (end) break;
        while (1) {
            scanf("%s", data);
            //printf("%s\n", data);
            if (data[0] == '*') break;
            for (int i = 0; i < row; i++) {
                for (int j = 0; logics[i][j]; j++) {
                    if (isupper(logics[i][j])) {
                        //�Է��� �ִ� ��ġ���� ����� ���� ����Ʈ �Ǵ� ��±��� ������ �����Ѵ�.
                        if (logics[i + dxy[0][0]][j + dxy[0][1]] == '|') move(i, j, data[logics[i][j] - 'A'] - '0', 0);
                        else if (logics[i + dxy[1][0]][j + dxy[1][1]] == '-') move(i, j, data[logics[i][j] - 'A'] - '0', 1);
                        else if (logics[i + dxy[2][0]][j + dxy[2][1]] == '|') move(i, j, data[logics[i][j] - 'A'] - '0', 2);
                        else if (logics[i + dxy[3][0]][j + dxy[3][1]] == '-') move(i, j, data[logics[i][j] - 'A'] - '0', 3);
                    }
                }
            }
            t = 0;
            while (t < gp) {
                for (int i = 0; i < gp; i++) {
                    if (!vis[gates[i][0]][gates[i][1] + 1] && vis[gates[i][0] - 1][gates[i][1] - 2] && vis[gates[i][0] + 1][gates[i][1] - 2]) {
                        //���� ó������ ���� ��� �Է��� ���ǵ� ����Ʈ�� ���
                        if (logics[gates[i][0]][gates[i][1]] == '>') {
                            //OR
                            move(gates[i][0], gates[i][1] + 1, nums[gates[i][0] - 1][gates[i][1] - 2] || nums[gates[i][0] + 1][gates[i][1] - 2], 1);
                        }
                        else {
                            //AND
                            move(gates[i][0], gates[i][1] + 1, nums[gates[i][0] - 1][gates[i][1] - 2] && nums[gates[i][0] + 1][gates[i][1] - 2], 1);
                        }
                        t++;
                    }
                }
            }
            printf("%c\n", nums[result[0]][result[1]] + '0');
            for (int i = 0; i < row; i++) {
                for (int j = 0; logics[i][j]; j++) {
                    vis[i][j] = 0; //�湮 �迭�� �ʱ�ȭ�Ѵ�.
                    nums[i][j] = 0;
                }
            }
        }
        printf("\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; logics[i][j]; j++) {
                logics[i][j] = '\0'; //�޾Ҵ� ������ �ʱ�ȭ�Ѵ�.
            }
        }
    }
    return 0;
}