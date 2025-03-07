#include <stdio.h>

struct Student
{
    int StudentId;
    int Age;
    struct  Student* NextStudent;
};

void printList(struct Student head);

int main(void){

    struct Student student1, student2, student3;

    student1.StudentId = 1;
    student1.Age = 10;  
    student1.NextStudent = &student2;


    student2.StudentId = 2;
    student2.Age = 20;
    student2.NextStudent = &student3;

    
    student3.StudentId = 3;
    student3.Age = 40;
    student3.NextStudent = NULL;

    printList(student1);

    return 0;
}

void printList(struct Student head) {
    struct Student current = head;
    while (current.NextStudent != NULL) {
        printf("StudentId: %d ", current.StudentId);
        printf("Age: %d\n", current.Age);
        printf("-----------------------------------------\n");
        current = *(current.NextStudent);
    }

    printf("StudentId: %d ", current.StudentId);
    printf("Age: %d\n", current.Age);
}
