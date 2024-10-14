#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int checkArguments(int numOfArguments, char **cmdLineArguments);
int printFileNames(int numberOfFiles, char **fileNames);
int checkFileExists(char *fileName);
int readFile(char *fileName);
int extractSample(char *fileName);
int isVowel(char ch);

// Main function
int main(int argc, char **argv) {
    // Check if the correct number of arguments is passed
    if (checkArguments(argc, argv) == 0) {
        printf("Error: Invalid number of arguments.\n");
        return 1;
    }

    // Print the file names
    printFileNames(argc, argv);

    // Check if the first file exists
    if (checkFileExists(argv[1]) == 0) {
        printf("Error: File %s does not exist.\n", argv[1]);
        return 1;
    }

    // Read and print the contents of the second file
    readFile(argv[2]);

    // Extract and print the sample from the third file
    extractSample(argv[3]);

    return 0;
}

// Check if the correct number of arguments is provided
int checkArguments(int numOfArguments, char **cmdLineArguments) {
    printf("Arguments: %s\n", (numOfArguments == 4) ? "true" : "false");
    return (numOfArguments == 4) ? 1 : 0;
}

// Print the file names provided in the arguments
int printFileNames(int numberOfFiles, char **fileNames) {
    for (int i = 1; i < numberOfFiles; i++) {
        printf("File Name: %s\n", fileNames[i]);
    }
    return 5;
}

// Check if a file exists
int checkFileExists(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file) {
        fclose(file);
        printf("File Exists: true\n");
        return 1;
    } else {
        printf("File Exists: false\n");
        return 0;
    }
}

// Read and print the contents of a file
int readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("Name: %c\n", ch);
    }
    fclose(file);
    return 5;
}

// Extract and print lines with 6 or more characters
int extractSample(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[100];
    int sampleNumber = 1;
    while (fgets(line, sizeof(line), file)) {
        if (strlen(line) >= 6) {
            printf("Sample %d: %s", sampleNumber++, line);
        }
    }
    fclose(file);
    return 5;
}

// Helper function to check if a character is a vowel
int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
