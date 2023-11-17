#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>

// Function to display the shell prompt
void display_prompt();

// Function to read user input
char *read_input();

// Function to parse the user input
char **parse_input(char *input);

// Function to execute a command
int execute_command(char **args);

#endif
