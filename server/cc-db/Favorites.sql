create table Favorites
(
    favorites_id int auto_increment
        primary key,
    record_fk    int not null,
    user_fk      int not null,
    constraint Favorites_Records_record_id_fk
        foreign key (record_fk) references Records (record_id),
    constraint Favorites_Users_user_id_fk
        foreign key (user_fk) references Users (user_id)
);

