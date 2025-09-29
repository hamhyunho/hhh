#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int stock[6] = { 0 }; 
    int sales[6] = { 0 };
    int n = 5;          
    int menu, id, qty;

    while (1) {
        printf("\n[���θ� ���� ���α׷�]\n");
        printf("���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ��ǰ��Ȳ, 4. ����)\n");
        scanf("%d", &menu);

        if (menu == 1) {
            int sel;
            printf("�԰���� �Է� : ��ü��ǰ(1), ������ǰ(2)\n");
            scanf("%d", &sel);

            if (sel == 1) {
                for (int i = 1; i <= n; i++) {
                    scanf("%d", &qty);
                    stock[i] += qty;
                }
            }
            else if (sel == 2) {
                scanf("%d %d", &id, &qty);
                stock[id] += qty;
            }
        }
        else if (menu == 2) {
            int sel;
            printf("�Ǹż��� �Է� : ��ü��ǰ(1), ������ǰ(2)\n");
            scanf("%d", &sel);

            if (sel == 1) {
                for (int i = 1; i <= n; i++) {
                    scanf("%d", &qty);
                    if (qty > stock[i]) qty = stock[i];
                    stock[i] -= qty;
                    sales[i] += qty;
                }
            }
            else if (sel == 2) {
                scanf("%d %d", &id, &qty);
                if (qty > stock[id]) qty = stock[id];
                stock[id] -= qty;
                sales[id] += qty;
            }
        }
        else if (menu == 3) { // ��ǰ��Ȳ
            int total_stock = 0, total_sales = 0, total_in = 0;
            for (int i = 1; i <= n; i++) {
                total_stock += stock[i];
                total_sales += sales[i];
                total_in += stock[i] + sales[i];
            }

            
            for (int i = 1; i <= n; i++) printf("%d", stock[i]);
            printf("\n");

           
            double rate = total_in > 0 ? (double)total_sales / total_in * 100.0 : 0;
            printf("�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", total_sales, rate);

          
            int max_id = 1, min_id = 1;
            for (int i = 2; i <= n; i++) {
                if (sales[i] > sales[max_id]) max_id = i;
                if (sales[i] < sales[min_id]) min_id = i;
            }
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", max_id, sales[max_id]);
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", min_id, sales[min_id]);

            for (int i = 1; i <= n; i++) {
                if (stock[i] <= 2) {
                    printf("��ǰ ID %d : ������(%d)\n", i, stock[i]);
                }
            }
        }
        else if (menu == 4) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("�߸��� �Է��Դϴ�.\n");
        }
    }
    return 0;
}
