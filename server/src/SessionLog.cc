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

    // Get the user's ip


    // Push data to mysql table
}

/*
 * Clears ALL entries from the table
 */
unsigned int SessionLog::clear_logins()
{
    return 0;
}

/*
 * Returns a session_log_t that holds ALL login entries
 * to the user's account (time) & (ip address)
 */
session_log_t SessionLog::pull_logins()
{


}