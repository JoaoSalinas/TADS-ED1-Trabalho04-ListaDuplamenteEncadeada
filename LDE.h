#ifndef LDE_H_INCLUDED
#define LDE_H_INCLUDED

typedef struct Person{
    struct Person *previous;
    struct Person *next;
    char name [100];
    char phone [20];
    int age;
}Person;

typedef struct List{
    Person *first;
    Person *last;
    int length;
}List;

List* createList();

Person* createPerson(char name [], char phone [], int age);
Person* createVoidPerson();

void push(List* list, Person* person);
void unshift(List* list, Person* person);
void insertPosition(List* list, Person* person, int position);
void insertInOrder(List* list, Person* person);

Person* pop(List* list);
Person* shift(List* list);
Person* removePosition(List* list, int position);

void showListAsc(List* list);
void showListDesc(List* list);
void showPerson(Person* person);

int size(List* list);

void sortList(List* list);

void dropList(List* list);

void deletePerson(Person* person);

void fillContactList(List* list);

void pause();

void bubbleSort(List* list, int length);

void swap(Person* person1, Person* person2);

void shellSort(List* contactsList);

Person* getPerson(List* list, int position);

#endif // LDE_H_INCLUDED