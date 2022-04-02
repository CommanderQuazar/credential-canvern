//
// Created by Tobey Ragain on 2/20/22.
//

#include "../include/SessionLog.h"

/*
 * Pushes a new login entry to the mysql db
 */
unsigned int SessionLog::push_login()
{
    return 0;
}

/*
 * Clears ALL entries from the table
 */
unsigned int SessionLog::clear_logins()
{
    return 0;
}

/*
 * Returns a session_log_t that holds ALL login entries
 * to the user's account (time) & (ip address)
 */
session_log_t SessionLog::pull_logins()
{


}
