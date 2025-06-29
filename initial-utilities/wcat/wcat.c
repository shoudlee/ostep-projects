// Forget to free!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
// I don't modify this anymore, in order to r-e-m-i-n-d myself, don't
//  forget to FREE!

#include <stdio.h>

#define BUFFERSIZE 1024*4

int main(int argc, char *argv[]) {
    // for (int i = 0; i < argc; i++) {
    //     printf("参数 %d: %s\n", i, argv[i]);
    // }
    
    FILE* _file;
    char _buffer[BUFFERSIZE];
    for (int i = 0; i < argc; i++) {
        _file = fopen(argv[i], "r");
        if (!_file){
            perror("Open file failed");
            continue;
        }
        while(fgets(_buffer, BUFFERSIZE, _file)){
            printf("%s", _buffer);
        }
    }
    return 0;
}