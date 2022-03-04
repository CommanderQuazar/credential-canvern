//
// Created by Tobey Ragain on 3/3/22.
//

#include "../include/UserConfig.h"

/*
 * Gets all of the user configurations from the database
 */
configurations_t UserConfig::pull_configs()
{
    std::string query ("SELECT * FROM UserConfig WHERE user_fk= '" + _user_id + "'");
    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not find a valid config row");
        return {._f_valid = false};
    }

    MYSQL_RES * mysqlResult = mysql_store_result(_server->connection());
    MYSQL_ROW userConfigRow = mysql_fetch_row(mysqlResult);

    return { userConfigRow[1], userConfigRow[2], userConfigRow[3], true};
}

/*
 * Pushes a new logout period to the database
 */
UserConfig &UserConfig::push_logout_period(std::string period)
{

}

/*
 * Pushes a new GUI theme to the database
 */
UserConfig &UserConfig::push_theme(std::string theme_color)
{

}

/*
 * Changes whether the user would like to encrypt server-side data
 */
UserConfig &UserConfig::toggle_encryption()
{

}

/*
 * Creates a default user config row in the table.
 * Defaults:
 * * Encryption is active
 * * Logout period is every 10 min
 * * Theme color is blue
 */
UserConfig &UserConfig::init_configs()
{
    // Check if user already has a config row
}
