#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LDE.h"

int main(){

    List* contactsList= createList();

    int choice = -1;
    while(choice != 0){
        printf("Selecione uma opção para continuar:\n");

        printf("######################################################\n");
        printf("##########Sistema de contatos telefonicos#############\n");
        printf("######################################################\n");
        printf("# 1   -  Inserir um contato.                         #\n");
        printf("# 2   -  Remove um contato                           #\n");
        printf("# 3   -  Mostrar lista de contatos.                  #\n");        
        printf("# 4   -  Mostrar tamanho da lista.                   #\n");
        printf("# 5   -  Excluir todos os contatatos da lista.       #\n");        
        printf("# 6   -  Ordenacao simples com insertionSort.        #\n");        
        printf("# 7   -  Ordenacao eficiente com shellSort.          #\n");        
        printf("# 8   -  Teste de carga comparando inserções.        #\n");        
        printf("# 999 -  Criar base de testes.                       #\n");
        printf("# 0   -  Sair do sistema.                            #\n");
        printf("######################################################\n\n");

        printf("------------------------------------------------------\n");
        printf("Informe a opcao escolhida:");
        scanf("%d", &choice);
        printf("------------------------------------------------------\n");

        switch(choice){
            int position;
            int listOption;
            clock_t timeControl;
            case -1:
            break;
            case 1: ;
                int insertionType = 0;
                Person* personToInsert = createVoidPerson();

                printf("Escolha a forma de insercao conforme os codigos a seguir:\n\n");
                printf("1- inserir no final da fila\n");
                printf("2- inserir no inicio da fila\n");
                printf("3- inserir em uma posicao especifica\n");                

                scanf("%d", &insertionType);

                switch(insertionType){
                    case 1:
                    push(contactsList, personToInsert);
                    break;

                    case 2:
                    unshift(contactsList, personToInsert);
                    break;

                    case 3: ;
                    int positionToInsert = 0;
                    printf("Escolha uma posicao para inserir:");
                    scanf("%d", &positionToInsert);
                    insertPosition(contactsList, personToInsert, positionToInsert);
                    break;

                    default: ;
                    printf("Tipo de insercao invalido\n\n");
                    pause();
                }
                pause();                
                break;
            case 2: ;  
                int deleteType = 0;       

                printf("Escolha a forma de exclusao conforme os codigos a seguir:\n\n");
                printf("1- excluir no final da fila\n");
                printf("2- excluir no inicio da fila\n");
                printf("3- excluir em uma posicao especifica\n");                

                scanf("%d", &deleteType);

                switch(deleteType){
                    case 1:
                    pop(contactsList);
                    break;

                    case 2:
                    shift(contactsList);
                    break;

                    case 3: ;
                    int positionToDelete = 0;
                    printf("Escolha uma posicao para excluir:");
                    scanf("%d", &positionToDelete);
                    removePosition(contactsList, positionToDelete);
                    break;

                    default: ;
                    printf("Tipo de insercao invalido\n\n");
                    pause();
                } 
                break;

            case 3: ;
                int showType = 0;
                printf("Escolha a forma que gostaria de ver a lista:\n\n");
                printf("1- Do primeiro elemento ate o ultimo\n");
                printf("2- Do ultimo elemento ate o primeiro\n");
                scanf("%d", &insertionType);

                switch(insertionType){
                    case 1:
                    showListAsc(contactsList);
                    break;

                    case 2:
                    showListDesc(contactsList);
                    break;

                    default: 
                    printf("Forma de visualizacao selecionada nao existe\n\n");
                    pause();
                    break;
                }
                break;
            case 4: ;
                printf("O tamanho atual da lista eh de %d elementos.\n\n", size(contactsList));
                pause();
                break;
            case 5: ;
                dropList(contactsList);                
                break;           
            case 6: ;
                timeControl = clock();
                bubbleSort(contactsList, contactsList->length);         
                printf("Tempo de execucao do bubbleSort de %lf segundos", ((double)timeControl)/((CLOCKS_PER_SEC/1000)));
                break;  
            case 7: ;
                timeControl = clock();
                shellSort(contactsList);         
                printf("Tempo de execucao do shellSort de %lf segundos", ((double)timeControl)/((CLOCKS_PER_SEC/1000)));
                break;  
            case 8: ;                
                dropList(contactsList);
                fillContactList(contactsList);                
                timeControl = clock();
                bubbleSort(contactsList, contactsList->length);
                timeControl = clock() - timeControl;                
                printf("Teste de tempo com bubbleSort de [%lf] segundos...\n", ((double)timeControl)/((CLOCKS_PER_SEC/1000)));

                dropList(contactsList);
                fillContactList(contactsList);
                timeControl = clock();
                shellSort(contactsList);       
                timeControl = clock() - timeControl;  
                printf("Teste de tempo com shellSort de [%lf] segundos...\n", ((double)timeControl)/((CLOCKS_PER_SEC/1000)));

                pause();
                
                break;  
            case 0:
                printf("Volte sempre!\n");
                break;
            case 999:
                fillContactList(contactsList);
                break;
            default:
                printf("Opcao invalida! Escolha uma opcao entre as disponiveis na lista!\n\n");
                pause();
                break;
        }
    }

    return 0;
}
