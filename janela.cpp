#include "janela.h"
#include "peca.h"
#include <QString>
#include <QVector>
#include <QPainter>
#include <QFileDialog>
#include <QTextEdit>
#include <QCloseEvent>
#include <fstream>
#include <iostream>
#include <QInputDialog>
#include<QMessageBox>
#include<QLabel>
#include <QDebug>
using namespace std ;

Janela::Janela(QWidget *parent) : QMainWindow(parent){
    this->setGeometry(100,100,800,600);
    this->setWindowTitle("Jogo da velha");

    salvar = new QPushButton("salvar",this);
    salvar-> setGeometry(690, 20, 90, 40);

    abrir = new QPushButton("abrir",this);
    abrir->setGeometry(690,80,90,40);

    reiniciar = new QPushButton("Reiniciar",this);
    reiniciar->setGeometry(690, 140, 90, 40);

    botao1 = new QPushButton("", this);
    botao1->setGeometry(100,80,120,120);

    parte1 = new QLabel(this);
    parte1 ->setGeometry(100,80,120,120);

    botao2 = new QPushButton("",this);
    botao2->setGeometry(220,80,120,120);

    parte2 = new QLabel(this);
    parte2 ->setGeometry(220,80,120,120);

    botao3 = new QPushButton("", this);
    botao3 ->setGeometry(340,80,120,120);

    parte3 = new QLabel(this);
    parte3 ->setGeometry(340,80,120,120);

    botao4 = new QPushButton("", this);
    botao4->setGeometry(100,200,120,120);

    parte4 = new QLabel(this);
    parte4 ->setGeometry(100,200,120,120);

    botao5 = new QPushButton("",this);
    botao5->setGeometry(220,200,120,120);

    parte5 = new QLabel(this);
    parte5 ->setGeometry(220,200,120,120);

    botao6 = new QPushButton("", this);
    botao6 ->setGeometry(340,200,120,120);

    parte6 = new QLabel(this);
    parte6 ->setGeometry(340,200,120,120);

    botao7 = new QPushButton("", this);
    botao7->setGeometry(100,320,120,120);

    parte7 = new QLabel(this);
    parte7 ->setGeometry(100,320,120,120);

    botao8 = new QPushButton("",this);
    botao8->setGeometry(220,320,120,120);

    parte8 = new QLabel(this);
    parte8 ->setGeometry(220,320,120,120);

    botao9 = new QPushButton("", this);
    botao9 ->setGeometry(340,320,120,120);

    parte9 = new QLabel(this);
    parte9 ->setGeometry(340,320,120,120);


    connect(reiniciar, SIGNAL(clicked(bool)),this,SLOT(reiniciarJanela()));

    connect(abrir, SIGNAL(clicked(bool)), this, SLOT(abrirArquivo()));

    connect(salvar, SIGNAL(clicked(bool)), this, SLOT(salvarArquivo()));

}
Janela* Janela::instancia = nullptr;
Janela* Janela::getInstancia(){
    if(instancia == nullptr)
        instancia = new Janela();
    return instancia;
}
void Janela::reiniciarJanela(){
    Pecas::apagarvetores();

}
void Janela::abrirArquivo(){

}
void Janela::salvarArquivo(){
    std::fstream f("Salvo", std::fstream::out);
    for(int i = 0; i < Pecas::getVetorX().size(); i++){
        f<<Pecas::getVetorX().at(i)<<"\n";
    }
    for(int i = 0; i < Pecas::getVetorO().size(); i++){
        f<<Pecas::getVetorO().at(i)<<"\n";
    }
    f.close();
}
void Janela::apertarbotao1(){
      try{
          Pecas::verificar(1);
          Pecas a;
          botao1->hide();
          if(a.getVez()%2 == 1){
              a.setPecaX(1);
              parte1->setPixmap(QPixmap("/home/esdras/projeto/Arquivox.png"));
              int ganho = Pecas::JogoGanho(Pecas::getVez());
              if(ganho == 1){
                   QMessageBox::about(this,"Parabens", "O 'X' e o vencedor");
                   Pecas::apagarvetores();
              }
              else
                   Pecas::proximarodada();
          }
          else{
              a.setPecaO(1);
              parte1->setPixmap(QPixmap("/home/esdras/projeto/Bolinha.png"));
              int ganho = Pecas::JogoGanho(Pecas::getVez());
              if(ganho == 1){
                   QMessageBox::about(this,"Parabens", "O 'O' e o vencedor");
                   Pecas::apagarvetores();
              }
              else
                   Pecas::proximarodada();
          }
     }
     catch(char const *erro){
        QMessageBox::about(this,"Erro", "Essa posicao ja foi escolhida");
     }
}
void Janela::apertarbotao2(){
    try{
        Pecas::verificar(2);
        Pecas a;
        botao2->hide();
        if(a.getVez()%2 == 1){
            a.setPecaX(2);
            parte2->setPixmap(QPixmap("/home/esdras/projeto/Arquivox.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'X' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
        else{
            a.setPecaO(2);
            parte2->setPixmap(QPixmap("/home/esdras/projeto/Bolinha.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'O' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
   }
   catch(char const *erro){
      QMessageBox::about(this,"Erro", "Essa posicao ja foi escolhida");
   }
}
void Janela::apertarbotao3(){
    try{
        Pecas::verificar(3);
        Pecas a;
        botao3->hide();
        if(a.getVez()%2 == 1){
            a.setPecaX(3);
            parte3->setPixmap(QPixmap("/home/esdras/projeto/Arquivox.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'X' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
        else{
            a.setPecaO(3);
            parte3->setPixmap(QPixmap("/home/esdras/projeto/Bolinha.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'O' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
   }
   catch(char const *erro){
      QMessageBox::about(this,"Erro", "Essa posicao ja foi escolhida");
   }
}
void Janela::apertarbotao4(){
    try{
        Pecas::verificar(4);
        Pecas a;
        botao4->hide();
        if(a.getVez()%2 == 1){
            a.setPecaX(4);
            parte4->setPixmap(QPixmap("/home/esdras/projeto/Arquivox.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'X' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
        else{
            a.setPecaO(4);
            parte4->setPixmap(QPixmap("/home/esdras/projeto/Bolinha.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){

                 QMessageBox::about(this,"Parabens", "O 'O' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
   }
   catch(char const *erro){
      QMessageBox::about(this,"Erro", "Essa posicao ja foi escolhida");
   }
}
void Janela::apertarbotao5(){
    try{
        Pecas::verificar(5);
        Pecas a;
        botao5->hide();
        if(a.getVez()%2 == 1){
            a.setPecaX(5);
            parte5->setPixmap(QPixmap("/home/esdras/projeto/Arquivox.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'X' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
        else{
            a.setPecaO(5);
            parte5->setPixmap(QPixmap("/home/esdras/projeto/Bolinha.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'O' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
   }
   catch(char const *erro){
      QMessageBox::about(this,"Erro", "Essa posicao ja foi escolhida");
   }
}
void Janela::apertarbotao6(){
    try{
        Pecas::verificar(6);
        Pecas a;
        botao6->hide();
        if(a.getVez()%2 == 1){
            a.setPecaX(6);
            parte6->setPixmap(QPixmap("/home/esdras/projeto/Arquivox.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                QMessageBox::about(this,"Parabens", "O 'X' e o vencedor");
                Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
        else{
            a.setPecaO(6);
            parte6->setPixmap(QPixmap("/home/esdras/projeto/Bolinha.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                QMessageBox::about(this,"Parabens", "O 'O' e o vencedor");
                Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
   }
   catch(char const *erro){
      QMessageBox::about(this,"Erro", "Essa posicao ja foi escolhida");
   }
}
void Janela::apertarbotao7(){
    try{
        Pecas::verificar(7);
        Pecas a;
        botao7->hide();
        if(a.getVez()%2 == 1){
            a.setPecaX(7);
            parte7->setPixmap(QPixmap("/home/esdras/projeto/Arquivox.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 reiniciarJanela();
                 QMessageBox::about(this,"Parabens", "O 'X' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
        else{
            a.setPecaO(7);
            parte7->setPixmap(QPixmap("/home/esdras/projeto/Bolinha.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'O' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
   }
   catch(char const *erro){
      QMessageBox::about(this,"Erro", "Essa posicao ja foi escolhida");
   }
}
void Janela::apertarbotao8(){
    try{
        Pecas::verificar(8);
        Pecas a;
        botao8->hide();
        if(a.getVez()%2 == 1){
            a.setPecaX(8);
            parte8->setPixmap(QPixmap("/home/esdras/projeto/Arquivox.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'X' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
        else{
            a.setPecaO(8);
            parte8->setPixmap(QPixmap("/home/esdras/projeto/Bolinha.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'O' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
   }
   catch(char const *erro){
      QMessageBox::about(this,"Erro", "Essa posicao ja foi escolhida");
   }
}
void Janela::apertarbotao9(){
    try{
        Pecas::verificar(9);
        Pecas a;
        botao9->hide();
        if(a.getVez()%2 == 1){
            a.setPecaX(9);
            parte9->setPixmap(QPixmap("/home/esdras/projeto/Arquivox.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'X' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
        else{
            a.setPecaO(9);
            parte9->setPixmap(QPixmap("/home/esdras/projeto/Bolinha.png"));
            int ganho = Pecas::JogoGanho(Pecas::getVez());
            if(ganho == 1){
                 QMessageBox::about(this,"Parabens", "O 'O' e o vencedor");
                 Pecas::apagarvetores();
            }
            else
                 Pecas::proximarodada();
        }
   }
   catch(char const *erro){
      QMessageBox::about(this,"Erro", "Essa posicao ja foi escolhida");
   }
}
void Janela::mousePressEvent(QMouseEvent *event){
    int posicao;
    if(event->button()== Qt::LeftButton || event->button()== Qt::RightButton){
        if(Pecas::getVez() % 2 == 1)
            posicao = QInputDialog::getInt(this, "Insira 'X'", "Posicao");
        else
            posicao = QInputDialog::getInt(this, "Insira 'O'", "Posicao");
        if(posicao == 1)
            apertarbotao1();

        else if(posicao == 2)
            apertarbotao2();

        else if(posicao == 3)
            apertarbotao3();

        else if(posicao == 4)
            apertarbotao4();

        else if(posicao == 5)
            apertarbotao5();

        else if(posicao == 6)
            apertarbotao6();

        else if(posicao == 7)
            apertarbotao7();

        else if(posicao == 8)
            apertarbotao8();

        else if(posicao == 9)
            apertarbotao9();
        if(posicao > 9 || posicao < 1)
            QMessageBox::about(this, "Erro", "Posicao invalida, tente novamente");
    }
}

void Janela::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.setPen(Qt::blue);
    //(,vai para baixo, ,)
    p.drawRect(QRect(99,79,361,361));
    p.setBrush(Qt::blue);
}

