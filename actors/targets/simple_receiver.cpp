#include "hjdj_includes.h"


INITIALIZE_EASYLOGGINGPP

int main(int argc, char const *argv[]){
  if(argc != 2){
    printf("1 argument needed!\n");
    return -1;
  }
  unsigned int port = atoi(argv[1]);
  hjdj::Receiver<int> receiver(port, 1024);

  int v = receiver.ReadNext();

  LOG(INFO) << "Received: " << v;
}
