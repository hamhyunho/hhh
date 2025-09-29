#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int stock[6] = { 0 }; 
    int sales[6] = { 0 };
    int n = 5;          
    int menu, id, qty;

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
        scanf("%d", &menu);

        if (menu == 1) {
            int sel;
            printf("입고수량 입력 : 전체상품(1), 개별상품(2)\n");
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
            printf("판매수량 입력 : 전체상품(1), 개별상품(2)\n");
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
        else if (menu == 3) { // 상품현황
            int total_stock = 0, total_sales = 0, total_in = 0;
            for (int i = 1; i <= n; i++) {
                total_stock += stock[i];
                total_sales += sales[i];
                total_in += stock[i] + sales[i];
            }

            
            for (int i = 1; i <= n; i++) printf("%d", stock[i]);
            printf("\n");

           
            double rate = total_in > 0 ? (double)total_sales / total_in * 100.0 : 0;
            printf("총 판매량: %d (판매율 %.2f%%)\n", total_sales, rate);

          
            int max_id = 1, min_id = 1;
            for (int i = 2; i <= n; i++) {
                if (sales[i] > sales[max_id]) max_id = i;
                if (sales[i] < sales[min_id]) min_id = i;
            }
            printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", max_id, sales[max_id]);
            printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", min_id, sales[min_id]);

            for (int i = 1; i <= n; i++) {
                if (stock[i] <= 2) {
                    printf("상품 ID %d : 재고부족(%d)\n", i, stock[i]);
                }
            }
        }
        else if (menu == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }
    return 0;
}
