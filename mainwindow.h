#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMessageBox>
#include <conjunto.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonCriarCA_clicked();

    void on_pushButtonInserirCA_clicked();

    void on_pushButtonCriarCB_clicked();

    void on_pushButtonInserirCB_clicked();

    void on_pushButtonAUniaoB_clicked();

    void on_pushButtonAIntersecaoB_clicked();

    void on_pushButtonAdiferencaB_clicked();

    void on_pushButtonBdiferencaA_clicked();

    void on_pushButtonASubB_clicked();

    void on_pushButtonBSubA_clicked();

    void on_pushButtonMediaCA_clicked();

    void on_pushButtonMediaCB_clicked();

    void on_pushButtonProdutoEscalar_clicked();

    void on_pushButtonIdenticos_clicked();

    void on_pushButtonDisjuntos_clicked();

    void on_pushButtonAmplitudeA_clicked();

    void on_pushButtonAmplitudeB_clicked();

private:
    Ui::MainWindow *ui;
    Conjunto *CA;
    Conjunto *CB;
};
#endif // MAINWINDOW_H
