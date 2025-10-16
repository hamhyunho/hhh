#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5

typedef struct {
    int id;            
    char name[20];     
    int stock;          
    int sales;         
} Product;

int main() {
    Product products[MAX_PRODUCTS] = { 0 };
    int menu;

    printf("[쇼핑몰 재고 관리 프로그램]\n");


    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i].id = i + 1;
        strcpy(products[i].name, "(미등록)");
    }

    while (1) {
        printf("\n> 원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 상품명 입력, 5. 종료)\n> ");
        scanf("%d", &menu);

     
        // 1. 입고
        if (menu == 1) {
            int input_type;
            printf("입고수량 입력 : 전체 상품 입고수량 입력(1), 개별 상품 입력(2)\n> ");
            scanf("%d", &input_type);

            if (input_type == 1) {
                int amount;
                printf("전체 상품의 입고수량을 입력하세요: ");
                scanf("%d", &amount);
                for (int i = 0; i < MAX_PRODUCTS; i++) {
                    products[i].stock += amount;
                }
                printf("전체 상품에 %d개씩 입고 완료!\n", amount);
            }
            else if (input_type == 2) {
                int id, amount;
                printf("상품ID (1~5): ");
                scanf("%d", &id);
                if (id < 1 || id > MAX_PRODUCTS) {
                    printf("잘못된 상품ID입니다.\n");
                    continue;
                }
                printf("입고수량: ");
                scanf("%d", &amount);
                products[id - 1].stock += amount;
                printf("[%s] 상품에 %d개 입고 완료!\n", products[id - 1].name, amount);
            }
        }

      
        // 2. 판매
        else if (menu == 2) {
            int input_type;
            printf("판매수량 입력 : 전체 상품 판매수량 입력(1), 개별 상품 입력(2)\n> ");
            scanf("%d", &input_type);

            if (input_type == 1) {
                int amount;
                printf("전체 상품의 판매수량을 입력하세요: ");
                scanf("%d", &amount);

                int can_sell = 1;
                for (int i = 0; i < MAX_PRODUCTS; i++) {
                    if (products[i].stock - products[i].sales < amount) {
                        can_sell = 0;
                        break;
                    }
                }

                if (can_sell) {
                    for (int i = 0; i < MAX_PRODUCTS; i++) {
                        products[i].sales += amount;
                    }
                    printf("전체 상품 판매 완료!\n");
                }
                else {
                    printf("재고가 부족하여 판매할 수 없습니다.\n");
                }
            }
            else if (input_type == 2) {
                int id, amount;
                printf("상품ID (1~5): ");
                scanf("%d", &id);
                if (id < 1 || id > MAX_PRODUCTS) {
                    printf("잘못된 상품ID입니다.\n");
                    continue;
                }
                printf("판매수량: ");
                scanf("%d", &amount);

                if (products[id - 1].stock - products[id - 1].sales >= amount) {
                    products[id - 1].sales += amount;
                    printf("[%s] 상품 판매 완료!\n", products[id - 1].name);
                }
                else {
                    printf("재고가 부족하여 판매할 수 없습니다.\n");
                }
            }
        }

        // 3. 상품현황 출력
        else if (menu == 3) {
            int total_sales = 0, total_stock = 0;

            printf("\n[상품현황]\n");
            printf("ID\t상품명\t입고\t판매\t재고\n");
            printf("---------------------------------\n");
            for (int i = 0; i < MAX_PRODUCTS; i++) {
                int inventory = products[i].stock - products[i].sales;
                printf("%d\t%s\t%d\t%d\t%d\n",
                    products[i].id, products[i].name, products[i].stock, products[i].sales, inventory);
                total_sales += products[i].sales;
                total_stock += products[i].stock;
            }

            double rate = 0;
            if (total_stock > 0)
                rate = (total_sales * 100.0) / total_stock;

            printf("---------------------------------\n");
            printf("총 판매량: %d (판매율 %.2f%%)\n", total_sales, rate);

            // 최대/최소 판매량 상품 찾기
            int max_id = 0, min_id = 0;
            for (int i = 1; i < MAX_PRODUCTS; i++) {
                if (products[i].sales > products[max_id].sales) max_id = i;
                if (products[i].sales < products[min_id].sales) min_id = i;
            }

            printf("가장 많이 판매된 상품: ID %d (%s), 판매량 %d\n",
                products[max_id].id, products[max_id].name, products[max_id].sales);
            printf("가장 적게 판매된 상품: ID %d (%s), 판매량 %d\n",
                products[min_id].id, products[min_id].name, products[min_id].sales);

            for (int i = 0; i < MAX_PRODUCTS; i++) {
                int remain = products[i].stock - products[i].sales;
                if (remain <= 2) {
                    printf("⚠️  상품 ID %d (%s) 재고부족(%d)\n",
                        products[i].id, products[i].name, remain);
                }
            }
        }

        // 4. 상품명 입력
        else if (menu == 4) {
            printf("상품명을 입력하세요:\n");
            for (int i = 0; i < MAX_PRODUCTS; i++) {
                printf("ID %d 상품명: ", i + 1);
                scanf("%s", products[i].name);
            }
        }

        // 5. 종료
        else if (menu == 5) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        // 잘못된 메뉴 선택
        else {
            printf("잘못된 메뉴 선택입니다.\n");
        }
    }

    return 0;
}
