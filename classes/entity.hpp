class Entity
{
    private:
        int x, y; //famo la struct
        char sprite;

    public:
        Entity(char sprite);
        Entity(int x, int y, char sprite);
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        void dead();

};

