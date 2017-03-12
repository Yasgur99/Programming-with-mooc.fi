#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"
#include "queuepriv.h"

Queue *Queue_init(void) {
    Queue *q = calloc(1, sizeof (Queue));
    return q;
}

void freeStudent(struct student* toBeFreed) {
    free(toBeFreed->name);
    free(toBeFreed);
}

struct student* createStudent(const char *id, const char *name) {
    /*return if name is too long*/
    if (strlen(id) > 6)
        return NULL;

    /*allocate room for new student struct*/
    struct student* newStudent = malloc(sizeof (struct student));
    if (!newStudent) return NULL;

    /*copy over student id*/
    strncpy(newStudent->id, id, 6);
    newStudent->id[6] = '\0';

    /*allocate room for new student's name*/
    char* studentName = malloc((strlen(name) + 1) * sizeof (char));
    if (!studentName) {
        free(newStudent);
        return NULL;
    }
    
    strncpy(studentName, name, strlen(name));
    studentName[strlen(name)] = '\0';
    newStudent->name = studentName;

    newStudent->next = NULL;

    return newStudent;
}

int Queue_enqueue(Queue *q, const char *id, const char *name) {

    /*allocate for newStudent*/
    struct student* newStudent = createStudent(id, name);
    if (newStudent == NULL) return 0;

    /*place new student in queue*/
    if (q->first == NULL)
        q->first = newStudent;
    else
        q->last->next = newStudent;

    q->last = newStudent;

    return 1;
}

char *Queue_firstID(Queue *q) {
    if (q && q->first)
        return q->first->id;
    else
        return NULL;
}

char *Queue_firstName(Queue *q) {
    if (q && q->first)
        return q->first->name;
    else
        return NULL;
}

int Queue_dequeue(Queue *q) {
    if (q->first) {
        if (q->first != q->last) {
            struct student* temp = q->first;
            q->first = q->first->next;
            freeStudent(temp);
            return 1;
        } else {
            freeStudent(q->first);
            q->first = NULL;
            q->last = NULL;
            return 1;
        }
    } else
        return 0;

}

int Queue_drop(Queue *q, const char *id) {
    struct student* current = q->first;
    struct student* last = NULL;

    /*step through list*/
    while (current) {
        /*if there is an entry with given id, free it and drop it)*/
        if (!strcmp(current->id, id)) {
            if(current == q->first)
                Queue_dequeue(q);
            else{
                if(current == q->last){
                    q->last = last;
                    last->next = NULL;
                }else{
                    last->next = current->next;
                }
                freeStudent(current);
            }
            return 1;
        } else {
            /*since the id didnt match the current, look at next element in list*/
            last = current;
            current = current->next;
        }
    }
    return 0;
    
}

void Queue_delete(Queue * q) {
    if (q) {
        while (Queue_dequeue(q));
        free(q);
    }
}
