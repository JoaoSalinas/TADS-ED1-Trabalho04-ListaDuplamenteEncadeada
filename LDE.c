#include "LDE.h"
#include <malloc.h>
#include <stddef.h>
#include <string.h>

/**

Implemente uma lista telefônica. A lista deve ser implementada utilizando os conceitos
de Lista Duplamente Encadeada – LDE.

Para cada elemento da lista armazenar (Nome, telefone e Idade);

Inserir no mínimo 20 registros (Elementos);

Implementar dois algoritmos de Ordenação:
    Um Método Simples (Selection Sort, Insertion Sort ou Bubble Sort)
    Um Método Eficiente (ShellSort ou QuickSort)

Ordenar de modo Crescente por idade:
    Apresentar a lista Original
    Apresentar as listas Ordenadas 

Avaliar o desempenho:
    Tempo de Execução 
    Resultados
*/

List* createList(){
    List* list = (List *)malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
    list->length = 0;        
    return list;
}

Person* createPerson(char name[],char phone[], int age){
    Person* person = (Person *)malloc(sizeof(Person));
    strcpy(person->name, name);
    strcpy(person->phone, phone);
    person->age = age;
    person->previous = NULL;
    person->next = NULL;
}

Person* createVoidPerson(){
    Person* person = (Person *)malloc(sizeof(Person));
    char name[30];
    char phone[11];
    int age;

    printf("Informe o nome do contato:");
    scanf("%s", name);

    printf("Informe o telefone do contato:");
    scanf("%s", phone);

    printf("Informe a idade do contato:");
    scanf("%d", &age);

    strcpy(person->name, name);
    strcpy(person->phone, phone);
    person->age = age;
    person->previous = NULL;
    person->next = NULL;
}

void push(List* list, Person* person){
    person->next = NULL;
    if(list->first == NULL){
        person->previous = NULL;
        list->first = person;
    }else{
        person->previous = list->last;
        list->last->next = person;
    }
    list->last = person;
    list->length++;
}

void unshift(List *list, Person *person){
     person->previous = NULL;
     if(list->first == NULL){
        person->next = NULL;
        list->last = person;
     }else{
        person->next = list->first;
        list->first->previous = person;
     }
     list->first = person;
     list->length++;
}

void showListAsc(List *list){
    if(list->length == 0){
        printf("Lista Vazia!\n");
        return;
    }

    Person* person = list->first;
    while(person != NULL ){
        showPerson(person);
        person = person->next;
    }
   // printf("\n Fim da Lista!\n");
}

void showListDesc(List *list){
    Person* person = list->last;
    while(person != NULL ){
        showPerson(person);
        person = person->previous;
    }
   // printf("\n Fim da Lista!\n");
}

void showPerson(Person *person){
    if(person != NULL){

        printf("Print de pessoa: \n\tNome: %s \n\tTelefone: %s \n\tIdade: %d\n",
        person->name,
        person->phone,
        person->age);
    }else{
        printf("Pessoa nao existe!\n");
    }
}

int size(List* list){
    return list->length;
}

//liberar toda lista da memoria
void dropList(List* list){        

    if(list->length == 0){
        printf("Lista Vazia!\n");
        pause();
        return;
    }

    while(list->length > 0) pop(list);                        
    
    list->length = 0;
    list->first = NULL;
    list->last = NULL;
    
}

//libera um Person - delete
void deletePerson(Person *person){
    free(person);
}


void insertPosition(List* list, Person* person, int position){
     if (position > list->length){
        printf("Posicao invalida\n");
        return;
    }

    if(list->length == position){
        push(list, person);
        return;
    }

    if(position == 0){
        unshift(list, person);
        return;
    }

    Person* tmp = list->first;

    int i;
    for (i = 0; i < position; i++){
        tmp = tmp->next;
    }

    person->next = tmp;
    person->previous = tmp->previous;
    tmp->previous->next = person;
    tmp->previous = person; 
    list->length++;
    
    printf("\nInserido com sucesso na posicao %d da lista!\n", position);
    pause();
}

Person* pop(List *list){
    Person *tmp = NULL;

    if(list->length == 0){
      printf("Lista Vazia!\n");
      return tmp;
    }

    if(list->length == 1){
        deletePerson(list->first);
        list->first = NULL;
        list->last = NULL;
        list->length = 0;
    }

    if(list->length > 1){
       
       Person* tmp = list->last;
       tmp->previous->next = NULL;       
       list->last = tmp->previous;
       deletePerson(tmp);
       list->length--;   
    }

    return tmp;
}

Person* shift(List *list){
    Person* tmp = NULL;

    if(list->length == 0){
        printf("Lista Vazia!\n");
        return tmp;
    }
 
    if(list->length == 1){
        deletePerson(list->first);
        list->first = NULL;
        list->last = NULL;    
    }else{
        tmp = list->first;
        list->first = list->first->next;
        list->first->previous = NULL;
        free(tmp);
    }
    
    list->length--;

    printf("\nRemovido com sucesso no inicio da lista!\n");
    pause();

    return list->first;
}

