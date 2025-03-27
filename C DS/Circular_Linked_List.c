#include <stdio.h>
#include <stdlib.h>

//Node for the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Creates a new node with the given value 
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

//Inserting at the end of the circular linked list
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    
    //If the list is empty, make the new node point to itself and set it as head
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    
    //Finds the node that is poiting to the head
    Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    
    temp->next = newNode;
    newNode->next = *head;
}

//Prints the circular linked list
void printList(Node* head) {
    if (head == NULL)
        return;
    
    Node* temp = head;

    //Using a do while loop to print the list, and when it finds the head again(the first one is the head), it stops
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    
    //Inserting elements into the circular linked list
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    
    printf("Circular List: ");
    printList(head);
    
    return 0;
}

