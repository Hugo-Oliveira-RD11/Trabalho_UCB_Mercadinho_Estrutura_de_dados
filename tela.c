#include "tela.h"
#include "string.h"

void menu() {
    int op;

    char ch;
    printf("deseja voltar com os produtos e o carrinho cadastrados anteriomente? [S/N]: ");
    scanf(" %c", &ch);
    if( ch == 's' || ch == 'S'){
        LoadProducts();
        ListProducts();
        printf("/n");
    }

    printf("/t/tBem-vindo ao mercadinho da esquina!\n\n");

    do {
        printf("Escolha uma opção para continuar:\n"
               "1 - Cadastrar produtos.\n"
               "2 - Lista produtos.\n"
               "3 - Procura por um único produto.\n"
               "4 - Comprar produtos.\n"
               "5 - Visualizar carrinho.\n"
               "6 - Fechar pedido.\n"
               "7 - Sair.\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                RegisterProduct();
                break;
            case 2:
                ListProducts();
                break;
            case 3:
                ProductInfo();
                break;
            case 4:
                PurchaseProduct();
                break;
            case 5:
                ViewCart();
                break;
            case 6:
                Checkout();
                break;
            case 7:
                char sr;
                printf("Tem certeza que deseja sair? (s/n): ");
                scanf(" %c", &sr);
                if (sr == 's' || sr == 'S') {
                    printf("Deseja apaga o historico dos produtos? (s/n): ");
                    scanf(" %c", &sr);
                        if (sr == 's' || sr == 'S')
                            ClearFile();
                    printf("Saindo...\n");
                    return;
                }
                system("cls");
                printf("Voltando...\n");
                break;
            default:
                printf("Digite uma opção válida!\n");
                break;
        }
    } while (op != 7);
}
