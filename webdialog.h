#ifndef WEBDIALOG_H
#define WEBDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QGridLayout>
#include <QtWebKitWidgets/QWebView>

QT_BEGIN_NAMESPACE
namespace Ui { class WebDialog; }
QT_END_NAMESPACE

class WebDialog : public QDialog
{
    Q_OBJECT

public:
    WebDialog(QWidget *parent = nullptr);
    ~WebDialog();

private slots:
    void on_pushButton_clicked();

public slots:
    void onPageHtmlFinsh(bool);
    void onPageHtmlCallQT();

private:
    Ui::WebDialog *ui;
    QWebView *pWebView;
};
#endif // WEBDIALOG_H
