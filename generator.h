#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED
#include <gmpxx.h>
#include <string>

class RSA
{
    public:
        RSA();
        RSA(const RSA& object);
        ~RSA();

        void getKeys(mpz_t N, mpz_t C, mpz_t U, gmp_randstate_t state);
        void randInit(mpz_t seed, const std::string& text);

    private:
        void randomPrime(mpz_t prime, int length, gmp_randstate_t state);
};

#endif // GEN_H_INCLUDED

