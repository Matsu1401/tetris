#include "Game.h"
#include <random>

Game::Game()
{
    setka = Setka();
    bloki = PoluchetAllBloki();
    etotBlok = RandomniBlock();
    sledBlok = RandomniBlock();
    gameover = false;
    score = 0;
}

gBlock Game::RandomniBlock()
{
    if (bloki.empty())
    {
        bloki = PoluchetAllBloki();
    }
    int ranomniindex = rand() % bloki.size();
    gBlock block = bloki[ranomniindex];
    bloki.erase(bloki.begin() + ranomniindex);
    return block;
}

std::vector<gBlock> Game::PoluchetAllBloki()
{
    return {I(), J(), L(), O(), S(), T(), Z()};
}

void Game::Risov()
{
    setka.Risov();
    etotBlok.Risov(11, 11);
    switch (sledBlok.id)
    {
    case 3:
        sledBlok.Risov(255, 290);
        break;
    case 4:
        sledBlok.Risov(255, 280);
        break;
    default:
        sledBlok.Risov(270, 270);
        break;
    }
}

void Game::Klava()
{
    int bottom = GetKeyPressed();
    if (gameover && bottom == KEY_R)
    {
        gameover = false;
        Reset();
    }
    switch (bottom)
    {
    case KEY_LEFT:
        MoveVlevo();
        break;
    case KEY_RIGHT:
        MoveVpravo();
        break;
    case KEY_DOWN:
        MoveVniz();
        ObnovitScore(0, 1);
        break;
    case KEY_UP:
        PerevernBlock();
        break;
    }
}

void Game::MoveVlevo()
{
    if (!gameover)
    {
        etotBlok.Move(0, -1);
        if (ProverkaBlokaNaVilet() || BlockVlez() == false)
        {
            etotBlok.Move(0, 1);
        }
    }
}

void Game::MoveVpravo()
{
    if (!gameover)
    {
        etotBlok.Move(0, 1);
        if (ProverkaBlokaNaVilet() || BlockVlez() == false)
        {
            etotBlok.Move(0, -1);
        }
    }
}

void Game::MoveVniz()
{
    if (!gameover)
    {
        etotBlok.Move(1, 0);
        if (ProverkaBlokaNaVilet() || BlockVlez() == false)
        {
            etotBlok.Move(-1, 0);
            Ostanovit();
        }
    }
}

bool Game::ProverkaBlokaNaVilet()
{
    std::vector<Posicii> tiles = etotBlok.PoluchPosicii();
    for (Posicii item : tiles)
    {
        if (setka.ProverkaNaVilet(item.row, item.col))
        {
            return true;
        }
    }
    return false;
}

void Game::Reset()
{
    setka.Initialaze();
    bloki = PoluchetAllBloki();
    etotBlok = RandomniBlock();
    sledBlok = RandomniBlock();
    score = 0;
}

void Game::ObnovitScore(int LinesCleared, int moveDownOchki)
{
    switch (LinesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDownOchki;
}

void Game::PerevernBlock()
{
    if (!gameover)
    {
        etotBlok.Rotate();
        if (ProverkaBlokaNaVilet() || BlockVlez() == false)
        {
            etotBlok.OtmenaRotation();
        }
    }
}

void Game::Ostanovit()
{
    std::vector<Posicii> tiles = etotBlok.PoluchPosicii();
    for (Posicii item : tiles)
    {
        setka.setka[item.row][item.col] = etotBlok.id;
    }
    etotBlok = sledBlok;
    if (BlockVlez() == false)
    {
        gameover = true;
    }
    sledBlok = RandomniBlock();
    int rowsCleared = setka.FinalOchistka();
    ObnovitScore(rowsCleared, 0);
}

bool Game::BlockVlez()
{
    std::vector<Posicii> tiles = etotBlok.PoluchPosicii();
    for (Posicii item : tiles)
    {
        if (setka.ProverkaNaPystoty(item.row, item.col) == false)
        {
            return false;
        }
    }
    return true;
}
