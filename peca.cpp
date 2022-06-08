#include "peca.h"
#include <QDebug>
#include "janela.h"
#include <QVector>
#include <QPainter>
#include <QPen>
using namespace std ;


Pecas::Pecas()
{

}
int Pecas::vez =1;
vector<int>Pecas::pecasX;
vector<int>Pecas::pecasO;

void Pecas::setPecaX(int a){
    pecasX.push_back(a);
}
void Pecas::setPecaO(int a){
    pecasO.push_back(a);
}
bool Pecas::verificar(int a){
    for(int i = 0; i < pecasO.size();i++){
        if(pecasO[i] == a)
            throw "Essa posicao ja foi escolhida";
    }
    for(int i = 0; i < pecasX.size();i++){
        if(pecasX[i] == a)
            throw "Essa posicao ja foi escolhida";
    }
    return 0;
}

void Pecas::proximarodada(){
    vez++;
}
int Pecas::getVez(){
    return vez;
}
bool Pecas::JogoGanho(int vezz){
    int H_cima = 0;
    int H_meio = 0;
    int H_baixo = 0;
    int V_direita = 0;
    int V_esquerda = 0;
    int V_meio = 0;
    int diagonal1 = 0;
    int diagonal2 = 0;
    if(vezz % 2 == 1){
        for(int i = 0; i<pecasX.size();i++){
            if(pecasX[i] == 1 || pecasX[i] == 2 || pecasX[i] == 3)
                H_cima++;
            if(pecasX[i] == 4 || pecasX[i] == 5 || pecasX[i] == 6)
                H_meio++;
            if(pecasX[i] == 7 || pecasX[i] == 8 || pecasX[i] == 9)
                H_baixo++;
            if(pecasX[i] == 1 || pecasX[i] == 4 || pecasX[i] == 7)
                V_esquerda++;
            if(pecasX[i] == 2 || pecasX[i] == 5 || pecasX[i] == 8)
                V_meio++;
            if(pecasX[i] == 3 || pecasX[i] == 6 || pecasX[i] == 9)
                V_direita++;
            if(pecasX[i] == 1 || pecasX[i] == 5 || pecasX[i] == 9)
                diagonal1++;
            if(pecasX[i] == 3 || pecasX[i] == 5 || pecasX[i] == 7)
                diagonal2++;
        }
        if(H_cima == 3 || H_meio == 3 || H_baixo ==3 || V_direita == 3 || V_esquerda == 3|| V_meio ==3 ||diagonal1 ==3 || diagonal2 ==3)
            return 1;
        else
            return 0;
    }
    else{
        for(int i = 0; i<pecasO.size();i++){
            if(pecasO[i] == 1 || pecasO[i] == 2 || pecasO[i] == 3)
                H_cima++;
            if(pecasO[i] == 4 || pecasO[i] == 5 || pecasO[i] == 6)
                H_meio++;
            if(pecasO[i] == 7 || pecasO[i] == 8 || pecasO[i] == 9)
                H_baixo++;
            if(pecasO[i] == 1 || pecasO[i] == 4 || pecasO[i] == 7)
                V_esquerda++;
            if(pecasO[i] == 2 || pecasO[i] == 5 || pecasO[i] == 8)
                V_meio++;
            if(pecasO[i] == 3 || pecasO[i] == 6 || pecasO[i] == 9)
                V_direita++;
            if(pecasO[i] == 1 || pecasO[i] == 5 || pecasO[i] == 9)
                diagonal1++;
            if(pecasO[i] == 3 || pecasO[i] == 5 || pecasO[i] == 7)
                diagonal2++;
        }
        if(H_cima == 3 || H_meio == 3 || H_baixo ==3 || V_direita == 3 || V_esquerda == 3|| V_meio ==3 ||diagonal1 ==3 || diagonal2 ==3)
            return 1;
        else
            return 0;
    }
}
vector<int> Pecas::getVetorO(){
    return pecasO;
}
vector<int> Pecas::getVetorX(){
    return pecasX;
}

void Pecas::apagarvetores(){
    pecasO.clear();
    pecasX.clear();
    vez = 1;
}

