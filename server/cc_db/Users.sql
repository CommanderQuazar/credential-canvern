create table Users
(
    user_id int auto_increment
        primary key,
    usern   varchar(64)  not null,
    passph  varchar(128) not null
);

