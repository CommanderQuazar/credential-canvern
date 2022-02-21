cmake_minimum_required(VERSION 3.20)
project(credential-cavern)

include_directories(/usr/local/Cellar/mysql/8.0.28/include)
include_directories(/usr/local/Cellar/mysql/8.0.28/lib)
add_link_options(/usr/local/Cellar/mysql/8.0.28/lib/libmysqlclient.21.dylib)

set(CMAKE_CXX_STANDARD 23)

add_executable(credential-cavern src/SQLConnector.cpp src/User.cpp include/User.h src/Favorites.cpp
        include/Favorites.h src/SessionLog.cpp include/SessionLog.h src/Records.cpp include/Records.h
        src/RecordItem.cpp include/RecordItem.h src/tester.cpp)
