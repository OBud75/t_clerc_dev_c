#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person {
    int age;
} Person;

int are_persons_equals(Person *p1, Person *p2) {
    return p1->age == p2->age;
}

typedef struct Book {
    int pages;
} Book;

int are_books_equals(Book *b1, Book *b2) {
    return b1->pages == b2->pages;
}

int are_equals(
    void *obj1, void *obj2,
    int (*compare_fnc)(void *, void *)) {
    return compare_fnc(obj1, obj2);
}

int is_greater(
    void *obj1, void *obj2,
    int (*compare_fnc)(void *, void *)) {
    return compare_fnc(obj1, obj2) > 0;
}

void swap(void *obj1, void *obj2, size_t size) {
    void *temp = malloc(size);
    if (!temp) {
        perror("Failed to allocate memory for swap");
        exit(EXIT_FAILURE);
    }
    memcpy(temp, obj1, size);
    memcpy(obj1, obj2, size);
    memcpy(obj2, temp, size);
    free(temp);
}

void sort(
    void *array[],
    int nb_of_elems_in_array,
    size_t elem_size,
    int (*compare_fnc)(void *, void *)) {
    for (int i = 0; i < nb_of_elems_in_array - 1; i++) {
        for (int j = 0; j < nb_of_elems_in_array - i - 1; j++) {
            if (compare_fnc(array[j], array[j + 1]) > 0) {
                swap(array[j], array[j + 1], elem_size);
            }
        }
    }
}

int is_in_array(void *obj_to_find,
                void *array[],
                int nb_of_elems_in_array,
                size_t elem_size,
                int (*compare_fnc)(void *, void *)) {
    for (int i = 0; i < nb_of_elems_in_array; i++) {
        if (compare_fnc(obj_to_find, array[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


int compare_ints(void *a, void *b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;
    return (int_a > int_b) - (int_a < int_b);
}

// Une fonction main qui prouve que tout fonctionne aurait été bienvenue.
