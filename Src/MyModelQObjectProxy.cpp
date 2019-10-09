#include <QObjectProxyExample/MyModelQObjectProxy.h>

MyModelClass MyModelQObjectProxy::myModel() const
{
    return m_myModel;
}

void MyModelQObjectProxy::setMyModel(const MyModelClass &myModel)
{
    m_myModel = myModel;
}

MyModelQObjectProxy::MyModelQObjectProxy(QObject *parent): QObject(parent) {}

QVariant MyModelQObjectProxy::id() const
{
    return QVariant::fromValue(m_myModel.id());
}

QVariant MyModelQObjectProxy::firstname() const
{
    return QString::fromStdString(m_myModel.firstname());
}

QVariant MyModelQObjectProxy::lastname() const
{
    return QString::fromStdString(m_myModel.lastname());
}

void MyModelQObjectProxy::setId(QVariant id)
{
    bool ok = false;
    auto asULong = id.toULongLong(&ok);
    if (!ok || m_myModel.id() == asULong)
        return;

    m_myModel.setId(asULong);
    emit idChanged(id);
}

void MyModelQObjectProxy::setFirstname(QVariant firstname)
{
    auto asString = firstname.toString().toStdString();
    if (m_myModel.firstname() == asString)
        return;
    m_myModel.setFirstname(asString);
    emit firstnameChanged(firstname);
}

void MyModelQObjectProxy::setLastname(QVariant lastname)
{
    auto asString = lastname.toString().toStdString();
    if (m_myModel.lastname() == asString)
        return;
    m_myModel.setLastname(asString);
    emit firstnameChanged(lastname);
}
