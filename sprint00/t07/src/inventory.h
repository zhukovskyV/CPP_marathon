#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream>
#include <string>

#define INVENTORY_SIZE 12

void empty(char **inventory);
int count_args(char *command, char **comm, char **arg);
void insert(char **inventory, char* chars_array);
void remove(char **inventory, char* chars_array);
void show(char **inventory);
void exit(char **inventory, char **comm, char **arg);
void util(char *command, char **inventory, char **comm, char **arg);

#endif