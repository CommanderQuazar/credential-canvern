//
// Created by Tobey Ragain on 2/20/22.
//

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_USER_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_USER_H_

#include <SqlConnector.h>
#include "SqlConnector.h"

#include <utility>

class User
{
    public:
        User()= delete;
        User(SqlConnector * my_sql_connection, std::string username_entry,
             std::string passph_entry) :
            _connection(my_sql_connection),
            _entry_user_n(std::move(username_entry)),
            _entry_pass_ph(std::move(passph_entry))
            { };

        User& create();

        //DEV NOTE: This must get a user table to operate on once logged in
        User& login();


    protected:


    private:
        SqlConnector * _connection;
        std::string _entry_user_n;
        std::string _entry_pass_ph;
        unsigned int _u_id {};
};


#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_USER_H_
