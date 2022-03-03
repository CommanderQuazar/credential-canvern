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
bool UserAccount::reset_umane(const std::string& new_passph)
{

}

/*
 * If the entered user credentials are confirmed the new password
 * will be updated in the user's account.
 */
bool UserAccount::reset_pass(const std::string& new_passph)
{

}

/*
 * Torches all data in user's account and removes it from
 * the user table.
 */
void UserAccount::remove()
{

}

/*
 * Gets the user's login credentials.
 * If _u_table_id is zero, the contents of the pair will be
 * empty and the flag will be set to false. Otherwise the
 * data will be returned and the flag will be set to true.
 */
credential_t UserAccount::mysql_get_credentials()
{
    std::string query = "SELECT * FROM Users WHERE id= '" + _user_id + "'";
    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("ERROR: Could not find a user account with id: " + _user_id);
        return {"", "", false};
    }

    MYSQL_RES * mysqlResult = mysql_store_result(_server->connection());
    MYSQL_ROW userAccount = mysql_fetch_row(mysqlResult);

    return {userAccount[1], userAccount[2], true};
}