Person* removePosition(List *list, int position){
    Person *tmp = NULL;

    if(position == 0){
        shift(list);
    }else if(position == list->length -1){
        pop(list);
    }

    if (position >= list->length){
        printf("\nPosicao invalida\n");
        return tmp;
    }

    if(list->length == 0){
      printf("\nLista Vazia!\n");
      return tmp;
    }

    tmp = getPerson(list, position);

    Person *deleting = tmp->next;

    tmp->next = deleting->next;
    tmp->previous = deleting->previous;
    
    deleting->next = NULL;
    deleting->previous = NULL;

    deletePerson(deleting);
    list->length--;

    printf("\nRemovido com sucesso da posicao %d da lista!\n", position);
    pause();

    return tmp;
}

 Person* getPerson(List* list, int position){
    Person *tmp = list->first;

    int i;
    for (i = 0; i < position-1; i++){
        tmp = tmp->next;
    }

    return tmp;
 }

void bubbleSort(List* list, int length){   
    if (length < 1) return;

    Person* person = list->first;
     
    while (person->next != NULL) {
        if(person->age > person->next->age){
            swap(person, person->next);
        } 
        person = person->next;
    }   
    bubbleSort(list, length-1);
} 

void swap(Person* person1, Person* person2){
    Person* tmp = (Person*) malloc(sizeof(Person));
    strcpy(tmp->name, person1->name); 
    strcpy(tmp->phone, person1->phone); 
    tmp->age = person1->age;

    strcpy(person1->name, person2->name); 
    strcpy(person1->phone, person2->phone); 
    person1->age = person2->age;

    strcpy(person2->name, tmp->name); 
    strcpy(person2->phone, tmp->phone); 
    person2->age = tmp->age;      

    deletePerson(tmp);
}

void shellSort(List* list) {
    int i, j;
    Person* person = (Person*) malloc(sizeof(Person));         

    int h = 1;

    while(h < list->length) h = 3*h+1;

    while (h > 0) {
        for(i = h; i <= list->length; i++) {            
            strcpy(person->name, getPerson(list, i)->name);
            strcpy(person->phone, getPerson(list, i)->phone);                
            person->age = getPerson(list, i)->age; 
            j = i;
            while (j > h-1 && person->age <= getPerson(list, j-h)->age) {                                
                strcpy(getPerson(list, j)->name, getPerson(list, j-h)->name);
                strcpy(getPerson(list, j)->phone, getPerson(list, j-h)->phone);                
                getPerson(list, j)->age = getPerson(list, j-h)->age;                
                j = j - h;
            }
            strcpy(getPerson(list, j)->name, person->name);
            strcpy(getPerson(list, j)->phone, person->phone);
            getPerson(list, j)->age = person->age;
        }
        h = h/3;
    }
    deletePerson(person);
} 

void pause(){
    printf("\nAperte qualquer tecla para prosseguir...\n");
    getchar();
    scanf("c\n");
    fflush(stdin);
	printf("\33[H\33[2J");
}

void fillContactList(List* contactsList){
    
    Person* marcia = createPerson("Marcia Luz","234567454",54);
    push(contactsList,marcia);
    Person* ana = createPerson("Ana Ribeiro","234567454",34);
    push(contactsList,ana);
    Person* maria = createPerson("Maria souza","234567454",74);
    push(contactsList,maria);
    Person* carla = createPerson("Carla Antunes","234567454",32);
    push(contactsList,carla);
    Person* marina = createPerson("Marina Coutinho","234567454",29);
    push(contactsList,marina);
    Person* jefferson = createPerson("Jefferson Albuquerque","234567454",31);
    push(contactsList,jefferson);
    Person* bruno = createPerson("Bruno Miranda","234567454",24);
    push(contactsList,bruno);
    Person* leandro = createPerson("Leandro amaral","234567454",38);
    push(contactsList,leandro);
    Person* andre = createPerson("Andre amaral","234567454",39);
    push(contactsList,andre);
    Person* claudia = createPerson("Claudia da silva","345674543",38);
    push(contactsList,claudia);
    Person* paula = createPerson("Paula Ribeiro","456745434",28);
    push(contactsList,paula);
    Person* clovis = createPerson("Clovis da silva","456745434",51);    
    push(contactsList,clovis);
    Person* murilo = createPerson("Murillo braga","456745434",38);
    push(contactsList,murilo);
    Person* leonardo = createPerson("Leonardo Cardoso","456745434",82);
    push(contactsList,leonardo);
    Person* daniel = createPerson("Daniel Santos","456745434",25);
    push(contactsList,daniel);
    Person* matheus = createPerson("Matheus Mendes","456745434",12);
    push(contactsList,matheus);
    Person* joares = createPerson("Joares Fernandez","456745434",58);
    push(contactsList,joares);
    Person* rafael = createPerson("Rafael Goulart","456745434",15);
    push(contactsList,rafael);
    Person* luan = createPerson("Luan Firmino","456745434",8);
    push(contactsList,luan);
    Person* renato = createPerson("Renato lemos","456745434",14);
    push(contactsList,renato);
    Person* enzo = createPerson("Enzo Miguel","456745434",8);
    push(contactsList,enzo);
    Person* valentina = createPerson("Valentina Ribeiro","456745434",8);
    push(contactsList,valentina);

    printf("Lista de contatos preenchida com sucesso!\n\n");
    pause();
}