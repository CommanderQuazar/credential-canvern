//
// Created by Tobey Ragain on 3/3/22.
//

#include "../include/UserConfig.h"

/*
 * Gets all of the user configurations from the database
 */
configurations_t UserConfig::pull_configs()
{

}

/*
 * Pushes a new logout period to the database
 */
UserConfig &UserConfig::push_logout_period(logout_period_e period)
{

}

/*
 * Pushes a new GUI theme to the database
 */
UserConfig &UserConfig::push_theme(theme_color_e theme_color)
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
