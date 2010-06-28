#include <iostream>
#include <sstream>
#include <string>
#include <gmpxx.h>
#include "generator.h"
#include "message.h"

int main()
{
    mpz_t pN;
    mpz_init(pN);
    mpz_t puC;
    mpz_init(puC);
    mpz_t prU;
    mpz_init(prU);

    gmp_randstate_t state;
    gmp_randinit_default(state);

    mpz_t seed;
    mpz_init(seed);

    RSA KeyGenerator;

    KeyGenerator.randInit(seed,"ahahah");
    gmp_randseed(state,seed);

    std::cout << "état : " <<state <<std::endl;

    KeyGenerator.getKeys(pN, puC, prU, state);

    std::cout << "public keys : " <<pN <<std::endl<<puC<<std::endl;
    std::cout << "private keys : " <<pN <<std::endl<<prU<<std::endl;

    gmp_randclear(state);

    Message Chaine("s");
    mpz_t code;
    mpz_init(code);
    std::string text1 = Chaine.encryptRSA(puC,pN);

    //std::cout << "voici le texte crypté:"<<std::endl<<text1<<std::endl;

    std::string text2 = Chaine.decryptRSA(prU, pN);
    //std::cout << "voici le texte décrypté:"<<std::endl<<text2<<std::endl;

    return 0;
}
