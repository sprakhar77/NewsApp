#include <Model/ArticleModel.h>
#include <RestHandle/Request/CustomAPI.h>
#include <RestHandle/Response/Article.h>
#include <RestHandle/RestClient.h>

#include <QObject>

class CustomBackend : public QObject {
    Q_OBJECT
    Q_PROPERTY(CustomAPI* customAPI READ customAPI CONSTANT)
    Q_PROPERTY(ArticleModel* articleModel READ articleModel CONSTANT)

public:
    explicit CustomBackend(QObject* parent = nullptr);

    CustomAPI* customAPI() const;
    ArticleModel* articleModel() const;

    void fetch(const QVector<QString>&sources);

private slots:
    void onResponseRecieved(const QJsonObject& json);

private:
    CustomAPI* m_customAPI{ nullptr };
    RestClient m_restClient;
    ArticleModel* m_articleModel{ nullptr };
};