#ifndef CLUBTENISPADEL_H
#define CLUBTENISPADEL_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class ClubTenisPadel;
}

class ClubTenisPadel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClubTenisPadel(QWidget *parent = 0);
    ~ClubTenisPadel();

private:
    Ui::ClubTenisPadel *ui;
    QNetworkAccessManager manager;
    QString token;
    QUrl urlToken ;
    QUrl urlSample;

    void getToken(QNetworkReply* reply);

private slots:
    void on_sampleButton_clicked();
    void on_quitutton_clicked();

public slots:
    void requestFinished(QNetworkReply *reply);
};

#endif // CLUBTENISPADEL_H
