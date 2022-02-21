//
// Created by Tobey Ragain on 2/20/22.
//

#include "../include/SQLConnector.h"

/*
 * Connect to your MySQL database
 */
SQLConnector& SQLConnector::connect()
{
    mysql_init(&mysql);
    mysql_real_connect(&mysql,
                       host->c_str(),
                       user->c_str(),
                       passwd->c_str(),
                       db->c_str(),
                       port,
                       (unix_socket == nullptr ? nullptr : unix_socket->c_str()),
                       client_flag);
    return *this;
}

/*
 * Closes the connection to MySQL database
 * The deconstrcutor will typically follow a call to this function
 */
SQLConnector &SQLConnector::disconnect()
{
    mysql_close(&mysql);
    return *this;
}

