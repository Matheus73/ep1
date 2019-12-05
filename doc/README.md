# EP1 - OO 2019.2 (UnB - Gama)
## Feito por:
    **Matheus Gabriel Alves Rodrigues**
    **180106970**
## Descrição

O projeto se trata de um software para Loja local da Victoria, uma loja que atende a cidade local, nesse software existem diferentes modos de uso que devem ser considerados.


### Modos do Projeto


    - **Modo venda**
    - **Modo recomendação**
    - **Modo Venda**
    - **Consultar Historico de vendas**
    - **Cadastro de Clientes**
    

### Modo venda
O Modo venda serve para que um cliente previamente cadastrado possa comprar produtos oferecidos pelo estabelecimento comercial.

Para isso o funcionario deve:
    - **Digitar o CPF do cliente já cadastrado com 11 numeros**
    - **Digitar o código do produto que o cliente deseja comprar**
    - **Digitar a quantidade que está sendo comprada**

Ao fim da compra quando o cliente não desejar comprar mais produtos o programa mostra o preço total que o cliente deve pagar (incluindo já o desconto de 15% para socios) e disponibiliza para impressão o **Cupom Fiscal Da Compra** já com nome e CPF do cliente e produtos comprados.


### Modo estoque
Para manter o estoque do estabelecimento, existe o **Modo estoque** onde é possivel cadastrar produtos,gerenciar seus estoques e verificar se já estão cadastrados.

    #### Orientações:
        - **Código do produto deve conter 6 digitos**
        - **Categorias devem ser separadas por '/'**


### Modo recomendação
Este modo do programa serve para baseado no histórico de compras de um cliente o software recomenda uma lista de 10 produtos baseado nas categorias já compradas pelo cliente em vezes anteriores.

### Consultar Historico de vendas
Este Modo do software mostra o rendimento da loja desde que começou a utilizar o programa.

### Cadastro de clientes
    #### Orientações:
        - **Nome não deve conter numeros**
        - **CPF só é valido se tiver 11 numeros**
        - **email validado**

## Execução:
Para execultar o Software deve se usar o comando:

            _make_ 
seguido do comando:

             _make run_ 

na pasta do projeto
