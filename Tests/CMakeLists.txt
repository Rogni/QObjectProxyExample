project(QObjectPropertyExampleTests)

add_subdirectory(ThirdParty/doctest)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (TESTS
    ProxyTests.cpp
    )

set (UsedQtComponents Core)

find_package(Qt5 COMPONENTS
    ${UsedQtComponents}
    REQUIRED)

function(MakeTests File)


    get_filename_component(Filename ${File} NAME_WE)

    set (TestName ${PROJECT_NAME}_${Filename})

    add_executable(${TestName} ${File})
    add_definitions(-DDOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
    qt5_use_modules(${TestName} ${UsedQtComponents})
    target_link_libraries(${TestName} doctest QObjectProxyExample)
    add_test(${TestName} ${TestName})
endfunction(MakeTests)

foreach(TestFile ${TESTS})
    MakeTests(${TestFile})
endforeach(TestFile)
