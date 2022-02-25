//
// Created by Tobey Ragain on 2/20/22.
//

/*
 * This file contains the interface to the SqlConnector class.
 * This header must be bound either to connectionlib.dylib (MacOS) or
 * the scr must be recompiled into a lib for your target machine.
 *
 * This class allows the _user to connect to a MySQL database, get
 * the running status, retrieve server stat info, and disconnect.
 */

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_SQLCONNECTOR_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_SQLCONNECTOR_H_

#include <mysql/mysql.h>

#include <iostream>

class SqlConnector
{
    public:
        SqlConnector(std::string *  host_name,
                     std::string *  user_name,
                     std::string *  password,
                     std::string *  database,
                     unsigned int   port_number,
                     std::string *  unix_socket_number = nullptr,
                     unsigned long  client_f = 0) :
            _host           (host_name),
            _user           (user_name),
            _passwd         (password),
            _db             (database),
            _port           (port_number),
            _unix_socket    (unix_socket_number),
            _client_flag    (client_f)
            { };

        SqlConnector&       connect();
        inline std::string  stats() { return mysql_stat(&_mysql); };
        inline bool         status() { return mysql_ping(&_mysql); };
        SqlConnector&       disconnect();

        ~SqlConnector() = default;

    protected:
        MYSQL _mysql {};

    private:
        std::string *   _host;
        std::string *   _user;
        std::string *   _passwd;
        std::string *   _db;
        unsigned int    _port;
        std::string *   _unix_socket;
        unsigned long   _client_flag;
};


#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_SQLCONNECTOR_H_
