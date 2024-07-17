#include <iostream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;
int main()
{
    int file_desc = open("test.txt", O_WRONLY | O_APPEND);  
    //file_desc is the file descriptor returned by open
    // int open(const char *pathname, int flags, mode_t mode)
    // pathname: filename

    //int flags: 
    // O_RDWR (read and write)
    // O_APPEND (write only at end of file)
    // O_CREAT (create file with access rights defined in mode) O_EXCL (return error if file exists)
    // O_TRUNC (empty the file if exists)
    // O_WRONLY Open for writing only.
    // O_APPEND If set, the file offset will be set to the end of the file prior to each write.

    //mode_t có thể tra đc
    if(file_desc < 0){
        cout << "Error opening the file";
    }
    // If the value is less than 0, it indicates an error in opening the file.

    int copy_desc = dup(file_desc);
    //dup(file_desc): Duplicates the file descriptor file_desc and assigns the new file descriptor to copy_desc

    write(copy_desc, "This will be output to the file named\n", 46);
    //Writes the specified string to the file referred to by copy_desc. The length of the string to write is 46 bytes.
    write(file_desc,"This will also be output to the file named dup.txt\n", 51); 
    //Writes another string to the file referred to by file_desc. The length of the string to write is 51 bytes.
      
    return 0; 
}