Descrição Geral

Este projeto é um sistema de gerenciamento para uma loja, permitindo ao usuário cadastrar produtos, visualizar informações, adicionar itens a um carrinho de compras e finalizar pedidos. O sistema é implementado em C e utiliza estruturas para organizar os dados de produtos e itens no carrinho.
Estruturas
Produto

    int code: Armazena o código identificador do produto.
    char name[MAX]: Armazena o nome do produto (até 49 caracteres).
    float price: Armazena o preço do produto.

A estrutura Produto representa um item que pode ser vendido.
Carrinho

    Product product: Um objeto do tipo Produto, representando um produto específico no carrinho.
    int quantity: Armazena a quantidade desse produto no carrinho.

A estrutura Carrinho agrupa um produto com a quantidade desejada.
Variáveis

    int totalProducts: Indica o número total de produtos cadastrados.
    int totalCartItems: Indica o número total de itens no carrinho.
    Product products[MAX]: Array que armazena os produtos cadastrados.
    Carrinho cart[MAX]: Array que armazena os itens no carrinho.

Funções do arquivo procedure.c

    RegisterProduct()
        Cadastra novos produtos, verificando se o limite de produtos foi atingido. Solicita informações como nome, código e preço. Limpa a tela após o cadastro.

    ListProducts()
        Exibe todos os produtos cadastrados, mostrando suas informações (nome, código e preço) de forma organizada.

    ProductInfo()
        Permite ao usuário buscar informações sobre um produto específico através do seu código. Se encontrado, exibe detalhes; caso contrário, informa que o produto não existe.

    PurchaseProduct()
        Adiciona um produto ao carrinho. Verifica se o produto já está no carrinho e, se sim, permite ao usuário adicionar mais unidades. Caso contrário, adiciona o produto ao carrinho.

    ViewCart()
        Mostra todos os produtos que estão no carrinho, incluindo nome, código, preço e quantidade.

    Checkout()
        Finaliza a compra e exibe uma fatura detalhada dos produtos no carrinho, calculando o total da compra e limpando o carrinho após a finalização.

    SaveProducts()
        Salva os produtos cadastrados em um arquivo de texto (produtos.txt).

    LoadProducts()
        Carrega produtos de um arquivo de texto para o sistema.

    ClearFile()
        Limpa o conteúdo do arquivo de produtos.

Função do arquivo tela.c

    menu()
        Apresenta um menu interativo para o usuário, permitindo a seleção de várias opções, como cadastrar produtos, listar produtos, procurar um único produto, comprar produtos, visualizar o carrinho e fechar pedidos.

Explicação dos arquivos .h
procedure.h

    Contém as declarações das funções utilizadas no sistema. Inclui proteções contra inclusões múltiplas.

tela.h

    Declara a função menu(), que apresenta o menu interativo ao usuário.

Explicação do arquivo main.c

    Inclusão de Bibliotecas
        Inclui locale.h para definir configurações regionais em português.
        Inclui tela.h para a função menu().

    Função Principal
        Configura o ambiente para português e chama a função menu() para iniciar a interação com o usuário..
