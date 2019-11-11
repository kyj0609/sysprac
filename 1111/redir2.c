# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define CLOSE_DUP
//#define USE_DUP2
void main(void){
    int fd;
    char line[100];

    fgets(line, 100, stdin);
    printf("%s", line);
    
    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(line, 100, stdin);
    printf("%s", line);

    
    fd = open("/etc/passwd", O_RDONLY);
    if(fd != 0){
        fprintf(stderr, "could not open data as fd()\n");
        exit(1);
    }
#ifdef CLOSE_DUP
    close(0);
    newfd = dup(fd);
#else
    newfd = dup2(fd,0);
#endif
    if(newfd != 0){
        fprintf(stderr, "could not dup fd to 0\n");
        exit(1);
    }
    close(fd);
    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(link, 100, stdin);
    printf("%s", line);
}
