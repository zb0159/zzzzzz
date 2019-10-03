#include "data.h"
int send_data(int socket,char * buffer,int len)
{
    if(io_flag == W_S_ENC)
    {
        int i;
        for(i = 0; i < len ; i++)
        {
            buffer[i] ^= 1;

        }
    }
    int n = send(socket,buffer,len,0);
 //   if(errno!=0)
   // {p_log("errno=%d fuc=%s\n",errno,__func__);return errno;}
    return n;
}

int receive_data(int socket, char * buffer, int len,int flags)
{
    int n = 0; 
    n = recv(socket,buffer,len,flags);
    if(n<=0) return n;
    if(io_flag == R_C_DEC && n > 0)
    {
        int i;
        for(i = 0; i< n; i++ )
        {
            buffer[i] ^= 1;
        }      
    }
    if(errno!=0)
   {p_log("errno=%d fuc=%s\n",errno,__func__);return errno;}
    
    return n;
}

int forward_data(int source_sock, int destination_sock) {
    char buffer[BUF_SIZE];
    int n;

    while (1)
    {
        if((n = receive_data(source_sock, buffer, BUF_SIZE,0)) > 0){
            if (errno != 0)
            {   //p_log("errno=%d\n",errno);
                break;
            }
            send_data(destination_sock, buffer, n);

        }else{
            break;
        }
    }

    shutdown(destination_sock, SHUT_RDWR);

    shutdown(source_sock, SHUT_RDWR);
    return n;
}

