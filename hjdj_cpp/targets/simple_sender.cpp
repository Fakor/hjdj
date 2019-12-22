#include "Sender.h"
#include "easylogging/easylogging++.h"


INITIALIZE_EASYLOGGINGPP

int main(int argc, char const *argv[]){
  if(argc != 3){
    printf("2 arguments needed!\n");
    return -1;
  }
  unsigned int port = atoi(argv[1]);
  char const *ip_address = argv[2];
  hjdj::Sender<int> sender(port, 1024, ip_address);
}
