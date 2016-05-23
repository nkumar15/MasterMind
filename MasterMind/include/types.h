#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED


enum class PegColor : int
{
    RED = 0,
    BLUE,
    YELLOW,
    GREEN,
    WHITE,
    BLACK,
    EMPTY,

};

enum class PegType
{
    CODE = 0,
    FEEDBACK,
};

enum class GameState
{
    READY=0,
    PLAYING,
    STOPPED
};

#endif // TYPES_H_INCLUDED
