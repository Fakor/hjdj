#ifndef HJDJ_RECEIVER_H
#define HJDJ_RECEIVER_H

#include <cstdint>
#include <cstddef>

#include <stdexcept>

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "easylogging/easylogging++.h"

namespace hjdj {

template <class T>
class Receiver
{
    public:
        Receiver(uint16_t port, size_t max_buffer_size);
        virtual ~Receiver();

        const T& ReadNext();

    private:
        uint16_t port_;
        size_t max_buffer_size_;
        int opt_{1};

        int server_fd_;
        int new_socket_;
        int addrlen_;
        struct sockaddr_in address_;
        T current_value_;
};

template <class T>
Receiver<T>::Receiver(uint16_t port, size_t max_buffer_size)
: port_{port}, max_buffer_size_{max_buffer_size}
{
    LOG(INFO) << "Setting up receiver for port " << port;
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
    LOG(INFO) << "Connection with sender established!";
}

template <class T>
Receiver<T>::~Receiver()
{
    //dtor
}

template <class T>
const T& Receiver<T>::ReadNext(){
    int valread = read(new_socket_, &current_value_, sizeof(T));
    return current_value_;
}

}

#endif // HJDJ_RECEIVER_H
