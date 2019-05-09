#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 255
#define ALG 17
#include <locale.h>

int main(void)
{

    int opcao;

    setlocale(LC_ALL, "Portuguese");
    menu();
    printf("QUAL OPERAÇÃO DESEJA REALIZAR? ");
    scanf("%d", &opcao);
    do
        {
        if(opcao>=6)
        {
            system("cls");  //limpar conteudo anterior
            menu();
            printf("Digite uma opcao valida! ");
            scanf("%d", &opcao);
        }
    }
    while(opcao>=6);
    process_calc(opcao);
    return 0;
}

// Esta função converte um número decimal para a base 2, 8 ou 16.
// Recebe como parâmetro um número decimal (num_dec), e a base (base) cujo número será convertido.

void decToBase(int num_dec, int base)
//Declarando variaveis.
{
    char resto[ALG] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}, num_conv[SIZE];
    int indx = 0;
    setlocale(LC_ALL, "portuguese");

    // Este loop realiza as operações de divisão. Os restos são guardados no vetor 'num_conv'
    while(num_dec > 0)
    {
        num_conv[indx] = resto[num_dec % base];
        num_dec /= base;
        indx++;
    }

    // Exclui o caractere especial '\0' do final da string
    indx -= 1;

    // Utilizado para identificar a saída do programa
    switch(base)
    {
    case 2 :
        printf("Binario: ");
        break;
    case 8 :
        printf("Octal: ");
        break;
    case 16 :
        printf("Hexadecimal: ");
        break;
    }

    // Inverte a string contida no vetor num_conv
    for(indx; indx >= 0; indx--)
        printf("%c", num_conv[indx]);
    printf("\n");

}

// Esta função permite converter um número na base 2, 8 ou 16 para a base decimal.
// Recebe como parâmetro uma string (representação do número), e um número inteiro que
// determina em qual base está o número do primeiro parâmetro.
void baseToDec(char* num_base, int base)
{
    setlocale(LC_ALL, "portuguese");
    int indx = 0, exp = 0, len = 0, dec = 0, num = 0;

    // Este loop determina o tamanho da string
    while(num_base[len] != '\0')
    {
        len++;
    }

    // Neste loop, a string é percorrida de trás para frente. Cada caractere é convertido
    // em um número inteiro, multiplicado pela base elevada ao expoente (0..Comprimento da string)
    // e somado ao valor da variável 'dec', que recebe as somas sucessivas.
    for(exp, indx=(len-1); exp < len; exp++, indx--)
    {
        if(base == 16)
        {
            switch(num_base[indx])
            {
            case 'A' :
                num = 10;
                break;
            case 'a' :
                num = 10;
                break;
            case 'B' :
                num = 11;
                break;
            case 'b' :
                num = 11;
                break;
            case 'C' :
                num = 12;
                break;
            case 'c' :
                num = 12;
                break;
            case 'D' :
                num = 13;
                break;
            case 'd' :
                num = 13;
                break;
            case 'E' :
                num = 14;
                break;
            case 'e' :
                num = 14;
                break;
            case 'F' :
                num = 15;
                break;
            case 'f' :
                num = 15;
                break;
            default :
                num = (int)num_base[indx] - (int)'0';
            }
        }
        else
            num = (int)num_base[indx] - (int)'0';

        // Aqui avalia se o usuário digitou um número válido ou não!
        if(num > (base-1) || num < 0)
        {
            printf("Você informou um numero invalido!\n");
            exit(0);
        }
        dec += num * pow(base, exp);
    }

    // O número convertido para decimal é exibido
    printf("Decimal: %d\n", dec);
}

// Função que imprime o menu da calculadora
void menu(void)
{
    printf("\nBEM-VINDO AO CONVERSOR DE BASES NUMERICAS\n\n");
    printf("Qual Operacao Deseja Realizar? \n\n");
    printf("Selecione a opcao desejada:\n\n");
    printf(" 1 Binario para base Decimal\n");
    printf(" 2  Decimal para base Binario\n");
    printf(" 3  Octal para base Decimal\n");
    printf(" 4  Decimal para base Octal\n");
    printf(" 5  Hexadecimal para base Decimal\n");
    printf(" 6  Decimal para base Hexadecimal\n");
    printf(" 0  Sair\n\n");


}

// Função que chama as funções correspondentes à opção escolhida
void process_calc(int opt)
{

    int numero;
    char str[SIZE];
    switch(opt)
    {
    case 0 :
        system("cls");  //limpar conteudo anterior
        printf("Conversor Encerrado!\n");
        exit(0);
    case 1 :
        system("cls");  //limpar conteudo anterior
        printf("Digite o numero Binario: ");
        scanf("%s", str);
        baseToDec(str, 2);
        break;
    case 2 :
        system("cls");  //limpar conteudo anterior
        printf("Decimal:");
        scanf("%d", &numero);
        decToBase(numero, 2);
        break;

    case 3 :
        system("cls");  //limpar conteudo anterior
        printf("Digite o numero Octal: ");
        scanf("%s", str);
        baseToDec(str, 8);
        break;

    case 4 :
        system("cls");  //limpar conteudo anterior
        printf("Decimal");
        scanf("%d", &numero);
        decToBase(numero, 8);

        break;
    case 5 :
        system("cls");  //limpar conteudo anterior
        printf("Digite o numero Hexadecimal:");
        scanf("%s", str);
        baseToDec(str, 16);
        break;
    case 6 :
        system("cls");  //limpar conteudo anterior
        printf("Digite o numero Decimal: ");
        scanf("%d", &numero);
        decToBase(numero, 16);

        break;
    default :
        system("cls");  //limpar conteudo anterior
        printf("Opcao invalida!\nFavor digitar uma opcao valida\n");

        break;



    }
}

