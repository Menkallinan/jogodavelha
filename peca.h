#ifndef PECA_H
#define PECA_H
#include <QPushButton>
#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <iostream>
#include<QLabel>
#include<vector>
#include <QVector>
#include <QDebug>
#include <QMouseEvent>

using namespace std;

class Pecas : public QLabel{
    static vector<int>pecasX;
    static vector<int>pecasO;
    static int vez;

public:
    Pecas();
    static int getVez();
    //fazer uma sobrecarga dos 2 verificar e jogo ganho
    static bool verificar(int a);
    static vector<int> getVetorX();
    static vector<int> getVetorO();
    static void apagarvetores();
    static bool JogoGanho(int vezz);
    static void proximarodada();
    static void setPecaX(int a);
    static void setPecaO(int a);
};


#endif // PECA_H
