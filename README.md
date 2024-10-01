 Descrição do que cada função faz no código.

### Estruturas

1. **Produto**:
    - int codigo: Armazena o código identificador do produto.
    - char nome[50]: Armazena o nome do produto, com até 49 caracteres (o último caractere é o terminador `\0`).
    - float preco: Armazena o preço do produto.

   A estrutura `Produto` é usada para representar um item que pode ser vendido.

2. **Carrinho**:
    - Produto produto: Um campo que contém um objeto do tipo `Produto`, representando um produto específico no carrinho.
    - int quant: Armazena a quantidade desse produto que está no carrinho.

   A estrutura `Carrinho` permite agrupar um produto e a quantidade desejada desse produto.

### Variáveis

- int totalP = MAX_P;: Inicializa a variável `totalP` com um valor máximo (que deve ser definido em outro lugar como `MAX_P`). Essa variável indica o número total de produtos que podem ser armazenados.

- int totalC = MAX_C;: Similarmente, inicializa `totalC` com um valor máximo (também deve ser definido como `MAX_C`), indicando o número total de itens que podem ser armazenados no carrinho.

- Produto produto;: Declara uma variável `produto` do tipo `Produto`, que pode ser usada para armazenar informações de um produto específico.

- Carrinho carrinho;: Declara uma variável `carrinho` do tipo `Carrinho`, que pode ser usada para armazenar um produto e sua quantidade no carrinho de compras.


## Funções do arquivo "procedure.c"

1. **CadProd**:

A função CadProd() é responsável por cadastrar produtos em um sistema de controle de estoque. Ela inicia verificando se o número total de produtos cadastrados já atingiu o limite máximo definido. Se o limite já foi alcançado, a função exibe uma mensagem informando que não é possível cadastrar mais produtos e encerra a execução.

Caso haja espaço para novos produtos, a função pede ao usuário a quantidade de produtos que deseja cadastrar. Em seguida, um loop é iniciado para coletar as informações de cada produto, incluindo nome, código e preço. A cada iteração, a função verifica se ainda há espaço para cadastrar mais produtos; se o limite for atingido durante o processo, uma mensagem de aviso é exibida e o loop é interrompido.

Após coletar os dados de um produto, a função incrementa o contador de produtos cadastrados para refletir a adição de um novo item. Por fim, a tela é limpa para proporcionar uma visualização mais organizada.

Assim, a função CadProd() permite ao usuário cadastrar múltiplos produtos, gerenciando efetivamente a quantidade total de produtos no sistema e garantindo que não exceda o limite estabelecido.

2. **ListarProd**

A função ListarProd() tem a finalidade de exibir uma lista dos produtos cadastrados no sistema. Ela começa com uma mensagem informativa, "Listando produtos...", indicando que a listagem está em andamento.

Em seguida, a função utiliza um loop para percorrer todos os produtos cadastrados, de 0 até totalP, que representa o número total de produtos. Para cada produto, a função imprime seu índice (começando em 1 para facilitar a compreensão) e exibe suas informações, incluindo o nome, o código identificador e o preço, formatado para mostrar duas casas decimais.

Ao final da listagem, a função limpa a tela usando o comando system("cls"), que é específico para sistemas Windows. Isso proporciona uma visualização mais organizada, preparando o ambiente para futuras interações do usuário.

Entretanto, é importante notar que a função parece usar apenas a última entrada da variável produto, o que sugere que o código pode precisar de ajustes para listar corretamente todos os produtos cadastrados.

3. **infoProd**

A função infoProd() tem como objetivo fornecer informações sobre um produto específico com base no código que o usuário insere. Inicialmente, a função solicita que o usuário digite o código do produto, que é armazenado na variável produto.codigo.

Em seguida, a função entra em um loop para percorrer todos os produtos cadastrados, de 0 até totalP. Dentro desse loop, a função verifica se o código do produto fornecido pelo usuário corresponde ao código do produto atual. No entanto, há um erro lógico na comparação, pois a função está comparando produto.codigo consigo mesma, o que sempre resulta em verdadeiro.

Se a condição fosse adequada, as informações do produto, incluindo o nome, o código e o preço formatado para duas casas decimais, seriam exibidas. Caso contrário, a função exibiria a mensagem "Não existe produto com código na lista!", mas essa mensagem seria repetida para cada produto que não corresponder, resultando em saídas indesejadas.

Por fim, a função limpa a tela com o comando system("cls"), preparando o ambiente para futuras interações. Em suma, a função tem a intenção de mostrar informações de um produto específico, mas necessita de correções para funcionar corretamente.

4. **carrinhoTem**

A função carrinhoTem() tem a finalidade de verificar se um produto específico já está presente no carrinho de compras. Para isso, a função inicia um loop que percorre todos os itens do carrinho, indo de 0 até totalC, que representa o total de itens cadastrados.

Dentro do loop, a função compara o código do produto no carrinho com o código do produto atual. Além disso, verifica se o nome do produto no carrinho é igual ao nome do produto em questão. Se uma dessas condições for verdadeira, a função retorna 1, indicando que o produto já está no carrinho.

