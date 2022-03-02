//
// Created by Tobey Ragain on 3/1/22.
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
        UserAccount(target_user_t user_table_id, std::string org_passph) :
            _og_passph(org_passph),
            _user_id(user_table_id)
            { };

        bool            reset_umane(const std::string& new_usern);
        bool            reset_pass(const std::string& new_passph);
        void            remove();
        credential_t    mysql_get_credentials();

    private:
        std::string             _og_passph;
        target_user_t           _user_id;
        const SqlConnector *    _server;


};

#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_USERACCOUNT_H_
