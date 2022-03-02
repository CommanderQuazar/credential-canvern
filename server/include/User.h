//
// Created by Tobey Ragain on 2/20/22.
//
// NOTE: If _u_table_id is zero that signifies that no
// user has been logged in. If non zero a user has been
// successfully logged into their account
//

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_USER_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_USER_H_

#include "SqlConnector.h"

typedef unsigned int target_user_t;

class User
{
    public:
        User() = delete;
        User(const SqlConnector * my_sql_connection, std::string username_entry,
             std::string passph_entry) :
            _server(my_sql_connection),
            _entry_usern(std::move(username_entry)),
            _entry_passph(std::move(passph_entry))
            { };

        User&                   create();
        User&                   login();
        inline target_user_t    user_id() const { return _u_table_id; };
        inline User&            reset_entries(const std::string& usern, const std::string& passph)
                                { _entry_usern = usern; _entry_passph = passph; return *this; }
        inline User&            logout() { _u_table_id = 0; return *this; };

        ~User() = default;

    private:
        target_user_t           _u_table_id { 0 }; // Stores the table ID of the logged in user
        std::string             _entry_usern;      // User entered username
        std::string             _entry_passph;     // User entered passphrase
        const SqlConnector *    _server;
};


#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_USER_H_
