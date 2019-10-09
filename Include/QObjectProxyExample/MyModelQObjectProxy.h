#ifndef MYMODELQOBJECTPROXY_H
#define MYMODELQOBJECTPROXY_H

#include <QObject>
#include <QObjectProxyExample/MyModelClass.h>
#include <QVariant>

class MyModelQObjectProxy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QVariant firstname READ firstname WRITE setFirstname NOTIFY firstnameChanged)
    Q_PROPERTY(QVariant lastname READ lastname WRITE setLastname NOTIFY lastnameChanged)

public:
    explicit MyModelQObjectProxy(QObject *parent = nullptr);


    MyModelClass myModel() const;
    void setMyModel(const MyModelClass &myModel);

    QVariant id() const;

    QVariant firstname() const;

    QVariant lastname() const;

public slots:
    void setId(QVariant id);

    void setFirstname(QVariant firstname);

    void setLastname(QVariant lastname);

signals:
    void idChanged(QVariant id);

    void firstnameChanged(QVariant firstname);

    void lastnameChanged(QVariant lastname);

private:
    MyModelClass m_myModel;
};

#endif // MYMODELQOBJECTPROXY_H
