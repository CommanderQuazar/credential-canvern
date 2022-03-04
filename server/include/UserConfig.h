//
// Created by Tobey Ragain on 3/3/22.
//
// Each user will have ONE row in the database's
// table to store their configurations
//

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_USERCONFIG_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_USERCONFIG_H_

#include "SqlConnector.h"
#include "User.h"

#define BLUE            0
#define GREEN           1
#define RED             2
#define PURPLE          3

#define TWO_MIN         0
#define FIVE_MIN        1
#define TEN_MIN         2
#define FORTY_FIVE_MIN  3
#define ONE_DAY         4
#define NEVER           5

// These types and the defines above are solely for
// the purposes of readability and data accuracy

static std::string logouts[6] = {"120", "300", "600", "2600", "86400", "never"};
static std::string themes[4] = {"blue", "green", "red", "purple"};

typedef struct
{
    bool            _encryption_enabled;
    std::string     _logout_time;
    std::string     _account_theme;
    bool            _f_valid;
} configurations_t;

class UserConfig
{
    public:
        UserConfig() = delete;
        UserConfig(SqlConnector * connection, target_user_t user_table_id) :
           _user_id(user_table_id),
           _server(connection)
           { };

        inline configurations_t pull_configs();
        unsigned int            init_configs();
        unsigned int            push_logout_period(std::string period);
        unsigned int            push_theme(std::string theme_color);
        unsigned int            toggle_encryption();


    private:
        target_user_t       _user_id;
        SqlConnector *      _server;

};

#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_USERCONFIG_H_
