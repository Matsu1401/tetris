/**
 *\file bloki.cpp
 *Файл где происходят большинство действий с блоками
 */

#include "bloki.h"

gBlock::gBlock()
{
    kletkisize = 30;
    rotation = 0;
    colors = PoluchitColor();
    colPerev = 0;
    rowPerev = 0;
}

/**
 * \ Рисует блок на экране с заданным смещением.
 *
 * Этот метод рисует все клетки блока на экране, используя заданные смещения по осям X и Y.
 * Он получает текущие позиции всех клеток блока с помощью метода PoluchPosicii() и рисует
 * каждую клетку с использованием функции DrawRectangle().
 *
 * \param[in] offsetX Смещение по оси X.
 * \param[in] offsetY Смещение по оси Y.
 */
void gBlock::Risov(int offsetX, int offsetY)
{
    // Получить текущие позиции всех клеток блока
    std::vector<Posicii> plitka = PoluchPosicii();

    // Пройти по всем клеткам блока
    for (Posicii item : plitka)
    {
        // Нарисовать каждую клетку с учетом смещения и цвета
        DrawRectangle(item.col * kletkisize + offsetX, item.row * kletkisize + offsetY, kletkisize - 1, kletkisize - 1, colors[id]);
    }
}

/**
 * \ Перемещает блок на заданное количество строк и столбцов.
 *
 * Этот метод изменяет текущую позицию блока, добавляя к его текущим координатам
 * заданное количество строк и столбцов. Метод обновляет внутренние переменные
 * rowPerev и colPerev, которые хранят смещение блока относительно его
 * начальной позиции.
 *
 * \param[in] rows Количество строк, на которое нужно переместить блок.
 * \param[in] cols Количество столбцов, на которое нужно переместить блок.
 */
void gBlock::Move(int rows, int cols)
{
    rowPerev += rows;
    colPerev += cols;
}

/**
 * \ Возвращает текущие позиции блока с учетом его смещения.
 *
 * Этот метод создает и возвращает вектор позиций (объектов типа Posicii),
 * представляющих текущее положение блока на игровом поле. Позиции рассчитываются
 * на основе текущей ориентации блока (rotation) и его смещения (rowPerev и colPerev).
 *
 * \return Вектор объектов типа Posicii, представляющих текущие позиции блока.
 */
std::vector<Posicii> gBlock::PoluchPosicii()
{
    std::vector<Posicii> tiles = kletki[rotation];
    std::vector<Posicii> movedTiles;
    for (Posicii item : tiles)
    {
        Posicii novaiapos = Posicii(item.row + rowPerev, item.col + colPerev);
        movedTiles.push_back(novaiapos);
    }
    return movedTiles;
}

/**
 * \ Поворачивает блок на 90 градусов по часовой стрелке.
 *
 * Этот метод изменяет текущую ориентацию блока, увеличивая значение
 * переменной rotation. Если после увеличения значение переменной
 * rotation становится равным количеству возможных ориентаций (kletki.size()),
 * оно сбрасывается на 0, что позволяет циклически переключаться между ориентациями.
 */
void gBlock::Rotate()
{
    rotation++;
    if (rotation == (int)kletki.size())
    {
        rotation = 0;
    }
}

/**
 * \ Отменяет последний поворот блока, поворачивая его на 90 градусов против часовой стрелки.
 *
 * Этот метод изменяет текущую ориентацию блока, уменьшая значение
 * переменной rotation. Если после уменьшения значение переменной
 * rotation становится равным -1, оно устанавливается на максимальное
 * значение индекса ориентации (kletki.size() - 1), что позволяет
 * циклически переключаться между ориентациями в обратном порядке.
 */
void gBlock::OtmenaRotation()
{
    rotation--;
    if (rotation == -1)
    {
        rotation = kletki.size() - 1;
    }
}
