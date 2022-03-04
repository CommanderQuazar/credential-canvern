//
// Created by Tobey Ragain on 3/1/22.
//

#include "../include/UserAccount.h"

/*
 * If the entered user credentials are confirmed the new username
 * will be updated in the user's account.
 *
 * If _u_table_id is equal to zero, it means the
 */
unsigned int UserAccount::reset_usern(const std::string& new_usern)
{
    // Check if new username already exists
    std::string query ("SELECT * FROM Users WHERE usern= '" + new_usern + "'");
    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not pull an id search");
        return EXIT_FAILURE;
    }

    MYSQL_RES * mysqlResult = mysql_store_result(_server->connection());
    if(mysql_num_rows(mysqlResult) != 0)
    {
        _server->log("FAILED: Unsuccessful change of username: "
                     "username already exists in this database");
        return EXIT_FAILURE;
    }

    query = "UPDATE Users SET usern= '" + new_usern + "' WHERE user_id= '" + _user_id + "'";
    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not push the username to: " + new_usern);
        return false;
    }
    _server->log("User '" + _user_id + "' username has been updated to: " + new_usern);
    return EXIT_SUCCESS;
}

/*
 * If the entered user credentials are confirmed the new password
 * will be updated in the user's account.
 */
unsigned int UserAccount::reset_pass(const std::string& new_passph)
{
    std::string query ("UPDATE Users SET passph= '" + new_passph + "' WHERE user_id= '" + _user_id + "'");
    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not push the new password");
        return EXIT_FAILURE;
    }
    _server->log("User '" + _user_id + "' password has been updated");
    return EXIT_SUCCESS;
}

/*
 * Torches all data in user's account and removes it from
 * the user table.
 */
inline unsigned int UserAccount::remove()
{
    std::string query ("DELETE FROM Users Favorites Records SessionLog UserConfig "
                       "WHERE user_id= '" + _user_id + "'");
    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could send a touch request");
        return EXIT_FAILURE;
    }
    _server->log("Torched user '" + _user_id + "' account");
    return EXIT_SUCCESS;
}

/*
 * Gets the user's login credentials.
 * If _u_table_id is zero, the contents of the pair will be
 * empty and the flag will be set to false. Otherwise the
 * data will be returned and the flag will be set to true.
 */
credential_t UserAccount::pull_credentials()
{
    // Check if user id exists
    std::string query ("SELECT * FROM Users WHERE user_id= '" + _user_id + "'");
    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not pull a user account with id: " + _user_id);
        return {"", "", false};
    }

    MYSQL_RES * mysqlResult = mysql_store_result(_server->connection());
    MYSQL_ROW userAccount = mysql_fetch_row(mysqlResult);

    if(mysql_num_rows(mysqlResult) == 0)
    {
        _server->log("SERVER ERROR: Could not find a user account with id: " + _user_id);
        return {"", "", false};
    }

    std::string usern (userAccount[USERN]);
    _server->log("Credentials for user '" + usern + "' sent");
    return {usern, userAccount[PASSPH], true};
}