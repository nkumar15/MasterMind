#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

/* Types of color present in system */
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

/* Type of peg */
enum class PegType
{
    CODE = 0,
    FEEDBACK,
};

#endif // TYPES_H_INCLUDED
