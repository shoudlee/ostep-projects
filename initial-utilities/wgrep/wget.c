#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

// BM Algorithm(Bad character)
// return: positive value-matched -1-no match
int BM_Match(char* term, char* source, int* jmp_list){
    int term_count = strlen(term);
    int source_count = strlen(source);

    int index_match = -1;
    int index_source = 0;
    int index_term = term_count-1;

    while (index_source + term_count <= source_count)
    {
        if (source[index_source + index_term] == term[index_term])
        {
            index_term--;
            if (index_term < 0)
            {
                // Term Matched!
                index_match = index_source;
                break;
            }
            
        }
        else{
            index_source += jmp_list[index_term];
            index_term = term_count-1;
        }
    }

    return index_match;

}
void Jmp_List(char* term, int* list){
    int length = strlen(term);
    for (size_t i = 0; i < length; i++) list[i] = length;
    for (size_t i = length-1; i > 0 ; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            if(term[i] != term[j]) continue;
            list[i] = i - j;
        }  
    }
    
}



int main(int argc, char *argv[]) {
    if (argc < 3){
        printf("Missing arguments.");
    }
    char* term = argv[1];
    int jmp_list[strlen(term)];

    size_t _size= 0;
    FILE* _file;
    char* _line= NULL;
    ssize_t nread = 0;

    Jmp_List(term, jmp_list);
    for(int i =2; i< argc; i++) 
    {
        
        _file = fopen(argv[i], "r");
        if (!_file)
        {
            perror("Open file failed");
            continue;
        }
        while (getline(&_line, &_size, _file) != -1)
        {
            if (BM_Match(term, _line, jmp_list))
            {
                printf("%s", _line);
            }
        }

        fclose(_file);
        free(_line);
    }

    return 0;
}