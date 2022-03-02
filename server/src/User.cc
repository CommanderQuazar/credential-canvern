//
// Created by Tobey Ragain on 2/20/22.
//

#include "../include/User.h"

/*
 * Creates a new user entry in the User table.
 */
bool User::create()
{
    MYSQL_RES * result;
    std::string query = "SELECT usern FROM User WHERE usern= '" + _entry_usern + "'";

    auto command = [] (std::string q) -> bool 
        { return mysql_query(_server->connection(), q.c_str()); };

    if(!command(query))
    {
        // TODO log error and return
        return false;
    }
    // Check if entered username already exists
    result = mysql_store_result(_server->connection());
    if(mysql_num_rows(result) != 0)
    {
        // TODO log and return
        return false;
    }
    else
    {
        // Add a user row with the provided entries
        query = "INSERT INTO User (usern, passph) VALUES "
                "('" + _entry_usern + "'" + _entry_passph + "')";
        if(!command(query))
        {
            // TODO log error and return
            return false;
        }
        return true;
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
    // Search usernames for entered

    // If username found, check password
}



