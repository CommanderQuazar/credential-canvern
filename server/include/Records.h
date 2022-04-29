//
// Created by Tobey Ragain on 2/20/22.
//

#ifndef CREDENTIAL_CAVERN_SERVER_INCLUDE_RECORDS_H_
#define CREDENTIAL_CAVERN_SERVER_INCLUDE_RECORDS_H_


#include "SqlConnector.h"
#include "../include/User.h"
#include <map>

enum recd_e {PASSWORD, BANK_ACCOUNT, PAYMENT_CARD, DATABASE_LOGIN, SSH_KEYS, SOFTWARE_LICENSE};

typedef struct
{
    recd_e      type;
    std::string create_date;
    //more data

}record_s;

typedef std::map<std::string, record_s> record_t;

class Records
{
    public:
        Records() = delete;
        Records(SqlConnector * connection, target_user_t u_id) :
            _user_id(u_id),
            _server(connection)
            { };

        unsigned int add_record();
        unsigned int remove_record();

        record_t sql_get_all_records();
        record_t sql_get_searched(const std::string& search_quary);

        unsigned int sort_by_date();
        unsigned int sort_by_type();
        unsigned int sort_by_name();



    private:
        target_user_t _user_id;
        SqlConnector * _server;

};


#endif //CREDENTIAL_CAVERN_SERVER_INCLUDE_RECORDS_H_
