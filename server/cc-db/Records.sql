create table Records
(
    record_id           int auto_increment
        primary key,
    name                varchar(32)                              not null,
    date                datetime                                 not null,
    type                enum ('LOGIN', 'SSH', 'NOTE', 'PAYMENT') not null,
    usern               varchar(128)  default ''                 null,
    passph              varchar(256)  default ''                 null,
    ssh_private_key     varchar(1024) default ''                 null,
    ssh_public_key      varchar(1024) default ''                 null,
    payment_card_number int                                      null,
    payment_card_exp    varchar(4)    default ''                 null,
    payment_card_cvv    int                                      null,
    payment_card_pin    int                                      null,
    payment_card_name   varchar(64)   default ''                 null,
    note                varchar(2048) default ''                 null,
    user_fk             int                                      not null,
    constraint Records_Users_user_id_fk
        foreign key (user_fk) references Users (user_id)
);

create index Records_record_id_index
    on Records (record_id);

