//
// Created by Tobey Ragain on 2/20/22.
//

#include "../include/SessionLog.h"

/*
 * Returns hostname for the local computer
 */
void check_host_name(int hostname)
{
    if (hostname == -1)
    {
        perror("gethostname");
        exit(1);
    }
}

/*
 * Returns host information corresponding to host name
 */
void check_host_entry(struct hostent * hostentry)
{
    if (hostentry == nullptr)
    {
        perror("gethostbyname");
        exit(1);
    }
}

/*
 * Converts space-delimited IPv4 addresses
 * to dotted-decimal format
 */
void check_i_pbuffer(const char *ip_buffer)
{
    if (nullptr == ip_buffer)
    {
        perror("inet_ntoa");
        exit(1);
    }
}

/*
 * convert IP string to dotted decimal format
 */
host_t SessionLog::get_host_info()
{
    char hostbuffer[256];

    // To retrieve hostname
    int hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    check_host_name(hostname);

    // To retrieve host information
    struct hostent *hostEntry = gethostbyname(hostbuffer);
    check_host_entry(hostEntry);

    // To convert an Internet network
    // address into ASCII string
    char * iPbuffer = inet_ntoa(*((struct in_addr*)
        hostEntry->h_addr_list[0]));

    return {hostbuffer, iPbuffer};
}

/*
 * Pushes a new login entry to the mysql db
 */
unsigned int SessionLog::push_login()
{
    // Checks to see of user id exists
    std::string query ("SELECT * FROM Users WHERE user_id= '" + _user_id + "'");
    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not pull a user account with id: " + _user_id);
        return EXIT_FAILURE;
    }

    // Get the user's ip and host name
    host_t host_info = get_host_info();

    // Push data to mysql table
    query = "INSERT INTO SessionLog (host_name, logged_ip, logged_datetime) VALUES (" + host_info.first + ", "
            + host_info.second + ")";
    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not push the session to the table");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/*
 * Clears ALL entries from the table
 */
unsigned int SessionLog::clear_logins()
{
    std::string query ("REMOVE * FROM SessionLog");

    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not clear logged sessions");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/*
 * Returns a session_log_t that holds ALL login entries
 * to the user's account (time) & (ip address)
 */
session_log_t SessionLog::pull_logins()
{
    session_log_t logons;
    std::string query ("SELECT * FROM SessionLog");
    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not find a valid session logs");
        return logons;
    }

    MYSQL_RES * mysqlResult = mysql_store_result(_server->connection());
    MYSQL_ROW userConfigRow;

    // Read the all rows into the map
    while((userConfigRow = mysql_fetch_row(mysqlResult)))
    {
        logons[userConfigRow[TIME_DATE]] = {userConfigRow[HOST], userConfigRow[IP]};
    }
    return logons;
}