No entanto, a função apresenta um erro na sua lógica: o retorno 0 está posicionado dentro do loop, o que faz com que a função retorne imediatamente 0 se o primeiro produto no carrinho não corresponder, sem verificar os demais itens. Isso significa que a função pode falhar em identificar corretamente a presença do produto no carrinho.

Em resumo, a função tem o objetivo de verificar a existência de um produto no carrinho, mas necessita de ajustes para funcionar corretamente, especialmente no que diz respeito à lógica de retorno.

5. **ComprarProd**

A função ComprarProd() tem como objetivo permitir que um usuário adicione um produto ao carrinho de compras. Inicialmente, a função verifica se o total de itens no carrinho (totalC) já atingiu o limite máximo (MAX_C). Se o limite for alcançado, uma mensagem é exibida informando que não é possível adicionar mais produtos, e a execução da função é encerrada.

Em seguida, a função deve verificar se o produto que o usuário deseja adicionar já está presente no carrinho. No entanto, a forma como isso é feito não está correta, já que o resultado da verificação não é utilizado adequadamente.

A função então solicita ao usuário que digite o código ou o nome do produto que deseja adicionar. No entanto, a maneira como os dados são lidos está incorreta, pois o scanf não está configurado para capturar as entradas de forma adequada.

Após a entrada de dados, a função verifica se o produto já está no carrinho, mas essa verificação também está mal implementada. Se o produto não estiver presente, a função tenta adicioná-lo ao carrinho. No entanto, a sintaxe usada para armazenar a quantidade do produto está errada, além de não estar claro como a quantidade é gerenciada.

Por fim, a função imprime uma mensagem indicando que o produto foi adicionado ao carrinho, mas, devido aos erros anteriores, essa ação pode não ocorrer conforme esperado. Em resumo, a função tem a intenção de adicionar um produto ao carrinho, mas apresenta diversas falhas que precisam ser corrigidas para que funcione corretamente.

6. **visualizarProd**

A função visualizarProd() tem como objetivo exibir os produtos que estão atualmente no carrinho de compras. Ela inicia imprimindo a mensagem "Produtos no carrinho:", informando ao usuário que a lista dos itens será apresentada.

Em seguida, a função utiliza um loop que percorre todos os itens no carrinho, de 0 até totalC, que representa o total de itens armazenados. Para cada produto, a função tenta imprimir suas informações, incluindo o nome, o código e o preço.

No entanto, há um erro na implementação: a função sempre acessa carrinho.produto, o que significa que ela exibirá apenas os dados do último produto adicionado ao carrinho, ignorando os demais itens. Essa abordagem resulta em uma listagem inadequada.

Em resumo, a função tem a intenção de listar os produtos no carrinho de compras, mas precisa de correções para acessar e exibir corretamente as informações de cada item, garantindo que todos os produtos sejam mostrados na saída.

7. **FecharPedido**

A função FecharPedido() tem como objetivo finalizar a compra e apresentar um resumo da fatura dos produtos que estão no carrinho.

A função começa verificando se o carrinho está vazio, checando se totalP é igual a zero. Se o carrinho estiver vazio, uma mensagem é exibida informando que não é possível finalizar a compra, e a execução da função é encerrada.

Se o carrinho contém produtos, a função inicializa a variável totalPedido com zero, que será usada para acumular o preço total dos itens. Em seguida, imprime um cabeçalho "Fatura detalhada:" e inicia um loop que percorre todos os itens do carrinho. Durante cada iteração, a função tenta imprimir o nome, o código e o preço de cada produto. No entanto, há um erro, pois a função acessa sempre carrinho.produto, resultando na exibição apenas dos dados do último produto adicionado, em vez de listar todos os itens.

Enquanto itera pelos produtos, o preço de cada um é adicionado à variável totalPedido, que acumula o custo total da compra. Após o loop, o total da compra é exibido, formatado para duas casas decimais.

A função então redefine totalC para zero, limpando o carrinho e indicando que não há mais produtos a serem comprados. Por fim, a tela é limpa usando o comando system("cls"), preparando o ambiente para futuras interações.

Em resumo, a função busca finalizar a compra e apresentar uma fatura detalhada, mas apresenta erros que precisam ser corrigidos, especialmente na forma como as informações dos produtos são acessadas e exibidas.


## Função do arquivo "tela.c"

1. **menu**

A função menu() tem como objetivo apresentar um menu interativo para o usuário em um sistema de gerenciamento de uma loja, permitindo que ele escolha diferentes opções de operação. A função inicia com uma mensagem de boas-vindas: "Bem-vindo a Lojinha da UCB!".

Dentro de um loop do-while, o menu é exibido repetidamente até que o usuário decida sair. As opções disponíveis incluem:

- Cadastrar produtos.
- Listar produtos.
- Procurar por um único produto.
- Comprar produtos.
- Visualizar o carrinho.
- Fechar o pedido.
- Sair.

O usuário é solicitado a inserir um número correspondente à opção desejada, que é lido e armazenado na variável op. Um switch é então utilizado para executar a função associada à opção escolhida:

