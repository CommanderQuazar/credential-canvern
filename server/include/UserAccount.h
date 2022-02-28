//
// Created by Tobey Ragain on 2/27/22.
//

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_USERACCOUNT_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_USERACCOUNT_H_

#include "User.h"

class UserAccount : User
{
    using User::_u_table_id;
    using User::_entry_usern;
    using User::_entry_passph;

    public:
        UserAccount() = delete;
        UserAccount(const std::string or_usern, const std::string or_passph) :
            User(or_usern, or_passph)
            { };

        UserAccount& reset_umane(const std::string& new_usern);
        UserAccount& reset_pass(const std::string& new_passph);
        void remove();

};

#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_USERACCOUNT_H_
