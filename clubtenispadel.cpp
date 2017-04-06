#include "clubtenispadel.h"
#include "ui_clubtenispadel.h"

ClubTenisPadel::ClubTenisPadel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClubTenisPadel),
    urlToken ("http://192.168.1.41/clubdev/api/v1.0/tokenauthentications"),
    urlSample("http://192.168.1.41/clubdev/api/v1.0/sample")
    {
    ui->setupUi(this);
    QNetworkRequest request(urlToken);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("username", "pepe");
    params.addQueryItem("password", "pepe");
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
               SLOT(requestFinished(QNetworkReply*)));
    QNetworkReply *reply = manager.post(request, params.toString(QUrl::FullyEncoded).toUtf8());

}

ClubTenisPadel::~ClubTenisPadel()
{
    delete ui;
}

void ClubTenisPadel::on_sampleButton_clicked()
{

    QNetworkRequest request(urlSample);
    QByteArray authorization = "Bearer ";
    authorization.append(token);

    request.setRawHeader("Authorization", authorization);
    QNetworkReply *reply = manager.get(request);
}

void ClubTenisPadel::on_quitutton_clicked()
{
    QCoreApplication::quit();
}

void ClubTenisPadel::requestFinished(QNetworkReply* reply)
{
    if (reply->request().url() == urlToken)
        getToken(reply);
    if (reply->request().url() == urlSample)
        ui->textEdit->setText(reply->readAll());
    reply->deleteLater();
}

void ClubTenisPadel::getToken(QNetworkReply* reply)
{
    //Read token from reply
    QJsonParseError err;

    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll(), &err);
    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        QJsonValue val = obj.value("token");
        token = val.toString();
    }
}
