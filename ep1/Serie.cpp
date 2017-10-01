#include "Serie.h"
#include <iostream>
using namespace std;

void Serie::setNome(string nome) {
    this->nome = nome;
}

void Serie::setNomeDoCanalX(string nomeDoCanalX) {
    this->nomeDoCanalX = nomeDoCanalX;
}

void Serie::setNomeDoCanalY(string nomeDoCanalY) {
    this->nomeDoCanalY = nomeDoCanalY;
}

string Serie::getNome() {
    return this->nome;
}

string Serie::getNomeDoCanalX() {
    return this->nomeDoCanalX;
}

string Serie::getNomeDoCanalY() {
    return this->nomeDoCanalY;
}

int Serie::getQuantidade() {
    return this->quantidade;
}

bool Serie::estaVazia() {
    if(this->quantidade == 0) {
        return true;
    } else {
        return false;
    }
}

void Serie::adicionar(double x, double y) {
   if(this->quantidade <= NUMERO_MAXIMO_VALORES) {
        this->eixoX[quantidade] = x;
        this->eixoY[quantidade] = y;
        quantidade++;
   }
}

Ponto* Serie::getLimiteSuperior() {
    Ponto* limiteSuperior = new Ponto;
    if(!estaVazia()) {
        double maiorX = this->eixoX[0];
        for(int i = 1; i< this->quantidade; i++) {
            if(maiorX < this->eixoX[i]) {
                maiorX = this->eixoX[i];
            }
        }
        double maiorY = this->eixoY[0];
        for(int j = 1; j < quantidade; j++) {
            if(maiorY < this->eixoY[j]) {
                maiorY = this->eixoY[j];
            }
        }
        limiteSuperior->setX(maiorX);
        limiteSuperior->setY(maiorY);
        return limiteSuperior;
    } else {
        return NULL;
    }
}

Ponto* Serie::getLimiteInferior() {
    Ponto* limiteInferior = new Ponto;
    if(!estaVazia()) {
        double menorX = this->eixoX[0];
        for(int i = 1; i< this->quantidade; i++) {
            if(menorX > this->eixoX[i]) {
                menorX = this->eixoX[i];
            }
        }
        double menorY = this->eixoY[0];
        for(int j = 1; j < quantidade; j++) {
            if(menorY > this->eixoY[j]) {
                menorY = this->eixoY[j];
            }
        }
        limiteInferior->setX(menorX);
        limiteInferior->setY(menorY);
        return limiteInferior;
    } else {
        return NULL;
    }
}

Ponto* Serie::getPosicao(int posicao) {
    if (posicao >= 0 && posicao < NUMERO_MAXIMO_VALORES) {
        Ponto* pontoPosicao = new Ponto;
        pontoPosicao->setX(eixoX[posicao]);
        pontoPosicao->setY(eixoY[posicao]);
        return pontoPosicao;
    } else {
        return NULL;
    }
}

void Serie::imprimir() {
    cout << "Serie " << this->getNome() << endl;
    for(int i =0; i < this->quantidade; i++) {
        cout << "(" << this->eixoX[i] << ", " << this->eixoY[i] << ")" << endl;
    }
}
