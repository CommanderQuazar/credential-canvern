//
// Created by Tobey Ragain on 2/20/22.
//

#include "../include/User.h"

/*
 * Creates a new user entry in the User table.
 */
User &User::create()
{
    return <#initializer#>;
}

/*
 * With the supplied username and passphrase this functions attempts
 * to login into a user account. If successful, login() will update
 * the _u_table_id data member with the table id of the user account.
 * If authentication is unsuccessful the value will be left at zero.
 */
User &User::login()
{
    return <#initializer#>;
}

/*
 * Gets the user's login credentials - primarily used by UserAccount class.
 * If _u_table_id is zero, the contents of the Credential struct will be
 * empty. Otherwise the data will be returned
 */
Credentials &User::mysql_get_credentials()
{

}


