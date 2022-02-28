//
// Created by Tobey Ragain on 2/20/22.
//

#include "../include/SqlConnector.h"

/*
 * Connect to your MySQL database
 */
SqlConnector& SqlConnector::connect()
{
    mysql_init(&_mysql);
    mysql_real_connect(&_mysql,
                       _host    ->c_str(),
                       _user    ->c_str(),
                       _passwd  ->c_str(),
                       _db      ->c_str(),
                       _port,
                       _unix_socket == nullptr ? nullptr : _unix_socket->c_str(),
                       _client_flag);
    return *this;
}

/*
 * Closes the connection to MySQL database
 * The destructor will typically follow a call to this function
 */
SqlConnector &SqlConnector::disconnect()
{
    mysql_close(&_mysql);
    return *this;
}

