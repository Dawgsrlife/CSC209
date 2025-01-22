#include <stdio.h>   // Header file for input/output functions such as printf and file operations.
#include <string.h>  // Header file for string manipulation functions like strlen.

#define MAXLINE 256  // Define a constant for the maximum length of a line.

int main() {
    /* Opening a file with `fopen()` in "r" mode (read mode).
     * The file must exist, or fopen() will return NULL.
     * The file pointer `data_fptr` is used to access the file.
     */
    FILE *data_fptr = fopen("data1.txt", "r");

    /* Checking if the file was opened successfully.
     * If fopen() returns NULL, it means the file couldn't be opened (e.g., it doesn't exist).
     */
    if (data_fptr == NULL) {
        printf("Error: Could not open file 'data1.txt'.\n");
        return 1;  // Return with an error code.
    }

    // Array to store a single line of text from the file, up to MAXLINE characters.
    char line[MAXLINE];

    // Pointer to store the result of `fgets`, which will be the address of `line` or NULL on error/end of file.
    char *ptr;

    // Read the first line from the file into `line`.
    ptr = fgets(line, MAXLINE, data_fptr);

    // Print the first line. If fgets fails, `line` may be uninitialized.
    printf("First line of file is:\n%s\n", line);

    /* The variable `ptr` is the same as `line` here.
     * This is because `fgets` returns the pointer to the buffer where the data is stored.
     * Print the first line again using `ptr`.
     */
    printf("First line of file is also:\n%s\n", ptr);

    /* Explanation of fgets:
     * - Reads at most MAXLINE - 1 characters from the file and stores them in `line`.
     * - Stops reading when it encounters a newline (`\n`) or end of file (EOF).
     * - Appends a null character (`\0`) to mark the end of the string.
     */

    // Variables to keep track of the number of lines and total characters.
    int num_lines = 0;    // Counter for the number of lines read.
    int sum_chars = 0;    // Counter for the total number of characters read.

    /* Loop to read each line of the file.
     * `fgets` returns NULL when it reaches EOF or encounters an error.
     */
    while (fgets(line, MAXLINE, data_fptr)) {
        num_lines++;                  // Increment the line counter.
        sum_chars += strlen(line);    // Add the length of the current line to the character counter.
    }

    // Print the total number of lines and characters read from the file.
    printf("Number of lines: %d, Number of characters: %d\n", num_lines, sum_chars);

    /* Note:
     * The output of this program may not match the result of `wc` (word count tool) because:
     * - This program counts characters including newline characters.
     * - `fgets` may ignore lines longer than MAXLINE, leading to potential discrepancies.
     */

    // Close the file to free resources.
    fclose(data_fptr);

    // Exit the program successfully.
    return 0;
}
