#include <stdio.h>

/*
���� : W * H(W, H <= 2500) ũ���� ���簢������ K(K <= 100000)���� ���� �����鿡 ������ �� ����� ���Ѵ�.
���� S�� �־�����. S�� 1�� ��� px, py, qx, qy�� �־�����, px - qx, py - qy ������ ���簢���� ��Ʈ�� �����´�.
S�� 2�� ��� px, qx, r�� �־�����, (px, qx)���� rĭ �̳��� ������ ĭ���� ��Ʈ�� �����´�.

�ذ� ��� : 2���� ���� ���� �̿��� �� ������ ������ ����� ���� �� �ִ�.
1�� ������ ��� ���簢���� ���� ��, (������ �Ʒ� + (1, 1))�� ���� 1, (������ �� + (1, 0)), (���� �Ʒ� + (0, 1))�� ���� -1�� ���ϰ�,
2�� ������ ��쿡�� ��������� ���ʰ� (�Ʒ��� + (0, 2))�� ���� 1, �� ���� ĭ���� ��ĭ �ڿ� -1�� ���Ѵ�.
�̶� ���� ��ġ�� ������ ����� �ʵ��� �����Ѵ�.
�׸��� �������� �������� ���� ������ ���� ������Ʈ �ϱ� ���� ���� + (0, 1), �Ʒ��� + (0, 1)�� 1�� �� ���� ĭ + (1, 0)�� -1�� ���Ѵ�.
�� �������� 2���� �������� �� ���� ����� ����ϸ� �ȴ�.

�ֿ� �˰����� : ���� ��

��ó : ��ϴ� 2018 ����
*/

char sums[2560][2560], sumd[2560][2560], cnts[2560][2560], cntd[2560][2560], res[2560][2560];
//char ���·� �����ϴ��� �и�Ƽ�� ���� �ǹǷ� ĳ�� ��Ʈ���� ���� �ӵ��� �޸� ȿ���� ���� �� �ִ�.

int main(void) {
    int w, h, k, s, px, py, qx, qy, r;
    scanf("%d %d %d", &w, &h, &k);
    for (int kk = 0; kk < k; kk++) {
        scanf("%d", &s);
        if (s == 1) {
            scanf("%d %d %d %d", &px, &py, &qx, &qy);
            cnts[py][px]++; //���� ��
            cnts[qy + 1][qx + 1]++; //������ �Ʒ�
            cnts[py][qx + 1]--; //������ ��
            cnts[qy + 1][px]--; //���� �Ʒ�
        }
        else {
            scanf("%d %d %d", &px, &py, &r);
            cntd[py - r][px]++; //����
            cntd[py + r + 2][px]++; //�Ʒ���
            cntd[py + 1][px + r + 1]--; //������
            if (px > r) cntd[py + 1][px - r - 1]--; //���� ���� 0�� �ƴ� ���
            else cntd[py + 1][2559]--; //���� ���� 0�� ���
            cntd[py - r + 1][px]++; //����(����)
            cntd[py + r + 1][px]++; //�Ʒ���(����)
            cntd[py + 1][px - r]--; //����(����)
            cntd[py + 1][px + r]--; //������(����)
        }
    }

    for (int y = 0; y < h; y++) {
        sums[y][0] = cnts[y][0];
        for (int x = 1; x < w; x++) {
            sums[y][x] = sums[y][x - 1] + cnts[y][x]; //������ �������� ���Ѵ�.
        }
    }
    for (int x = 0; x < w; x++) {
        for (int y = 1; y < h; y++) {
            sums[y][x] += sums[y - 1][x]; //������ �������� ���Ѵ�.
        }
    }
    for (int y = 0; y < h; y++) {
        if (y == 0) sumd[y][0] = cntd[y][0];
        else sumd[y][0] = cntd[y][0] + cntd[y - 1][2559]; //-1�� ĭ�� ���� ó��
        for (int x = 1; x + y < h; x++) {
            sumd[y + x][x] = sumd[y + x - 1][x - 1] + cntd[y + x][x]; //������ �Ʒ� �밢���� ���� �������� ���Ѵ�. (���� ���)
        }
    }
    for (int x = 1; x < w; x++) {
        sumd[0][x] = cntd[0][x];
        for (int y = 1; x + y < w; y++) {
            sumd[y][y + x] = sumd[y - 1][y + x - 1] + cntd[y][y + x]; //������ �Ʒ� �밢���� ���� �������� ���Ѵ�. (���� ���)
        }
    }
    for (int y = 0; y < w + h; y++) {
        for (int x = w - 1; x >= 0; x--) {
            if (y < x + 1 || y - x > h) continue;
            sumd[y - x][x] += sumd[y - x - 1][x + 1]; //���� �Ʒ� �밢���� ���� �������� ���Ѵ�.
        }
    }
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if ((sums[y][x] + sumd[y][x]) & 1) res[y][x] = '#'; //���� �������� �������� ��Ʈ�� ���¸� ���Ѵ�.
            else res[y][x] = '.';
        }
    }
    for (int y = 0; y < h; y++) {
        printf("%s\n", res[y]);
    }
    return 0;
}