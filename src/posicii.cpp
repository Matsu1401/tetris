/**
 * \file posicii.cpp
 * Этот файл содержит конструктор для для класса Posicii
 */
#include "posicii.h"

/**
 * Конструктор для класса Posicii.
 *
 * Инициализирует новый объект позиции с заданными значениями строки и столбца.
 *
 * \param[in] row Значение строки.
 * \param[in] col Значение столбца.
 */
Posicii::Posicii(int row, int col)
{
    this->row = row;
    this->col = col;
}