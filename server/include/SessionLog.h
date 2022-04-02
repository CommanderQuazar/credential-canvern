//
// Created by Tobey Ragain on 2/20/22.
//
// Session log tracks when a user logs into
// their account and allows them to view the ip
// and date from which the login originated from
//

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_SESSIONLOG_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_SESSIONLOG_H_

#include "../include/SqlConnector.h"
#include "../include/User.h"
#include <map>

typedef std::map<std::string, std::string> session_log_t;

class SessionLog
{
    public:
        SessionLog() = delete;
        SessionLog(SqlConnector * connection, target_user_t user_table_id) :
            _server(connection),
            _user_id(user_table_id)
            { };

        unsigned int    push_login();
        unsigned int    clear_logins();
        session_log_t   pull_logins();

        ~SessionLog() = default;

    private:
        target_user_t   _user_id;
        SqlConnector *  _server;
};


#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_SESSIONLOG_H_
