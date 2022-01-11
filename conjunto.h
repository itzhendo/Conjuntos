#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <QString>

namespace tp1
{
    class Conjunto;
}
class Conjunto
{
private:
    int tamanho;
    int indiceDeUso;
    int *array;
public:
    Conjunto(int tamanhoDoVetor);
    ~Conjunto();
    void inserirElemento(int valor);
    bool estaCheio()const;
    QString getConjunto()const;
    bool buscar(int elemento)const;
    bool estaVazio()const;
    Conjunto* uniao(Conjunto const * const objConjunto)const;
    Conjunto* intersecao(Conjunto const * const objConjunto)const;
    Conjunto* diferenca(Conjunto const * const objConjunto)const;
    bool subconjuntos(Conjunto const * const objConjunto)const;
    bool disjuntos(Conjunto const * const objConjunto)const;
    float mediaConjuntos()const;
    Conjunto* produtoEscalar(Conjunto const * const objConjunto)const;
    int amplitude()const;




};

#endif // CONJUNTO_H
