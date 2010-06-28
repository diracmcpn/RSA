#include "message.h"

Message::Message(const std::string& text)
{
    this->originalText = text;
}

Message::Message(const Message& object){}

Message::~Message(){}

std::string Message::encryptRSA(mpz_t C, mpz_t N)
{
    mpz_t chiffre;
    mpz_init(chiffre);
    mpz_t code;
    mpz_init(code);

    std::string text;

    for(int i = 0; this->originalText[i];i++)
    {
        unsigned long int lettre = this->originalText[i];
        mpz_set_ui(chiffre,lettre);
        mpz_powm(code,chiffre,C,N);
        std::string car = toStr(code);
        text+= car+" ";
    }
    this->cryptedText = text;

    return this->cryptedText;
}

std::string Message::decryptRSA(mpz_t U, mpz_t N)
{
    char * cstr, *p;
    mpz_t chiffre;
    mpz_init(chiffre);

    std::ostringstream t;

    cstr = new char [this->cryptedText.size()+1];
    strcpy (cstr, this->cryptedText.c_str());

    p = strtok (cstr," ");
    while (p!=NULL)
    {
        mpz_set_str(chiffre,p,10);
        mpz_powm(chiffre,chiffre,U,N);
        int lettre = mpz_get_ui(chiffre);
        t << char(lettre);

        p = strtok(NULL," ");
    }

    delete[] cstr;

    return t.str();
}

std::string Message::getMessage()
{
    return this->originalText;
}

std::string Message::toStr(mpz_t entier)
{
    std::ostringstream t;
    t << entier;
    return t.str();
}
