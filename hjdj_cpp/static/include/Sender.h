#ifndef HJDJ_SENDER_H
#define HJDJ_SENDER_H

#include <cstdint>
#include <cstddef>


class Sender
{
    public:
        Sender(uint16_t port, size_t max_buffer_size, char const *ip_address);
        virtual ~Sender();

    protected:

    private:
};

#endif // HJDJ_SENDER_H
