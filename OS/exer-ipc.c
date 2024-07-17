#include<stdio.h>
int main(int argc, char* argv[])
{
	char* src, *dest;
	int fd;
	if(argc !=3){
		printf("usage: copy <src> <dest>\n")
		return 0;
	}
	src = argv[1];
	dest = argv[2];
	fd = open(dest, O_CREATE | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if(fd == -1){perror("error open"); exit(0);}
	if dup2(fd,1) == -1){perror("error dup2"); exit(0);}
	if(execlp("cat", "cat", src, NULL) == -1){perror("errpr execl"); exit(0);}
}
