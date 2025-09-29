#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int stock[6] = { 0 };   // ���
    int sales[6] = { 0 };   // �Ǹ�
    char names[6][50];      // ��ǰ�� ����
    int n = 5;              // ��ǰ ����
    int menu, id, qty;

    // �ʱ� ��ǰ�� ����α�
    for (int i = 1; i <= n; i++) {
        strcpy(names[i], "�Է¾ȵ�");
    }

    while (1) {
        printf("\n���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ��ǰ��Ȳ, 4. ��ǰ�� �Է�, 5. ����)\n");
        if (scanf("%d", &menu) != 1) break;

        if (menu == 1) {  // �԰�
            int sel;
            printf("�԰���� �Է� : ��ü��ǰ(1), ������ǰ(2)\n");
            if (scanf("%d", &sel) != 1) break;

            if (sel == 1) {
                for (int i = 1; i <= n; i++) {
                    if (scanf("%d", &qty) != 1) break;
                    stock[i] += qty;
                }
            }
            else if (sel == 2) {
                printf("��ǰID : ");
                if (scanf("%d", &id) != 1) break;
                printf("�԰���� : ");
                if (scanf("%d", &qty) != 1) break;
                stock[id] += qty;
            }
        }
        else if (menu == 2) {  // �Ǹ�
            int sel;
            printf("�Ǹż��� �Է� : ��ü��ǰ(1), ������ǰ(2)\n");
            if (scanf("%d", &sel) != 1) break;

            if (sel == 1) {
                for (int i = 1; i <= n; i++) {
                    if (scanf("%d", &qty) != 1) break;
                    if (qty > stock[i]) qty = stock[i];
                    stock[i] -= qty;
                    sales[i] += qty;
                }
            }
            else if (sel == 2) {
                printf("��ǰID : ");
                if (scanf("%d", &id) != 1) break;
                printf("�Ǹż��� : ");
                if (scanf("%d", &qty) != 1) break;
                if (qty > stock[id]) qty = stock[id];
                stock[id] -= qty;
                sales[id] += qty;
            }
        }
        else if (menu == 3) {  // ��ǰ��Ȳ
            int total_stock = 0, total_sales = 0, total_in = 0;
            for (int i = 1; i <= n; i++) {
                total_stock += stock[i];
                total_sales += sales[i];
                total_in += stock[i] + sales[i];
            }

            printf("\n������ : ");
            for (int i = 1; i <= n; i++) {
                printf("%d", stock[i]);
            }
            printf("\n");

            double rate = total_in > 0 ? (double)total_sales / total_in * 100.0 : 0;
            printf("�� �Ǹŷ� : %d (�Ǹ��� %.2f%%)\n", total_sales, rate);

            int max_id = 1, min_id = 1;
            for (int i = 2; i <= n; i++) {
                if (sales[i] > sales[max_id]) max_id = i;
                if (sales[i] < sales[min_id]) min_id = i;
            }

            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ�� : %s, �Ǹŷ� %d\n",
                max_id, names[max_id], sales[max_id]);
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ�� : %s, �Ǹŷ� %d\n",
                min_id, names[min_id], sales[min_id]);

            for (int i = 1; i <= n; i++) {
                if (stock[i] <= 2) {
                    printf("��ǰ ID %d : ��ǰ�� : %s ������(%d)\n", i, names[i], stock[i]);
                }
            }
        }
        else if (menu == 4) {  // ��ǰ�� �Է�
            printf("<< ��ǰ���Է� �޴� ���� >>\n");
            for (int i = 1; i <= n; i++) {
                printf("��ǰID %d ��ǰ�� : ", i);
                scanf("%s", names[i]);
            }
        }
        else if (menu == 5) {  // ����
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("�߸��� �Է��Դϴ�.\n");
        }
    }
    return 0;
}
