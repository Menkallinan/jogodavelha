#ifndef JANELA_H
#define JANELA_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
class Janela : public QMainWindow
{

    Q_OBJECT
    static Janela *instancia;
    QPushButton *reiniciar, *salvar, *abrir, *botao1, *botao2, *botao3, *botao4, *botao5, *botao6, *botao7, *botao8,*botao9, *botao10;
    QTextEdit *editor;
    QLabel *parte1, *parte2, *parte3,*parte4, *parte5, *parte6,*parte7, *parte8, *parte9;
public:
    explicit Janela(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent * event);
public slots:
    void reiniciarJanela();
    void abrirArquivo();
    void paintEvent(QPaintEvent *event);
    static Janela *getInstancia();
    void salvarArquivo();
    void apertarbotao1();
    void apertarbotao2();
    void apertarbotao3();
    void apertarbotao4();
    void apertarbotao5();
    void apertarbotao6();
    void apertarbotao7();
    void apertarbotao8();
    void apertarbotao9();
signals:


};

#endif // JANELA_H
