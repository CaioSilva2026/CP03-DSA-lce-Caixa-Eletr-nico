#include<stdio.h>

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

int main(){
    while(menu() != 5){

    }

    printf("Muito obrigado por utilizar nosso Caixa Eletronico!\n");
    printf("Sistema Encerrado!");
    printf("\n");
    
    return 0;
}