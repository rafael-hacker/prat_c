#include <stdio.h>
#include <dirent.h>


void listfiles(char* path) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path); 
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\t", dir->d_name); 
        }
        closedir(d);
    }
}

int main(int argc, char* argv[]) {
    listfiles(argv[1]);
}
