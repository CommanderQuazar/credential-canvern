//
// Created by Tobey Ragain on 3/1/22.
//
// NOTE: Credential verification calls to the ui logic
// see mysql_get_credentials()
//

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_USERACCOUNT_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_USERACCOUNT_H_

#include "SqlConnector.h"
#include "User.h"

typedef struct
{
    std::string _usern;
    std::string _passph;
} credential_t;

class UserAccount
{
    public:
        UserAccount() = delete;
        UserAccount(const SqlConnector * my_sql_connection, target_user_t user_table_id,
                    std::string org_passph) :
            _server(my_sql_connection),
            _curr_passph(org_passph),
            _user_id(user_table_id)
            { };

        bool                    reset_umane(const std::string& new_usern);
        bool                    reset_pass(const std::string& new_passph);
        credential_t            mysql_get_credentials();
        inline UserAccount&     reset_curr_passph(const std::string& new_curr)
                                { _curr_passph = new_curr; return *this; };
        void                    remove();

    private:
        std::string             _curr_passph;
        target_user_t           _user_id;
        const SqlConnector *    _server;


};

#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_USERACCOUNT_H_
