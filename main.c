#include<stdio.h>
#include<stdlib.h>

//Variáveis gerais
float saldo_total = 0;
int tent = 0;

//Variáveis verificar_extrato()
char extrato[3][50];
int totalExtrato = 0;


int menu(){
    int opcao;
    
    printf("=================================\n");
    printf("         CAIXA ELETRONICO        \n");
    printf("=================================\n");

    printf("Selecione o que deseja fazer: \n1- Consultar Saldo \n2- Verificar Extrato \n3- Realizar Saque \n4- Realizar Deposito \n5- Sair \n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    while(getchar() != '\n');
    printf("\n");

    while(opcao < 1 || opcao > 5){
        printf("\nValor Invalido! Escolha entre as opcoes validas:\n");
        printf("1- Consultar Saldo \n2- Verificar Extrato \n3- Realizar Saque \n4- Realizar Deposito \n5- Sair \n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        while(getchar() != '\n');
        printf("\n");
    }

    return opcao;
}

float realizar_saque(float saldo_atual) {
    float valor_saque = 0;

    printf("-------------------------------\n");
    printf("             SAQUE             \n");
    printf("-------------------------------\n");

    printf("Saldo atual: ");
    printf("R$ %.2f\n", saldo_atual);
    printf("Qual valor voce deseja sacar? R$");
    scanf("%f", &valor_saque);
    while(getchar() != '\n');
    printf("\n");


    while(valor_saque<=0){
        tent += 1;
        if(tent>=3){
            break;
        }else{
        printf("Valor invalido, digite outro valor: R$");
        scanf("%f", &valor_saque);
        while(getchar() != '\n');
        }            
    }
    if(tent>=3){
        printf("Limite de tentativas excedido, tente novamente mais tarde\n");
    }else{
        if(valor_saque>1000){
            printf("Limite diario excedido\n");
        }else if(valor_saque<=saldo_atual){
            saldo_atual -= valor_saque;
            printf("Saque autorizado, aguarde a contagem das cedulas\n");
            printf("\n");
            printf("Saldo atual: ");
            printf("R$ %.2f\n", saldo_atual);
            sprintf(extrato[totalExtrato % 3], "Saque: -R$ %.2f", valor_saque);
            totalExtrato++;
            printf("\n");
        }else{
            printf("Saldo insuficiente\n");
            printf("\n");
        }
    }  

    return saldo_atual;
}

float realizar_deposito(float saldo_atual) {
    float valor_deposito = 0;

    printf("-------------------------------\n");
    printf("           DEPOSITO             \n");
    printf("-------------------------------\n");

    while (valor_deposito <= 0) {
        printf("Digite o valor do deposito: R$");
        scanf("%f", &valor_deposito);
        while(getchar() != '\n');
        printf("\n");

        if (valor_deposito > 0) {

            saldo_atual += valor_deposito;
            printf("Deposito realizado!\n");
            printf("\n");
            printf("Saldo atualizado: R$%.2f\n", saldo_atual);
            sprintf(extrato[totalExtrato % 3], "Deposito: +R$ %.2f", valor_deposito);
            totalExtrato++;
            printf("\n");
        }else{
            printf("Valor invalido! Tente novamente com um valor positivo.\n");
            printf("\n");
        }
    }

    return saldo_atual;
}

void verificar_saldo(float saldo_total){
    printf("---------------------------------\n");
    printf("Saldo Atual: R$ %.2f\n", saldo_total);
    printf("---------------------------------\n");
    printf("\n");
}

void verificar_extrato(float saldo_total) {
    printf("-------------------------------\n");
    printf("           EXTRATO             \n");
    printf("-------------------------------\n");

    if(totalExtrato == 0){
        printf("Nenhuma movimentacao feita\n");
    }else{
        
        int quantidade = totalExtrato < 3 ? totalExtrato : 3;
        int inicio = totalExtrato % 3;

        for (int i = 0; i < quantidade; i++) {
            printf("%s\n", extrato[(inicio + i) % 3]);
        }
    }

    printf("\n");
    printf("SALDO FINAL: R$%.2f\n", saldo_total);
}

int main(){    
    int opcao_escolhida = menu();

    do{
        switch(opcao_escolhida){
            case 1:
               verificar_saldo(saldo_total);
               system("pause");
               system("cls");
            break;

            case 2:
                verificar_extrato(saldo_total);
                system("pause");
                system("cls");
            break;

            case 3:
                saldo_total = realizar_saque(saldo_total);
                system("pause");
                system("cls");
            break;

            case 4:
                saldo_total = realizar_deposito(saldo_total);
                system("pause");
                system("cls");
            break;            
        }

        opcao_escolhida = menu();
    }while(opcao_escolhida != 5);

    printf("Muito obrigado por utilizar nosso Caixa Eletronico!\n");
    printf("Sistema Encerrado!");
    printf("\n");
    system("pause");
    system("cls");
    
    return 0;
}
