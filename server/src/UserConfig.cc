//
// Created by Tobey Ragain on 3/3/22.
//

#include "../include/UserConfig.h"

/*
 * Creates a default user config row in the table.
 * Defaults:
 * * Encryption is active
 * * Logout period is every 10 min
 * * Theme color is blue
 */
unsigned int UserConfig::init_configs()
{
    // Check if user already has a config row
    std::string query ("SELECT user_fk FROM UserConfig WHERE user_fk= '" + _user_id + "'");

    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not pull an id search");
        return EXIT_FAILURE;
    }

    MYSQL_RES * mysqlResult = mysql_store_result(_server->connection());
    if(mysql_num_rows(mysqlResult) > 1)
    {
        _server->log("FAILED: User '" + _user_id + "' already exists");
        return EXIT_FAILURE;
    }

    // Inits with default account values
    query = "INSERT INTO UserConfig (enable_encryption, logout_period, "
            "theme_color, user_fk) VALUES (1, '300', 'blue', " + _user_id + ")";

    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("SERVER ERROR: Could not push a config row for user: " + _user_id);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

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
unsigned int UserConfig::push_logout_period(std::string period)
{
    std::string query ("UPDATE UserConfig SET logout_period = "
                       "'" + period + "' WHERE user_fk= '" + _user_id + "'");

    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("Failed to push a new logout period");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/*
 * Pushes a new GUI theme to the database
 */
unsigned int UserConfig::push_theme(std::string theme_color)
{
    std::string query ("UPDATE UserConfig SET theme_color = "
                       "'" + theme_color + "' WHERE user_fk= '" + _user_id + "'");

    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("Failed to push a new theme");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/*
 * Changes whether the user would like to encrypt server-side data
 */
unsigned int UserConfig::toggle_encryption()
{
    std::string query ("UPDATE UserConfig SET enable_encryption = "
                       "NOT boolean_field WHERE user_fk= '" + _user_id + "'");

    if(mysql_query(_server->connection(), query.c_str()))
    {
        _server->log("Failed to push a toggle on the encryption for user");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

