/**
 * \file posicii.h
 * Этот файл содержит класс Posicii, где объявлены действия связанные с позицией блока
 */
#ifndef POSICII_H
#define POSICII_H

/**
 * \class Posicii
 * Класс, представляющий позицию в двумерной сетке.
 *
 * Этот класс используется для хранения и управления координатами строки и столбца.
 */

class Posicii
{
public:
    /**
     * Конструктор для класса Posicii.
     *
     * Инициализирует новый объект позиции с заданными значениями строки и столбца.
     *
     * \param[in] row Значение строки.
     * \param[in] col Значение столбца.
     */
    Posicii(int row, int col);

    int col; ///< Значение столбца.
    int row; ///< Значение строки.
};
#endif