#include<stdio.h>
//Variáveis gerais
float saldo_total = 0;

//Variáveis consultar_saldo()

//Variáveis verificar_extrato()

//Variáveis realizar_saque()

//Variáveis realizar_deposito()

int menu(){
    int opcao;
    
    printf("================\n");
    printf("CAIXA ELETRONICO\n");
    printf("=================\n");
    printf("\n");

    printf("Selecione o que deseja fazer: \n1- Consultar Saldo \n2- Verificar Extrato \n3- Realizar Saque \n4- Realizar Deposito \n5- Sair \n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    while(opcao < 1 || opcao > 5){
        printf("\nValor Invalido! Escolha entre as opcoes validas:\n");
        printf("1- Consultar Saldo \n2- Verificar Extrato \n3- Realizar Saque \n4- Realizar Deposito \n5- Sair \n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("\n");
    }

    return opcao;
}

int realizar_deposito() {
    float valor_deposito = 0;

    while (valor_deposito <= 0) {
        printf("Digite o valor do deposito: ");
        scanf("%f", &valor_deposito);
        printf("\n");

        if (valor_deposito > 0) {
            saldo_total += valor_deposito;
            printf("Deposito realizado!\n");
            printf("Saldo atualizado: R$%.2f\n", saldo_total);
            printf("\n");
        } else {
            printf("Valor invalido! Tente novamente com um valor positivo.\n");
            printf("\n");
        }
    }

    return 0;
}

int main(){    
    int opcao_escolhida = menu();
    
    while(opcao_escolhida != 5){
        switch(opcao_escolhida){
            case 1:

            break;

            case 2:

            break;

            case 3:

            break;

            case 4:
                realizar_deposito();
            break;            
        }

        opcao_escolhida = menu();
    }

    printf("Muito obrigado por utilizar nosso Caixa Eletronico!\n");
    printf("Sistema Encerrado!");
    printf("\n");
    
    return 0;
}