#include <iostream>
#include <string>
#include <csignal>
#include <unistd.h>

void signalHandler(int signum){
  std::cout<<" Interrupt signal ("<<signum<<") received.\n";
  // cleanup and close up; terminate program
  exit(signum);
}
int main(){
  std::signal(SIGINT, signalHandler);
  while(1){
    std::cout<<" Going to sleep...\n";
    sleep(1);
  }
  return 0;
}
