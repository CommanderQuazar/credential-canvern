create table UserConfig
(
    user_config_id    int auto_increment
        primary key,
    enable_encryption tinyint                                              default 1      not null,
    logout_period     enum ('120', '300', '600', '2600', '86400', 'NEVER') default '600'  not null,
    theme_color       enum ('blue', 'green', 'red', 'purple')              default 'blue' not null,
    user_fk           int                                                                 null,
    constraint UserConfig_Users_user_id_fk
        foreign key (user_fk) references Users (user_id)
);

create index UserConfig_user_config_id_index
    on UserConfig (user_config_id);

