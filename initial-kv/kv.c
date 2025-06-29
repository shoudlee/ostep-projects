#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DBFILE ".mydb"

int main(int argc, char *argv[]) {
    // arg0: command
    char* command = argv[1];
    FILE* dbfile = NULL;
    char* delimter = ",";
    

    switch (*command)
    {
    case 'p':
        if (argc < 3) dprintf(2, "'Put' needs more arguments.");
        // **** extract key-value pairs
        int key = atoi(strsep(&argv[2], delimter));
        char* value = strsep(&argv[2], delimter);
        // ****
        dbfile = fopen(DBFILE, "a");
        
        int needed = snprintf(NULL, 0, "\n%d,%s", key, value);
        char *buf = malloc(needed + 1);
        if (!buf) { perror("malloc"); exit(1); }
        sprintf(buf, "\n%d,%s", key, value);
        fwrite(buf, needed+1, 1, dbfile);
        free(buf);
        break;
    case 'g':

        break;
    default:
        break;
    }


    if(!dbfile) fclose(dbfile);
    return 0;
}