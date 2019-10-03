#include <arpa/inet.h>
#include <errno.h>
#include <libgen.h>
#include <netdb.h>
#include <resolv.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>

#define BUF_SIZE 8192
#define MAX_EVENTS 100
#define READ  0
#define WRITE 1

#define DEFAULT_LOCAL_PORT    8080
#define DEFAULT_REMOTE_PORT   8081
#define SERVER_SOCKET_ERROR -1
#define SERVER_SETSOCKOPT_ERROR -2
#define SERVER_BIND_ERROR -3
#define SERVER_LISTEN_ERROR -4
#define CLIENT_SOCKET_ERROR -5
#define CLIENT_RESOLVE_ERROR -6
#define CLIENT_CONNECT_ERROR -7
#define CREATE_PIPE_ERROR -8
#define BROKEN_PIPE_ERROR -9
#define HEADER_BUFFER_FULL -10
#define BAD_HTTP_PROTOCOL -11

#define MAX_HEADER_SIZE 8192

#define COMMLIB_DBG_FILE  "./log.log"


