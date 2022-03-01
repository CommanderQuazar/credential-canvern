//
// Created by Tobey Ragain on 2/20/22.
//

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_USER_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_USER_H_

#include "SqlConnector.h"

typedef struct Credentials
{
    std::string passphrase;
    std::string password;
};

class User
{
    public:
        User() = delete;
        User(SqlConnector * my_sql_connection, std::string username_entry,
             std::string passph_entry) :
            _server(my_sql_connection),
            _entry_usern(std::move(username_entry)),
            _entry_passph(std::move(passph_entry))
            { };

        User&           create();
        User&           login();
        unsigned int    get_user_id() const { return _u_table_id; };

        ~User() = default;

    protected:
        User(std::string username_entry,
             std::string passph_entry) :
            _entry_usern(std::move(username_entry)),
            _entry_passph(std::move(passph_entry))
            { };
        Credentials& mysql_get_credentials();

        //Stores the table ID of the logged in user
        unsigned int _u_table_id {0};
        std::string _entry_usern;
        std::string _entry_passph;

    private:
        SqlConnector * _server;

};


#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_USER_H_
