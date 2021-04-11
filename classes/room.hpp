#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED


class Room {
    protected:
        char** content;
        //lista nemici?

    public:
        void generateRoom();
        char** getContent();

};

#endif