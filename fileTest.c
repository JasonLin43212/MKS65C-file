#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int file_dest = open("test.txt", O_WRONLY | O_APPEND);
  printf("Opening the file <test.txt>\n");
  if (file_dest < 0) {
    return 1;
  }
  printf("File destination number : %d\n",file_dest);



  printf("Closing file\n");
  if (close(file_dest) < 0){
    return 1;
  }

  return 0;
}
