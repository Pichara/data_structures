#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 5

// Structure for each key-value entry
typedef struct Entry {
    char *key;
    char *value;
    struct Entry *next;
} Entry;

// Global hash table
Entry *table[TABLE_SIZE];

// Simple hash function
unsigned int hash(const char *key) {
    unsigned int sum = 0;
    while (*key) {
        sum += (unsigned char)(*key);
        key++;
    }
    return sum % TABLE_SIZE;
}

// Insert a key-value pair
void insert(const char *key, const char *value) {
    unsigned int index = hash(key);
    Entry *newEntry = (Entry*) malloc(sizeof(Entry)); // Cast if compiling as C++
    if (!newEntry) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    newEntry->key = strdup(key);
    newEntry->value = strdup(value);
    newEntry->next = NULL;

    if (table[index] == NULL) {
        table[index] = newEntry;
    } else {
        Entry *current = table[index];
        while (current) {
            if (strcmp(current->key, key) == 0) {
                free(current->value);
                current->value = strdup(value);
                free(newEntry->key);
                free(newEntry->value);
                free(newEntry);
                return;
            }
            if (current->next == NULL) {
                current->next = newEntry;
                return;
            }
            current = current->next;
        }
    }
}

// Retrieve the value by key
char* get(const char *key) {
    unsigned int index = hash(key);
    Entry *current = table[index];
    while (current) {
        if (strcmp(current->key, key) == 0) return current->value;
        current = current->next;
    }
    return NULL;
}

// Remove an entry by key
void removeKey(const char *key) {
    unsigned int index = hash(key);
    Entry *current = table[index], *prev = NULL;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (!prev) table[index] = current->next;
            else prev->next = current->next;
            free(current->key);
            free(current->value);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    // Initialize
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;

    // Usage
    insert("name", "John");
    insert("age", "25");
    insert("profession", "Engineer");
    insert("name", "Rodrigo");

    printf("name: %s\n", get("name"));          
    printf("age: %s\n", get("age"));            
    printf("profession: %s\n", get("profession"));

    removeKey("name");
    printf("name after removal: %s\n", get("name")); 

    return 0;
}
