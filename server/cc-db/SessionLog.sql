create table SessionLog
(
    session_log_id  int auto_increment
        primary key,
    hostname        varchar(32)                     not null,
    logged_ip       varchar(32) default '127.0.0.1' not null,
    logged_datetime datetime                        not null,
    user_fk         int                             not null,
    constraint SessionLog_Users_user_id_fk
        foreign key (user_fk) references Users (user_id)
);

create index SessionLog_session_log_id_index
    on SessionLog (session_log_id);

