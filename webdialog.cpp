#include "webdialog.h"
#include "ui_webdialog.h"

#include <QtWebKitWidgets/QWebFrame>
#include <QMessageBox>

WebDialog::WebDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WebDialog)
{
    ui->setupUi(this);

    pWebView = new QWebView(this);

    //网页加载完成后, 槽调用
    connect(pWebView,SIGNAL(loadFinished(bool)),this,SLOT(onPageHtmlFinsh(bool)));





    //setting
    pWebView->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    pWebView->settings()->setAttribute(QWebSettings::JavaEnabled, true);
    pWebView->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    pWebView->settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
    pWebView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    pWebView->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
    pWebView->settings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);
    pWebView->settings()->setAttribute(QWebSettings::JavascriptCanCloseWindows, true);
    pWebView->settings()->setAttribute(QWebSettings::AutoLoadImages, true);
    pWebView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
        //
    pWebView->settings()->setAttribute(QWebSettings::CSSGridLayoutEnabled, true);



    //QGridLayout *layout = new QGridLayout(this);
    //layout->addWidget(pWebView,0,0,0,0);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(pWebView);
    layout->setContentsMargins(0,0,0,100);


    this->setLayout(layout);


    QString htmlPath = QCoreApplication::applicationDirPath() + "/www/index.html";
    //pWebView->load(QUrl("file:///" + htmlPath));
    pWebView->load(QUrl("file:////Users/apple/qtprojects/webview/www/index.htm"));
    //pWebView->load(QUrl("http://127.0.0.1:8888/main/index.htm#/admin"));
    //pWebView->load(QUrl("http://m.baidu.com"));
    //pWebView->load(QUrl("http://html5test.com/"));

    //pWebView->load(QUrl(htmlPath));

}

WebDialog::~WebDialog()
{
    delete ui;
}


void WebDialog::on_pushButton_clicked()
{
    //取标题
    QString a = pWebView->title();
    qDebug() << a << endl;


    //调用Html中的JS
    pWebView->page()->mainFrame()->evaluateJavaScript(QString("qtcallHtml()"));
}


void WebDialog::onPageHtmlFinsh(bool)  {
    qDebug() << "网页加载完成:  finsh .html loading ....." << endl;

    //预埋QT对象
    pWebView->page()->mainFrame()->addToJavaScriptWindowObject("Dialog",this);

}

void WebDialog::onPageHtmlCallQT(){
    qDebug() << "网页js Call QT .function ....." << endl;
    
    QMessageBox::information(this, "消息提醒", "我是网页里面JS调用QT然后弹出的框", QMessageBox::NoButton, QMessageBox::Close);
}

