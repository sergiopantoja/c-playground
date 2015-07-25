#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXPENDING 64
#define BUFFER_SIZE 256

void error(char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
  int sockfd, connectionfd, port, n;
  unsigned int cli_len;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[BUFFER_SIZE];

  if (argc != 2) {
    printf("USAGE: %s [port]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // create socket
  if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    error("socket() failed");

  // setup address and port info
  port = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(port);

  // bind socket to address/port
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    error("bind() failed");

  // start listening for incoming connections
  if (listen(sockfd, MAXPENDING) < 0)
    error("listen() failed");

  printf("Listening on %d...\n", port);

  // accept our first connection!
  cli_len = sizeof(cli_addr);
  if ((connectionfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_len)) < 0)
    error("accept() failed");

  // clear the buffer
  memset(&buffer, 0, BUFFER_SIZE);

  // read from the client
  if ((n = read(connectionfd, &buffer, BUFFER_SIZE)) < 0)
    error("read() failed");

  printf("WE GOT A MESSAGE!!! Here it is: %s\n", buffer);

  // respond to client
  char response[] = "I got your response!";
  if ((n = write(connectionfd, response, strlen(response))) < 0)
    error("write() failed");

  // close connection and socket
  close(connectionfd);
  close(sockfd);

  return 0;
}
