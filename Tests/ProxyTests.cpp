#include <doctest/doctest.h>
#include <QObjectProxyExample/MyModelQObjectProxy.h>

TEST_CASE("Get properties test") {
    MyModelClass myModel(1, "test_fn", "test_ln");
    MyModelQObjectProxy proxy;
    proxy.setMyModel(myModel);
    CHECK_EQ(proxy.property("firstname").toString().toStdString(), myModel.firstname());
    CHECK_EQ(proxy.property("lastname").toString().toStdString(), myModel.lastname());

    auto ok =false;
    auto id = proxy.property("id").toULongLong(&ok);

    CHECK(ok);
    CHECK_EQ(id, myModel.id());
}

TEST_CASE("Set properties test") {
    MyModelQObjectProxy proxy;
    uint64_t id = 999;
    std::string firstname = "MyTest2FirstName";
    std::string lastname = "MyTest2LastName";
    proxy.setProperty("id", QVariant::fromValue(id));
    proxy.setProperty("firstname", QString::fromStdString(firstname));
    proxy.setProperty("lastname", QString::fromStdString(lastname));

    MyModelClass myModel = proxy.myModel();

    CHECK_EQ(myModel.id(), id);
    CHECK_EQ(myModel.firstname(), firstname);
    CHECK_EQ(myModel.lastname(), lastname);

}

