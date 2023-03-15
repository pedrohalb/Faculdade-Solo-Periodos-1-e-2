#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 13

struct node {
  int key;
  char value[100];
  struct node *next;
};

struct node *hash_table[TABLE_SIZE];

int hash_function(int key) { return key % TABLE_SIZE; }

void insert(int key, char *value) {
  int index = hash_function(key);
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  strcpy(new_node->value, value);
  new_node->key = key;
  new_node->next = hash_table[index];
  hash_table[index] = new_node;
}

char *search(int key) {
  int index = hash_function(key);
  struct node *temp = hash_table[index];
  while (temp != NULL) {
    if (temp->key == key)
      return temp->value;
    temp = temp->next;
  }
  return NULL;
}

void delete(int key) {
  int index = hash_function(key);
  struct node *temp = hash_table[index];
  struct node *prev = NULL;
  if (temp != NULL && temp->key == key) {
    hash_table[index] = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->key != key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL)
    return;
  prev->next = temp->next;
  free(temp);
}

int main() {
  insert(1, "value1");
  insert(2, "value2");
  insert(3, "value3");
  insert(4, "value4");
  insert(14, "value14");

  printf("%s\n", search(1));
  printf("%s\n", search(2));
  printf("%s\n", search(3));
  printf("%s\n", search(4));
  printf("%s\n", search(14));

  delete (1);
  delete (2);
  delete (3);
  delete (4);
  delete (14);

  printf("%s\n", search(1));
  printf("%s\n", search(2));
  printf("%s\n", search(3));
  printf("%s\n", search(4));
  printf("%s\n", search(14));

  return 0;
}
