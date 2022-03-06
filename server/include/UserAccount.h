//
// Created by Tobey Ragain on 3/1/22.
//
// NOTE: Credential verification calls to the ui logic
// see mysql_get_credentials()
//

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_USERACCOUNT_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_USERACCOUNT_H_

#include <utility>

#include "SqlConnector.h"
#include "User.h"

typedef struct
{
    std::string     _usern;
    std::string     _passph;
    bool            _f_valid;
} credential_t;

class UserAccount
{
    public:
        UserAccount() = delete;
        UserAccount(SqlConnector * my_sql_connection, target_user_t user_table_id) :
            _server(my_sql_connection),
            _user_id(std::move(user_table_id))
            { };

        unsigned int            reset_usern(const std::string& new_usern);
        unsigned int            reset_pass(const std::string& new_passph);
        credential_t            pull_credentials();
        inline unsigned int     remove();

        ~UserAccount() = default;

    private:
        target_user_t     _user_id;
        SqlConnector *    _server;
};

#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_USERACCOUNT_H_
