//
// Created by Tobey Ragain on 2/20/22.
//

#ifndef CREDENTIAL_CANVERN_SQLCONNECTOR_H
#define CREDENTIAL_CANVERN_SQLCONNECTOR_H

#include <mysql/mysql.h>

#include <iostream>

class SQLConnector
{
    public:
        SQLConnector(std::string *  host_name,
                     std::string *  user_name,
                     std::string *  password,
                     std::string *  database,
                     unsigned int   port_number,
                     std::string *  unix_socket_number = nullptr,
                     unsigned long  client_f = 0) :
                     host           (host_name),
                     user           (user_name),
                     passwd         (password),
                     db             (database),
                     port           (port_number),
                     unix_socket    (unix_socket_number),
                     client_flag    (client_f)
                     { };

        SQLConnector&       connect();
        inline std::string  stats() { return mysql_stat(&mysql); };
        inline bool         status() { return mysql_ping(&mysql); };
        SQLConnector&       disconnect();

        ~SQLConnector() = default;

    protected:
        MYSQL mysql {};

    private:
        std::string *   host;
        std::string *   user;
        std::string *   passwd;
        std::string *   db;
        unsigned int    port;
        std::string *   unix_socket;
        unsigned long   client_flag;
};


#endif //CREDENTIAL_CANVERN_SQLCONNECTOR_H
