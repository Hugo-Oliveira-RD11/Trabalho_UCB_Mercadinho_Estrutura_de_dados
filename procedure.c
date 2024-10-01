#include "procedure.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct {
    int code;
    char name[MAX];
    float price;
} Product;

typedef struct {
    Product products;
    int quantity;
} Carrinho;

Product products[];
Carrinho cart[];
int totalProducts;
int totalCartItems;
void RegisterProduct() {
    int numProducts;

    if (totalProducts >= 50) {
      printf("Limite de produtos atingido!\n");
      return;
    }

    printf("Quantos produtos você deseja cadastrar? ");
    scanf("%d", &numProducts);

    if (numProducts + totalProducts > MAX) {
        printf("Limite de produtos atingido! Não é possível cadastrar essa quantidade.\n");
        return;
    }

    for (int i = 0; i < numProducts; i++) {
        Product *p = &products[totalProducts];

        printf("Produto número %d\n", i + 1);
        printf("Digite o nome do produto: ");
        scanf("%s", p->name);
        printf("Digite o código do produto: ");
        scanf("%d", &p->code);
        printf("Digite o preço do produto: ");
        scanf("%f", &p->price);

        totalProducts++;
    }
    SaveProducts();
    system("cls");
}

void ListProducts() {
    system("cls");
    printf("Listando produtos...\n");

    for (int i = 0; i < totalProducts; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: %s\nCódigo do produto: %d\nPreço: %.2f\n", products[i].name, products[i].code, products[i].price);
    }
}

void ProductInfo() {
    system("cls");
    int code;
    printf("Digite o código do produto: ");
    scanf("%d", &code);
    int found = 0;

    for (int i = 0; i < totalProducts; i++) {
        if (products[i].code == code) {
            printf("Produto: %s\nCódigo: %d\nPreço: %.2f\n", products[i].name, products[i].code, products[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Não existe produto com esse código!\n");
    }
}

void PurchaseProduct() {
    if (totalCartItems >= MAX) {
        printf("Limite de produtos no carrinho atingido!\n");
        return;
    }

    int code;
    printf("Digite o código que deseja adicionar ao carrinho: ");
    scanf("%d", &code);

    for (int i = 0; i < totalCartItems; i++) {
        if (cart[i].products.code == code) {
            int quantityToAdd;
            printf("O produto já está no carrinho. Quantas unidades você deseja adicionar? ");
            scanf("%d", &quantityToAdd);

            cart[i].quantity += quantityToAdd;
            printf("Quantidade atualizada. Total de unidades no carrinho: %d\n", cart[i].quantity);
            return;
        }
    }

    for (int i = 0; i < totalProducts; i++) {
        if (products[i].code == code) {
            int quantityToAdd;
            printf("Quantas unidades você deseja adicionar ao carrinho? ");
            scanf("%d", &quantityToAdd);

            cart[totalCartItems].products = products[i];
            cart[totalCartItems].quantity = quantityToAdd;
            totalCartItems++;
            printf("Produto adicionado ao carrinho.\n");
            return;
        }
    }

    printf("Produto não encontrado!\n");
}

void ViewCart() {
    printf("Produtos no carrinho:\n");
    for (int i = 0; i < totalCartItems; i++) {
        printf("Nome: %s\nCódigo: %d\nPreço: %.2f\nQuantidade: %d\n", cart[i].products.name, cart[i].products.code, cart[i].products.price, cart[i].quantity);
    }
    printf("\n");
}

void Checkout() {
    system("cls");

    if (totalCartItems == 0) {
        printf("O carrinho está vazio. Não é possível finalizar a compra!\n");
        return;
    }

    float totalOrder = 0.0f;
    printf("Fatura detalhada:\n");

    for (int i = 0; i < totalCartItems; i++) {
        printf("Produto: %s\nCódigo: %d\nPreço: %.2f\nQuantidade: %d\n", cart[i].products.name, cart[i].products.code, cart[i].products.price, cart[i].quantity);
        totalOrder += cart[i].products.price * cart[i].quantity;
    }

    printf("Total da compra: %.2f\n", totalOrder);
    totalCartItems = 0; // Limpa o carrinho
    printf("Carrinho limpo após a finalização do pedido.\n");
}


#define PRODUCT_FILE "produtos.txt"

void SaveProducts() {
    FILE *file = fopen(PRODUCT_FILE, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de produtos para escrita!\n");
        return;
    }

    fprintf(file, "Nome;Código;Preço\n");
    for (int i = 0; i < totalProducts; i++) {
        fprintf(file, "%s;%d;%.2f\n", products[i].name, products[i].code, products[i].price);
    }

    fclose(file);
    printf("Produtos salvos com sucesso em %s.\n", PRODUCT_FILE);
}

void LoadProducts() {
    FILE *file = fopen(PRODUCT_FILE, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de produtos para leitura!\n");
        return;
    }

    totalProducts = 0;
    char header[100];
    fgets(header, sizeof(header), file);

    while (fscanf(file, "%49[^;];%d;%f\n", products[totalProducts].name, &products[totalProducts].code, &products[totalProducts].price) == 3) {
        totalProducts++;
        if (totalProducts >= MAX) {
            printf("Limite de produtos atingido ao carregar!\n");
            break;
        }
    }

    fclose(file);
    printf("Produtos carregados com sucesso de %s.\n", PRODUCT_FILE);
}
void ClearFile(){
    FILE *f = fopen(PRODUCT_FILE, "w");
    fclose(f);
}
