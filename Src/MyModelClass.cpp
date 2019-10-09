#include <QObjectProxyExample/MyModelClass.h>


uint64_t MyModelClass::id() const
{
    return m_id;
}

void MyModelClass::setId(const uint64_t &id)
{
    m_id = id;
}

std::string MyModelClass::firstname() const
{
    return m_firstname;
}

void MyModelClass::setFirstname(const std::string &firstname)
{
    m_firstname = firstname;
}

std::string MyModelClass::lastname() const
{
    return m_lastname;
}

void MyModelClass::setLastname(const std::string &lastname)
{
    m_lastname = lastname;
}


MyModelClass::MyModelClass(uint64_t id, std::string fn, std::string ln):
    m_id(id),
    m_firstname(fn),
    m_lastname(ln)
{}

