#ifndef MYMODELCLASS_H
#define MYMODELCLASS_H

#include <string>
#include <cinttypes>

class MyModelClass
{
    uint64_t m_id = 0;
    std::string m_firstname;
    std::string m_lastname;

public:
    MyModelClass() = default;
    MyModelClass(uint64_t id, std::string fn, std::string ln);

    uint64_t id() const;
    void setId(const uint64_t &id);
    std::string firstname() const;
    void setFirstname(const std::string &firstname);
    std::string lastname() const;
    void setLastname(const std::string &lastname);
};

#endif // MYMODELCLASS_H
