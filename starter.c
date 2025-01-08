// starter.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void printGreeting();
int addNumbers(int a, int b);
void demoPointers();
void fileOperations();

int main() {
    // 1. Basic Input/Output
    printf("Welcome to the C Basics Program!\n");
    printGreeting();

    int num1, num2;
    printf("\nEnter two integers to add: ");
    scanf("%d %d", &num1, &num2);

    int result = addNumbers(num1, num2);
    printf("The sum of %d and %d is %d\n", num1, num2, result);

    // 2. Demonstrating Pointers
    demoPointers();

    // 3. File Operations
    fileOperations();

    return 0;
}

// Function to print a greeting message
void printGreeting() {
    printf("Hello! This program demonstrates basic C programming concepts.\n");
}

// Function to add two numbers
int addNumbers(int a, int b) {
    return a + b;
}

// Function to demonstrate pointers
void demoPointers() {
    int value = 42;
    int *ptr = &value;

    printf("\nPointer Demonstration:\n");
    printf("Value: %d\n", value);
    printf("Pointer Address: %p\n", (void *)ptr);
    printf("Value through Pointer: %d\n", *ptr);
}

// Function to demonstrate file operations
void fileOperations() {
    printf("\nFile Operations Demonstration:\n");

    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "Hello, this is a sample text file created in C.\n");
    fclose(file);
    printf("File 'example.txt' has been written.\n");

    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];
    printf("Reading from 'example.txt':\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}
