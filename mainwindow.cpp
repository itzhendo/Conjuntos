#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      CA(0),
      CB(0)
{
    ui->setupUi(this);
    ui->lineEditValoresDoConjuntoCA->setEnabled(false);
    ui->lineEditValoresDoConjuntoCB->setEnabled(false);
    ui->pushButtonInserirCA->setEnabled(false);
    ui->pushButtonInserirCB->setEnabled(false);
    ui->lineEditValorCA->setEnabled(false);
    ui->lineEditValorCB->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete CA;
    delete CB;
    delete ui;
}


void MainWindow::on_pushButtonCriarCA_clicked()
{
    try
    {
        int tamanho = ui->lineEditTamanhoCA->text().toInt();
       CA = new Conjunto(tamanho);
       ui->lineEditTamanhoCA->setEnabled(false);
       ui->pushButtonCriarCA->setEnabled(false);
       ui->pushButtonInserirCA->setEnabled(true);
       ui->lineEditValorCA->setEnabled(true);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this, "Erro do Sistema",erro);
    }
}

void MainWindow::on_pushButtonInserirCA_clicked()
{
    try
    {
       CA->inserirElemento(ui->lineEditValorCA->text().toInt());
       ui->lineEditValorCA->clear();
       QString saida = "CA = ";
       saida+= CA->getConjunto();
       ui->lineEditValoresDoConjuntoCA->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this, "Erro do Sistema",erro);
    }
}

void MainWindow::on_pushButtonCriarCB_clicked()
{
    try
    {
       int tamanho = ui->lineEditTamanhoCB->text().toInt();
       CB = new Conjunto(tamanho);
       ui->lineEditTamanhoCB->setEnabled(false);
       ui->pushButtonCriarCB->setEnabled(false);
       ui->pushButtonInserirCB->setEnabled(true);
       ui->lineEditValorCB->setEnabled(true);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this, "Erro do Sistema",erro);
    }
}

void MainWindow::on_pushButtonInserirCB_clicked()
{
    try
    {
       CB->inserirElemento(ui->lineEditValorCB->text().toInt());
       ui->lineEditValorCB->clear();
       QString saida = "CB = ";
       saida+= CB->getConjunto();
       ui->lineEditValoresDoConjuntoCB->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this, "Erro do Sistema",erro);
    }
}

void MainWindow::on_pushButtonAUniaoB_clicked()
{
  try
    {
       Conjunto *CC = CA->uniao(CB);
       QString saida = "CC = " + CC->getConjunto();
       ui->lineEditResultado->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this, "Erro do Sistema",erro);
    }
}


void MainWindow::on_pushButtonAIntersecaoB_clicked()
{
    try
      {
         Conjunto *CD = CA->intersecao(CB);
         QString saida = "CD = " + CD->getConjunto();
         ui->lineEditResultado->setText(saida);
      }
      catch (QString &erro)
      {
          QMessageBox::information(this, "Erro do Sistema",erro);
      }
}

void MainWindow::on_pushButtonAdiferencaB_clicked()
{
    try
      {
         Conjunto *CE = CA->diferenca(CB);
         QString saida = "CE = " + CE->getConjunto();
         ui->lineEditResultado->setText(saida);
      }
      catch (QString &erro)
      {
          QMessageBox::information(this, "Erro do Sistema",erro);
      }
}

void MainWindow::on_pushButtonBdiferencaA_clicked()
{
    try
      {
         Conjunto *CF = CB->diferenca(CA);
         QString saida = "CF = " + CF->getConjunto();
         ui->lineEditResultado->setText(saida);
      }
      catch (QString &erro)
      {
          QMessageBox::information(this, "Erro do Sistema",erro);
      }
}


void MainWindow::on_pushButtonASubB_clicked()
{
    try
      {
         if(CA->subconjuntos(CB))
         {
            QString saida= "A é subconjunto de B";
            ui->lineEditResultado->setText(saida);
         }
         else
         {
             QString saida= "A não é subconjunto de B";
             ui->lineEditResultado->setText(saida);
          }


      }
      catch (QString &erro)
      {
          QMessageBox::information(this, "Erro do Sistema",erro);
      }
}

void MainWindow::on_pushButtonBSubA_clicked()
{
    try
      {
         if(CB->subconjuntos(CA))
         {
            QString saida= "B é subconjunto de A";
            ui->lineEditResultado->setText(saida);
         }
         else
         {
             QString saida= "B não é subconjunto de A";
             ui->lineEditResultado->setText(saida);
          }


      }
      catch (QString &erro)
      {
          QMessageBox::information(this, "Erro do Sistema",erro);
      }

}

void MainWindow::on_pushButtonMediaCA_clicked()
{
    try
      {
         QString saida = "Media CA = ";
         saida+= QString::number(CA->mediaConjuntos());
         ui->lineEditResultado->setText(saida);
      }
      catch (QString &erro)
      {
          QMessageBox::information(this, "Erro do Sistema",erro);
      }

}

void MainWindow::on_pushButtonMediaCB_clicked()
{
    try
      {
         QString saida = "Media CB = ";
         saida+= QString::number(CB->mediaConjuntos());
         ui->lineEditResultado->setText(saida);
      }
      catch (QString &erro)
      {
          QMessageBox::information(this, "Erro do Sistema",erro);
      }


}
void MainWindow::on_pushButtonIdenticos_clicked()
{
    try
      {
        if(CA->diferenca(CB)->estaVazio() && CB->diferenca(CA)->estaVazio())
        {
            QString saida = "São identicos";
            ui->lineEditResultado->setText(saida);
        }
        else
        {
            QString saida = "Nao sao identicos";
            ui->lineEditResultado->setText(saida);
        }

      }
      catch (QString &erro)
      {
          QMessageBox::information(this, "Erro do Sistema",erro);
      }


}

void MainWindow::on_pushButtonDisjuntos_clicked()
{
    try
      {
         if(CA->disjuntos(CB))
         {
             QString saida = "Sao disjuntos";
             ui->lineEditResultado->setText(saida);
         }
         else
         {
             QString saida = "Nao sao disjuntos";
             ui->lineEditResultado->setText(saida);
         }

      }
      catch (QString &erro)
      {
          QMessageBox::information(this, "Erro do Sistema",erro);
      }

}

void MainWindow::on_pushButtonAmplitudeA_clicked()
{
    QString saida= "Amplitude A = ";
    saida+=QString::number(CA->amplitude());
    ui->lineEditResultado->setText(saida);

}

void MainWindow::on_pushButtonAmplitudeB_clicked()
{
    QString saida= "Amplitude B = ";
    saida+=QString::number(CB->amplitude());
    ui->lineEditResultado->setText(saida);

}

void MainWindow::on_pushButtonProdutoEscalar_clicked()
{
    try
    {
       Conjunto *Escalar = CA->produtoEscalar(CB);
       QString saida = "Produto Escalar = " + Escalar->getConjunto();
       ui->lineEditResultado->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this, "Erro do Sistema",erro);
    }

}
