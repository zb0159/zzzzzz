#ifndef _DATA_H
#define _DATA_H
#include "common.h"
#include "log.h"

typedef enum {

    FLG_NONE = 0,       /* 正常数据流不进行编解码 */
    R_C_DEC = 1,        /* 读取客户端数据仅进行解码 */
    W_S_ENC = 2         /* 发送到服务端进行编码 */
}flag_s;

flag_s io_flag;
int send_data(int socket,char * buffer,int len );
int receive_data(int socket, char * buffer, int len,int flags);

int forward_data(int source_sock, int destination_sock);
#endif
