#include <stdio.h>
#include <dirent.h>

int listfiles(char *path) {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);
    if (dir == NULL){
        perror("não foi possivel abrir o arquivo");
        return 1;
    } // um tratamento de error não mata okay !
    while ((entry = readdir(dir)) != NULL){
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 1;
}
int main(int argc, char* argv[]) {
    if (argc < 1){
        printf("error: argumentos insuficientes");
        return 1;
    }
    listfiles(argv[1]);
    return 0;
}
