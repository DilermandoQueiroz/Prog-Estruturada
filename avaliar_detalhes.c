#include "biblioteca.h"

/*Avalia um livro
*/
int avaliar(struct livros livro[], int contador){

    char nome[20];
    printf("\n Por favor, entre com o nome do livro que deseja avaliar:\n");
    fflush(stdin);
    gets(nome);

    int id = id_nome(nome);
    int aux = 0;
    int cont = 0;
    int nota = 0;

    // Encontrar o livro na lista
    while(aux == 0){

        if(id == livro[cont].id){

            while(aux == 0){

                printf("\n Entre com a sua avaliacao(0-100):\n");
                scanf("%i", &nota);

                // Verificar se a nota inserida est� no intervalo indicado
                if(nota<0 || nota>100){

                    printf("\n Nota invalida!\n");
                }
                else{

                    aux = 1;
                }
            }

            printf("\n Obrigado!\n");

            // Atualizar a m�dia do livro

            int n = livro[cont].qtd_avaliacoes;
            int media = livro[cont].avaliacao;

            media = (n*media+nota)/(n+1);

            livro[cont].qtd_avaliacoes = n+1;
            livro[cont].avaliacao = media;

        }

        // Se o nome do livro ja foi comparado com todos os nomes do vetor, este ainda nao foi cadastrado
        if(cont == contador+1){
            printf("\n Este livro ainda nao foi cadastrado.\n");
            aux = 1;
        }
        cont = cont+1;
    }

    return contador;
}

void detalhes(struct livros livro[], int contador){
    char nome[50];

    fflush(stdin);
    printf("\n Insira o nome do livro que voce gostaria de saber detalhes: \n");
    gets(nome);

    int id = id_nome(nome);
    int aux = 0;
    int cont = 0;

    // Encontrar o livro na lista de livros cadastrados
    while(aux == 0){
        if(id == livro[cont].id){
            aux = 1;
            printf("\n O livro '%s' foi alugado %i vezes, avaliado por %i pessoas e possui media %i.\n", nome, livro[cont].qtd_alugado, livro[cont].qtd_avaliacoes, livro[cont].avaliacao);
            printf("Existem %i copias em nosso estoque.\n\n", livro[cont].qtd_estoque);
        }
        if(cont == contador+1){
            printf("Este livro ainda nao foi cadastrado.\n\n");
            aux = 1;
        }
        cont = cont + 1;
    }

    int a =0;
    aux = 0;

    while(aux==0){
        printf("Gostaria de saber mais detalhes sobre outro livro? \n Digite 1 - Sim \n Digite 2 - Nao\n");

        scanf("%i", &a);

        if(a == 1){
            detalhes(livro,contador);
            aux = 1;
        }
        else if(a == 2){
            aux = 1;
            printf("\n Ate logo!\n");
        }
        else{
            printf("\n Essa entrada nao eh valida\n\n");
        }
    }
}
