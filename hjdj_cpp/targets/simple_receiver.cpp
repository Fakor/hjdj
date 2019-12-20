#include "Receiver.h"
#include "easylogging/easylogging++.h"


INITIALIZE_EASYLOGGINGPP

int main(int argc, char const *argv[]){
  if(argc != 2){
    printf("2 arguments needed!\n");
    return -1;
  }
  unsigned int port = atoi(argv[1]);
  hjdj::Receiver receiver(port, 1024);
}
