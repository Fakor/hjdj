#ifndef HJDJ_SENDER_H
#define HJDJ_SENDER_H

#include <cstdint>
#include <cstddef>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "easylogging/easylogging++.h"

namespace hjdj{

class Sender
{
    public:
        Sender(uint16_t port, size_t max_buffer_size, char const *ip_address);
        virtual ~Sender();

    private:
        uint16_t port_;
        size_t max_buffer_size_;
        int sock_{0};
        struct sockaddr_in serv_addr_;
};

}

#endif // HJDJ_SENDER_H
