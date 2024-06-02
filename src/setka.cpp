#include "setka.h"
#include <iostream>
#include "colors.h"

Setka::Setka()
{
    colors = PoluchitColor();
    numRows = 20;
    numCols = 10;
    size_of_cell = 30;
    Initialaze();
}

void Setka::Initialaze()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            setka[row][col] = 0;
        }
    }
}

void Setka::print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            std::cout << setka[row][col] << ' ';
        }
        std::cout << std::endl;
    }
}

void Setka::Risov()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            int val = setka[row][col];
            DrawRectangle(col * size_of_cell + 11, row * size_of_cell + 11, size_of_cell - 1, size_of_cell - 1, colors[val]);
        }
    }
}

bool Setka::ProverkaNaVilet(int row, int col)
{
    if (row >= 0 && row < numRows && col >= 0 && col < numCols)
    {
        return false;
    }
    return true;
}

int Setka::FinalOchistka()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (ProverkaNaPolnoty(row))
        {
            Ochistka(row);
            completed++;
        }
        else if (completed > 0)
        {
            OpystitVse(row, completed);
        }
    }
    return completed;
}

bool Setka::ProverkaNaPystoty(int row, int col)
{
    if (setka[row][col] == 0)
    {
        return true;
    }
    return false;
}

bool Setka::ProverkaNaPolnoty(int row)
{
    for (int col = 0; col < numCols; col++)
    {
        if (setka[row][col] == 0)
        {
            return false;
        }
    }
    return true;
}

void Setka::Ochistka(int row)
{
    for (int col = 0; col < numCols; col++)
    {
        setka[row][col] = 0;
    }
}

void Setka::OpystitVse(int row, int NumRows)
{
    for (int col = 0; col < numCols; col++)
    {
        setka[row + NumRows][col] = setka[row][col];
        setka[row][col] = 0;
    }
}