- Para a opção 1, a função CadProd() é chamada para cadastrar novos produtos.
- A opção 2 chama ListarProd() para listar os produtos cadastrados.
- A opção 3 aciona infoProd() para procurar informações sobre um único produto.
- A opção 4 invoca ComprarProd() para adicionar produtos ao carrinho.
- A opção 5 chama VisualizarProd() para mostrar os produtos no carrinho.
- A opção 6 ativa FecharPedido() para finalizar a compra.
- Para a opção 7, o usuário é solicitado a confirmar se realmente deseja sair. Uma variável sr é utilizada para armazenar a resposta, embora a leitura dessa entrada possa não funcionar corretamente devido a problemas de manipulação de entrada.

Caso o usuário insira uma opção inválida, uma mensagem informando que a opção não é válida é exibida. O loop continua até que o usuário escolha a opção de sair.


## Explicação dos arquivos ".h"

1. **procedure.h**

O trecho de código apresentado é um cabeçalho de um arquivo em C que contém as declarações de várias funções utilizadas em um sistema de gerenciamento de produtos em uma loja. Aqui está uma descrição detalhada de cada parte do código:

Descrição do Código
1. 1. Inclusão de Bibliotecas:

- #include <stdio.h>: Inclui a biblioteca padrão de entrada e saída, que permite usar funções como printf e scanf.
- #include <stdlib.h>: Inclui a biblioteca padrão da linguagem C, que fornece funções como malloc, free, e exit.
- #include <string.h>: Inclui a biblioteca que contém funções para manipulação de strings, como strcpy, strlen, entre outras.
- #include <windows.h>: Inclui a biblioteca da API do Windows, que permite o uso de funções específicas do sistema operacional, como manipulação de janelas e controle de console.
- #include <locale.h>: Inclui a biblioteca que permite definir e manipular configurações regionais, como formatos de data e moeda.
1. 2. Diretiva de Pré-processador:

- #ifndef PROCEDURE_H: Verifica se PROCEDURE_H ainda não foi definido. Isso é parte da técnica de inclusão de cabeçalho, que evita que o arquivo seja incluído mais de uma vez.
- #define PROCEDURE_H: Define a constante PROCEDURE_H para que, em inclusões futuras do arquivo, o código contido dentro do #ifndef e #define não seja processado novamente.

1. 3. Declaração de Funções:

- void CadProd();: Declara a função que será responsável por cadastrar produtos.
- void ListarProd();: Declara a função para listar os produtos cadastrados.
- void infoProd();: Declara a função que busca informações sobre um único produto.
- int carrinhoTem();: Declara a função que verifica se um produto já está no carrinho.
- void ComprarProd();: Declara a função para adicionar produtos ao carrinho.
- void VisualizarProd();: Declara a função que exibe os produtos no carrinho.
- void FecharPedido();: Declara a função para finalizar a compra e mostrar a fatura.

1. 4. Diretiva de Finalização:

- #endif //PROCEDURE_H: Finaliza a estrutura condicional iniciada com #ifndef.

2. **telas.h**

O trecho de código apresentado é um cabeçalho de um arquivo em C que contém a declaração de uma função. Aqui está uma descrição detalhada de cada parte do código:

Descrição do Código

2. 1. Diretivas de Pré-processador:

- #ifndef TELA_H: Verifica se TELA_H ainda não foi definido. Isso ajuda a evitar a inclusão múltipla do mesmo cabeçalho em um projeto, o que poderia levar a erros de compilação.
- #define TELA_H: Define a constante TELA_H para que, em futuras inclusões desse arquivo, o conteúdo entre #ifndef e #endif não seja processado novamente.

2. 2. Declaração da Função:

- void menu();: Declara a função menu(), que será responsável por apresentar um menu interativo ao usuário. Esta função provavelmente permitirá que o usuário selecione diferentes opções para interagir com o sistema.

2. 3. Diretiva de Finalização:

- #endif //TELA_H: Finaliza a estrutura condicional iniciada com #ifndef, garantindo que o cabeçalho seja incluído apenas uma vez.

## Explicação do arquivo "main.c"

O trecho de código apresentado é a função principal (main()) de um programa em C que utiliza um sistema de menus. Aqui está uma descrição detalhada do que cada parte faz:

Descrição do Código

1. Inclusão de Bibliotecas:

- #include <locale.h>: Inclui a biblioteca que permite definir e manipular configurações regionais. Nesse caso, é usada para ajustar a linguagem e o formato de saída para o português.

2. Inclusão do Cabeçalho Personalizado:

- #include "tela.h": Inclui o cabeçalho que contém a declaração da função menu(), que é responsável por apresentar um menu interativo ao usuário.

3. Função Principal:

- int main() { ... }: Define a função principal do programa, onde a execução começa.

4. Configuração de Localização:

- setlocale(LC_ALL, "Portuguese");: Configura o ambiente para usar as configurações de localização em português. Isso é útil para garantir que a formatação de números, datas e mensagens esteja de acordo com as convenções do idioma.

5. Chamada da Função menu():

- menu();: Chama a função menu(), que apresentará ao usuário as opções disponíveis para interagir com o sistema.