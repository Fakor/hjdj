#ifndef HJDJ_SENDER_H
#define HJDJ_SENDER_H

#include <cstdint>
#include <cstddef>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "easylogging/easylogging++.h"

namespace hjdj{

template <class T>
class Sender
{
    public:
        Sender(uint16_t port, size_t max_buffer_size, char const *ip_address);
        virtual ~Sender();

        void Send(const T& value);
    private:
        uint16_t port_;
        size_t max_buffer_size_;
        int sock_{0};
        struct sockaddr_in serv_addr_;
};

template<class T>
Sender<T>::Sender(uint16_t port, size_t max_buffer_size, char const *ip_address)
: port_{port}, max_buffer_size_{max_buffer_size}
{
    LOG(INFO) << "Setting up sender for ip " << ip_address << " port " << port_;
    if ((sock_ = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        throw std::runtime_error("Socket creation error");
    }

    serv_addr_.sin_family = AF_INET;
    serv_addr_.sin_port = htons(port_);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip_address, &serv_addr_.sin_addr)<=0)
    {
        throw std::runtime_error("Invalid address");
    }

    if (connect(sock_, (struct sockaddr *)&serv_addr_, sizeof(serv_addr_)) < 0)
    {
        throw std::runtime_error("Connection failed");
    }
    LOG(INFO) << "Connection with receiver established!";
}

template<class T>
Sender<T>::~Sender()
{
    //dtor
}

template<class T>
void Sender<T>::Send(const T& value){
    send(sock_, &value, sizeof(T), 0);
}

}

#endif // HJDJ_SENDER_H
