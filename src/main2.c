#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#include <sys/mman.h>
#include <emscripten.h>
#include <string.h>

char* file_content = NULL;

void processFileContent(const char* content) {
    // Process the file content here
    printf("File content: %s\n", content);
}

EMSCRIPTEN_KEEPALIVE
void storeString(const char* content) {
    int string_length = strlen(content);
    file_content = (char*)malloc(string_length + 1);
    if (file_content == NULL) {
        printf("Failed to allocate memory for file content\n");
        return;
    }
    strcpy(file_content, content);

    processFileContent(file_content);

    free(file_content);
    file_content = NULL;
}

// int main() {
//     // Call the storeString function with the long ASCII string as an argument
//     storeString("This is a long ASCII string");

//     return 0;
// }