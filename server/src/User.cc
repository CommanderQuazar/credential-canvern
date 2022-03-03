//
// Created by Tobey Ragain on 2/20/22.
//

#include "../include/User.h"

/*
 * Creates a new user entry in the User table.
 */
creation_status_e User::create()
{
    MYSQL_RES * mysqlResult;
    std::string query = "SELECT usern FROM User WHERE usern= '" + _entry_usern + "'";

    if(!_command(query))
    {
        _server->log("ERROR: Selecting from User table failed");
        return SERVER_FAULT;
    }
    // Check if entered username already exists
    mysqlResult = mysql_store_result(_server->connection());
    if(mysql_num_rows(mysqlResult) != 0)
    {
        _server->log("FAILED: Unsuccessful creation of user: "
                     "username already exists in this database");
        return BAD_USERN;
    }
    else
    {
        // Add a user row with the provided entries
        query = "INSERT INTO User (usern, passph) VALUES "
                "('" + _entry_usern + "'" + _entry_passph + "')";
        if(!_command(query))
        {
            _server->log("ERROR: Inserting a new user into the User table has failed");
            return SERVER_FAULT;
        }
        return SUCCESS;
    }
}

/*
 * With the supplied username and passphrase this functions attempts
 * to login into a user account. If successful, login() will update
 * the _u_table_id data member with the table id of the user account.
 * If authentication is unsuccessful the value will be left at zero.
 */
User& User::login()
{
    MYSQL_RES * mysqlResult;
    std::string query = "SELECT * FROM Users WHERE passph= '" + _entry_passph +
        "' AND usern= '" + _entry_passph + "'";

    // Check if usern and passph exists
    // User creation verifies that no repeat usern are added
    if(!_command(query))
    {
        _server->log("ERROR: Selecting passph User table failed");
        return *this;
    }
    mysqlResult = mysql_store_result(_server->connection());
    if(mysql_num_rows(mysqlResult) == 0)
    {
        _server->log("FAILED: No user found with provided username or password");
        return *this;
    }

    // Get the id of the user account
    MYSQL_ROW row = mysql_fetch_row(mysqlResult);
    _u_table_id = atoi(row[0]);
    return *this;
}



