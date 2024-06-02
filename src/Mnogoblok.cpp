#include "bloki.h"
#include "posicii.h"

class L : public gBlock
{
public:
    L()
    {
        id = 1;
        kletki[0] = {Posicii(0, 2), Posicii(1, 0), Posicii(1, 1), Posicii(1, 2)};
        kletki[1] = {Posicii(0, 1), Posicii(1, 1), Posicii(2, 1), Posicii(2, 2)};
        kletki[2] = {Posicii(1, 0), Posicii(1, 1), Posicii(1, 2), Posicii(2, 0)};
        kletki[3] = {Posicii(0, 0), Posicii(0, 1), Posicii(1, 1), Posicii(2, 1)};
        Move(0, 3);
    }
};

class J : public gBlock
{
public:
    J()
    {
        id = 2;
        kletki[0] = {Posicii(0, 0), Posicii(1, 0), Posicii(1, 1), Posicii(1, 2)};
        kletki[1] = {Posicii(0, 1), Posicii(0, 2), Posicii(1, 1), Posicii(2, 1)};
        kletki[2] = {Posicii(1, 0), Posicii(1, 1), Posicii(1, 2), Posicii(2, 2)};
        kletki[3] = {Posicii(0, 1), Posicii(1, 1), Posicii(2, 0), Posicii(2, 1)};
        Move(0, 3);
    }
};

class I : public gBlock
{
public:
    I()
    {
        id = 3;
        kletki[0] = {Posicii(1, 0), Posicii(1, 1), Posicii(1, 2), Posicii(1, 3)};
        kletki[1] = {Posicii(0, 2), Posicii(1, 2), Posicii(2, 2), Posicii(3, 2)};
        kletki[2] = {Posicii(2, 0), Posicii(2, 1), Posicii(2, 2), Posicii(2, 3)};
        kletki[3] = {Posicii(0, 1), Posicii(1, 1), Posicii(2, 1), Posicii(3, 1)};
        Move(-1, 3);
    }
};

class O : public gBlock
{
public:
    O()
    {
        id = 4;
        kletki[0] = {Posicii(0, 0), Posicii(0, 1), Posicii(1, 0), Posicii(1, 1)};
        Move(0, 4);
    }
};

class S : public gBlock
{
public:
    S()
    {
        id = 5;
        kletki[0] = {Posicii(0, 1), Posicii(0, 2), Posicii(1, 0), Posicii(1, 1)};
        kletki[1] = {Posicii(0, 1), Posicii(1, 1), Posicii(1, 2), Posicii(2, 2)};
        kletki[2] = {Posicii(1, 1), Posicii(1, 2), Posicii(2, 0), Posicii(2, 1)};
        kletki[3] = {Posicii(0, 0), Posicii(1, 0), Posicii(1, 1), Posicii(2, 1)};
        Move(0, 3);
    }
};

class T : public gBlock
{
public:
    T()
    {
        id = 6;
        kletki[0] = {Posicii(0, 1), Posicii(1, 0), Posicii(1, 1), Posicii(1, 2)};
        kletki[1] = {Posicii(0, 1), Posicii(1, 1), Posicii(1, 2), Posicii(2, 1)};
        kletki[2] = {Posicii(1, 0), Posicii(1, 1), Posicii(1, 2), Posicii(2, 1)};
        kletki[3] = {Posicii(0, 1), Posicii(1, 0), Posicii(1, 1), Posicii(2, 1)};
        Move(0, 3);
    }
};

class Z : public gBlock
{
public:
    Z()
    {
        id = 7;
        kletki[0] = {Posicii(0, 0), Posicii(0, 1), Posicii(1, 1), Posicii(1, 2)};
        kletki[1] = {Posicii(0, 2), Posicii(1, 1), Posicii(1, 2), Posicii(2, 1)};
        kletki[2] = {Posicii(1, 0), Posicii(1, 1), Posicii(2, 1), Posicii(2, 2)};
        kletki[3] = {Posicii(0, 1), Posicii(1, 0), Posicii(1, 1), Posicii(2, 0)};
        Move(0, 3);
    }
};
