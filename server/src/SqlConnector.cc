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

std::string SqlConnector::get_curr_time_date(const std::string& s)
{
    time_t now = time(nullptr);
    struct tm  timeStruct { };
    char  buf[80];
    timeStruct = * localtime(&now);
    if(s == "now")
    {
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &timeStruct);
    }
    else if(s == "date")
    {
        strftime(buf, sizeof(buf), "%Y-%m-%d", &timeStruct);
    }
    return {buf};
}

/*
 * Logs MySQL actions to a provided log file throughout the library
 */
SqlConnector &SqlConnector::log(const std::string& msg)
{
    std::string filePath = _logfile_location;
    std::string now = get_curr_time_date("now");
    std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app );
    ofs << now << '\t' << msg << '\n';
    ofs.close();
    return *this;
}

