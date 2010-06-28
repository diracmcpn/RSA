#include "generator.h"
#define LONGUEUR_NB_PREMIER 200
#define LONGUEUR_NB_C 30

RSA::RSA(){}

RSA::RSA(const RSA& object){}

RSA::~RSA(){}

void RSA::randomPrime(mpz_t prime, int length, gmp_randstate_t state)
{
    //déclaration et initialisation de rand
    mpz_t rand;
    mpz_init(rand);

    //déclaration et initialisation de la borne supérieure
    mpz_t max;
    mpz_init(max);
    mpz_ui_pow_ui(max,10,length+1);

    //déclaration et initialisation de la borne inférieure
    mpz_t min;
    mpz_init(min);
    mpz_ui_pow_ui(min,10,length);

    //génére aléatoirement un nombre compris entre min et max
    do
    {
        mpz_urandomm(rand,state,max); //génére un nombre aléatoire compris entre 0 et max initialisé par state
    }
    while (mpz_cmp(rand,min) > 0); //vérifie si rand > min en renvoyant une valeur positive

    mpz_nextprime(prime,rand); //cherche le premier nombre premier juste aprés rand*/

}

void RSA::getKeys(mpz_t N, mpz_t C, mpz_t U, gmp_randstate_t state)
{
    //déclaration et initialisation de P et Q
    mpz_t P;
    mpz_init(P);
    mpz_t Q;
    mpz_init(Q);

    //Definit Q et P comme des nombres premiers
    randomPrime(P,LONGUEUR_NB_PREMIER,state);
    randomPrime(Q,LONGUEUR_NB_PREMIER,state);

    //Definit N comme le produit de P et Q
    mpz_mul(N,P,Q);

    //déclaration et initialisation de M l'indice d'Euler
    mpz_t M;
    mpz_init(M);
    mpz_t p;
    mpz_init(p);
    mpz_t q;
    mpz_init(q);

    //définit M comme le produit de P-1 et Q-1
    mpz_sub_ui(p,P,1);
    mpz_sub_ui(q,Q,1);
    mpz_mul(M,p,q);

    // libération de l'espace mémoire de q et p
    mpz_clear(p);
    mpz_clear(q);

    //Génére un nombre premier de N chiffres
    randomPrime(C,LONGUEUR_NB_C,state);

    //Définit U par rapport à C et M : C mod(M)
     mpz_invert(U,C,M);
}

void RSA::randInit(mpz_t seed, const std::string& text)
{
    int len,letter,i;
    mpz_t a;
    mpz_init(a);
    mpz_t b;
    mpz_init(b);

    for(i = 0; text[i]; i++)
    {
        letter = text[i];
        len = text.size() - i;
        mpz_ui_pow_ui(a,256,len);
        mpz_mul_ui(b,a,letter);
        mpz_add(seed,seed,b);
     }
}
