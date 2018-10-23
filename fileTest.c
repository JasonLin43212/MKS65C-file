#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int file_dest = open("test.txt", O_RDWR | O_APPEND);
  printf("Opening the file <test.txt>\n");
  if (file_dest < 0) {
    printf("There was a problem opening the file.\n");
    return 1;
  }
  printf("File destination number : %d\n\n",file_dest);
  printf("Reading <test.txt>\n");

  char text[400] = "";
  if (read(file_dest,text,400) < 0) {
    printf("There was a problem reading the file.\n");
    return 1;
  }
  printf("Contents of File:\n==================\n%s\n\n",text);


  printf("Writing <This world is full of earthworms.> to the file\n\n");
  char * addition = "This world is full of earthworms.\n";
  if (write(file_dest,addition,34) != 34) {
    printf("There was a problem writiing to the file.\n");
    return 1;
  }



  printf("Rereading <test.txt>\n");

  if (read(file_dest,text,10) < 0) {
    printf("There was a problem reading the file.\n");
    return 1;
  }
  printf("New contents of file:\n===========\n%s\n\n",text);


  printf("Closing file\n");
  if (close(file_dest) < 0){
    printf("There was a problem closing the file.\n");
    return 1;
  }

  return 0;
}
