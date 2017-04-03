#include "clubtenispadel.h"
#include "ui_clubtenispadel.h"

ClubTenisPadel::ClubTenisPadel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClubTenisPadel)
{
    ui->setupUi(this);
}

ClubTenisPadel::~ClubTenisPadel()
{
    delete ui;
}

void ClubTenisPadel::on_sampleButton_clicked()
{
    QUrl url("http://localhost/clubdev/api/v1.0/sample");
    QNetworkRequest request(url);
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            SLOT(requestFinished(QNetworkReply*)));
    QNetworkReply *reply = manager.get(request);
}

void ClubTenisPadel::on_quitutton_clicked()
{
    QCoreApplication::quit();
}
void ClubTenisPadel::requestFinished(QNetworkReply* reply)
{
    ui->textEdit->setText(reply->readAll());
}
