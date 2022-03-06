cmake_minimum_required(VERSION 3.20)
project(credential-cavern)
set(CMAKE_CXX_STANDARD 23)

include_directories(/usr/local/Cellar/mysql/8.0.28_1/include)
include_directories(/usr/local/Cellar/mysql/8.0.28_1/lib)
add_link_options(/usr/local/Cellar/mysql/8.0.28_1/lib/libmysqlclient.21.dylib)

set(CMAKE_CXX_COMPILER_ID "GNU")
set(CMAKE_CXX_COMPILER_VERSION "4.6.3")

add_executable(credential-cavern include/SqlConnector.h src/SqlConnector.cc src/User.cc include/User.h
        src/Favorites.cc include/Favorites.h src/SessionLog.cc include/SessionLog.h src/Records.cc
        include/Records.h include/UserAccount.h src/UserAccount.cc test/tester.cc src/UserConfig.cc include/UserConfig.h test/tester.cc)

add_library(connectionlib SHARED src/User.cc src/Favorites.cc src/SessionLog.cc
        src/Records.cc src/SqlConnector.cc src/UserAccount.cc include/UserAccount.h src/UserConfig.cc include/UserConfig.h)