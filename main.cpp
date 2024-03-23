#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QClipboard>
#include <QGuiApplication>
#include <QUrl>

class UrlEncoderDecoder : public QWidget {
    Q_OBJECT
public:
    UrlEncoderDecoder(QWidget *parent = nullptr) : QWidget(parent) {
        this->resize(600, 200);

        auto layout = new QVBoxLayout(this);
        auto entryLabel = new QLabel("Enter URL:", this);
        layout->addWidget(entryLabel);

        entry = new QLineEdit(this);
        layout->addWidget(entry);

        auto encodeButton = new QPushButton("Encode", this);
        connect(encodeButton, &QPushButton::clicked, this, &UrlEncoderDecoder::encodeUrl);
        layout->addWidget(encodeButton);

        auto decodeButton = new QPushButton("Decode", this);
        connect(decodeButton, &QPushButton::clicked, this, &UrlEncoderDecoder::decodeUrl);
        layout->addWidget(decodeButton);

        resultLabel = new QLabel("Result:", this);
        layout->addWidget(resultLabel);

        output = new QLabel("", this);
        output->setWordWrap(true);
        layout->addWidget(output);

        auto copyButton = new QPushButton("Copy to Clipboard", this);
        connect(copyButton, &QPushButton::clicked, this, &UrlEncoderDecoder::copyToClipboard);
        layout->addWidget(copyButton);
    }

private slots:
    void encodeUrl() {
        QString url = entry->text();
        QString encodedUrl = QUrl::toPercentEncoding(url);
        output->setText(encodedUrl);
    }

    void decodeUrl() {
        QString url = entry->text();
        QString decodedUrl = QUrl::fromPercentEncoding(url.toUtf8());
        output->setText(decodedUrl);
    }

    void copyToClipboard() {
        QGuiApplication::clipboard()->setText(output->text());
    }

private:
    QLineEdit *entry;
    QLabel *output;
    QLabel *resultLabel;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    UrlEncoderDecoder window;
    window.setWindowTitle("URL Encoder/Decoder");
    window.show();
    return app.exec();
}
