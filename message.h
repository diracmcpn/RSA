#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
#include <gmpxx.h>
#include <string>
#include <sstream>
#include <iostream>

class Message
{
    public:
        Message(const std::string& text);
        Message(const Message& object);
        ~Message();

        std::string encryptRSA(mpz_t C, mpz_t N);
        std::string decryptRSA(mpz_t U, mpz_t N);
        std::string getMessage();

    private:
        std::string toStr(mpz_t entier);

        //Attribute
        std::string originalText;
        std::string cryptedText;
};

#endif // MESSAGE_H_INCLUDED
