#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_uploadBtn_clicked()
{
    // selecting
    filename = QFileDialog::getOpenFileName(this, tr("Open PDF File"), "/", tr("PDF Files (*.pdf )") );
    // loading
    document->load(filename);
    // creatn new obj
    selectedText = new QString;
}

void MainWindow::on_extractBtn_clicked()
{
    // getn page
    int page = ui->page->text().toInt();
    // getn text frm slcted page
    QString selectedText = document->getAllText(page).text();
    // settn text on textedit
    ui->textEdit->setText(selectedText);
}
