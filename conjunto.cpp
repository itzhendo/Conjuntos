#include "conjunto.h"

Conjunto::Conjunto(int tamanhoDoVetor):
    tamanho(0),
    indiceDeUso(0),
    array(0)
{
    if (tamanhoDoVetor<=0)
        throw QString("Tamanho não pode ser <= 0");
    array = new int[tamanhoDoVetor];
    tamanho = tamanhoDoVetor;
}
Conjunto::~Conjunto()
{
    delete[] array;
}
void Conjunto::inserirElemento(int valor)
{
    if(estaCheio())
        throw QString ("Conjunto está cheio");
    if(buscar(valor))
        throw QString ("Elemento já existe");
    array[indiceDeUso] = valor;
    indiceDeUso++;
}
bool Conjunto::estaCheio()const
{
    return (tamanho == indiceDeUso);
}
QString Conjunto::getConjunto()const
{
    QString saida("{ ");
        saida+= QString::number(array[0]);
    for(int pos = 1; pos < indiceDeUso; pos++ )
    {
        saida+= ", " + QString::number(array[pos]);
    }
        saida+= " }";
    return saida;
}
bool Conjunto::buscar(int elemento)const
{
    for(int pos = 0; pos < indiceDeUso; pos++)
        if(elemento == array[pos])
        {
            return true;
        }
            return false;
}
bool Conjunto::estaVazio()const
{
    return (indiceDeUso == 0);
}
Conjunto* Conjunto::uniao(Conjunto const * const objConjunto)const
{
    int tamanho = indiceDeUso +objConjunto->indiceDeUso;
    Conjunto *aux = new Conjunto(tamanho);
    for(int pos = 0; pos < indiceDeUso; pos++)
    {
        aux->array[pos] = array[pos];
    }
    aux->indiceDeUso = indiceDeUso;
    for(int pos = 0; pos < objConjunto->indiceDeUso; pos++)
    {
        if(!aux->buscar(objConjunto->array[pos]))
        {
            aux->array[aux->indiceDeUso] = objConjunto->array[pos];
            aux->indiceDeUso++;
        }
    }
    return aux;
}
Conjunto* Conjunto::intersecao(Conjunto const * const objConjunto)const
{
    int tamanho = 0;
    if(indiceDeUso < objConjunto->indiceDeUso)
        tamanho = indiceDeUso;
    else
        tamanho = objConjunto->indiceDeUso;
    Conjunto *aux = new Conjunto(tamanho);

    for(int pos = 0; pos < indiceDeUso; pos++)
    {
        if(objConjunto->buscar(array[pos]))
        {
            aux->array[aux->indiceDeUso] = array[pos];
            aux->indiceDeUso++;
        }
    }
    return aux;

}
Conjunto* Conjunto::diferenca(Conjunto const * const objConjunto)const
{
    int tamanho = indiceDeUso;
    Conjunto *aux = new Conjunto(tamanho);
    for(int pos = 0; pos < indiceDeUso; pos++)
    {
        if(!objConjunto->buscar(array[pos]))
        {
            aux->array[aux->indiceDeUso] = array[pos];
            aux->indiceDeUso++;
        }
    }
    return aux;
}
bool Conjunto::subconjuntos(Conjunto const * const objConjunto)const
{
    int tamanho = indiceDeUso;
    Conjunto *aux = new Conjunto(tamanho);
    for(int pos = 0; pos < indiceDeUso; pos++)
    {
        if(!objConjunto->buscar(array[pos]))
        {
            aux->array[aux->indiceDeUso] = array[pos];
            aux->indiceDeUso++;
        }
    }

    if (aux->indiceDeUso==0)
    {
        return true;
    }
    else
        return false;
}
float Conjunto::mediaConjuntos()const
{
    float calc = 0;
    for(int pos = 0; pos < indiceDeUso; pos++)
    {
        calc+= array[pos];
    }
    return calc/indiceDeUso;
}
Conjunto* Conjunto::produtoEscalar(Conjunto const * const objConjunto)const
{
    int tamanho = 0;
    if(indiceDeUso==objConjunto->indiceDeUso)
    {
        tamanho = indiceDeUso;
        Conjunto *aux = new Conjunto(tamanho);
        for(int pos = 0 ; pos < indiceDeUso; pos++)
         {
            aux->array[aux->indiceDeUso] = array[pos] * objConjunto->array[pos];
            aux->indiceDeUso++;
         }
       return aux;
    }
    else
          throw QString ("Conjunto não possui o mesmo tamanho");

}
int Conjunto::amplitude()const
{
    int maior = 0;
    int menor =  1000;
    for(int pos = 0; pos < indiceDeUso; pos++)
    {
        if(array[pos] > maior)
        {
           maior = array[pos];
        }
        if(array[pos] < menor)
        {
           menor = array[pos];
        }
    }
    return maior-menor;
}
bool Conjunto::disjuntos(Conjunto const * const objConjunto)const
{
    int tamanho = 0;
    int num = 0;
    if(indiceDeUso < objConjunto->indiceDeUso)
        tamanho = indiceDeUso;
    else
        tamanho = objConjunto->indiceDeUso;
    Conjunto *aux = new Conjunto(tamanho);

    for(int pos = 0; pos < indiceDeUso; pos++)
    {
        if(objConjunto->buscar(array[pos]))
        {
            aux->array[aux->indiceDeUso] = array[pos];
            aux->indiceDeUso++;
            num++;
        }
    }
    if(num == 0)
        return true;
    else
        return false;

}
