//
// Created by Tobey Ragain on 3/3/22.
//

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_USERCONFIG_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_USERCONFIG_H_

#include "SqlConnector.h"
#include "User.h"

#include <iostream>

enum logout_period_e {TWO_MIN, FIVE_MIN, TEN_MIN, FORTY_FIVE_MIN, ONE_DAY, NEVER};
enum theme_color_e {BLUE, GREEN, RED, PURPLE};

class UserConfig
{
    public:
        UserConfig() = delete;
        UserConfig(SqlConnector * connection, target_user_t user_table_id,
                   logout_period_e logout, theme_color_e color, bool encrypt) :
           _user_id(user_table_id),
           _server(connection),
           _encryption_enabled(encrypt),
           _logout_time(logout),
           _account_theme(color)
            { };

    private:
        target_user_t   _user_id;
        bool            _encryption_enabled;
        logout_period_e _logout_time;
        theme_color_e   _account_theme;
        SqlConnector *  _server;

};

#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_USERCONFIG_H_
