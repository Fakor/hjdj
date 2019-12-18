#ifndef HJDJ_RECEIVER_H
#define HJDJ_RECEIVER_H

#include <cstdint>
#include <cstddef>

#include <stdexcept>

#include <sys/socket.h>
#include <netinet/in.h>

namespace hjdj {

class Receiver
{
    public:
        Receiver(uint16_t port, size_t max_buffer_size);
        virtual ~Receiver();

    protected:

    private:
        uint16_t port_;
        size_t max_buffer_size_;
        int opt_{1};

        int server_fd_;
        int new_socket_;
        int addrlen_;
        struct sockaddr_in address_;
};

}

#endif // HJDJ_RECEIVER_H
