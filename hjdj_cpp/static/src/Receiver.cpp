#include "Receiver.h"

namespace hjdj {

Receiver::Receiver(uint16_t port, size_t max_buffer_size)
: port_{port}, max_buffer_size_{max_buffer_size}
{
    addrlen_ = sizeof(address_);
    if((server_fd_ = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        throw std::runtime_error("socket fail");
    }

    if (setsockopt(server_fd_, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                    &opt_, sizeof(opt_)))
    {
        throw std::runtime_error("setsockopt failed");
    }

    address_.sin_family = AF_INET;
    address_.sin_addr.s_addr = INADDR_ANY;
    address_.sin_port = htons( port_ );

    if (bind(server_fd_, (struct sockaddr *)&address_,
                                 sizeof(address_))<0)
    {
        throw std::runtime_error("bind failed");
    }

    if (listen(server_fd_, 3) < 0)
    {
        throw std::runtime_error("listen failed");
    }

    if ((new_socket_ = accept(server_fd_, (struct sockaddr *)&address_,
                            (socklen_t*)&addrlen_))<0)
    {
        throw std::runtime_error("accept failed");
    }
}

Receiver::~Receiver()
{
    //dtor
}

}
