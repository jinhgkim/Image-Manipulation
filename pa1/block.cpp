#include "block.h"
#include <cmath>
#include <iostream>

int Block::width() const
{
    return data[0].size();
}
int Block::height() const
{
    return data.size();
}

void Block::render(PNG &im, int column, int row) const
{
    for (int y = row; y < row + height(); y++)
    {
        for (int x = column; x < column + width(); x++)
        {
            RGBAPixel *imgPixel = im.getPixel(x, y);
            RGBAPixel dataPixel = data[y - row][x - column];
            imgPixel->r = dataPixel.r;
            imgPixel->g = dataPixel.g;
            imgPixel->b = dataPixel.b;
            imgPixel->a = dataPixel.a;
        }
    }
}

void Block::build(PNG &im, int column, int row, int width, int height)
{
    data.resize(height, vector<RGBAPixel>(width));

    for (int y = row; y < row + height; y++)
    {
        for (int x = column; x < column + width; x++)
        {
            RGBAPixel *imgPixel = im.getPixel(x, y);
            RGBAPixel *dataPixel = &data[y - row][x - column];
            dataPixel->r = imgPixel->r;
            dataPixel->g = imgPixel->g;
            dataPixel->b = imgPixel->b;
            dataPixel->a = imgPixel->a;
        }
    }
}

void Block::flipVert()
{
    int height = this->height();
    int width = this->width();
    for (int y = 0; y < height / 2; y++)
    {
        for (int x = 0; x < width; x++)
        {
            RGBAPixel temp = data[y][x];
            data[y][x] = data[height - 1 - y][x];
            data[height - 1 - y][x] = temp;
        }
    }
}

void Block::flipHoriz()
{
    int height = this->height();
    int width = this->width();
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            RGBAPixel temp = data[y][x];
            data[y][x] = data[y][width - 1 - x];
            data[y][width - 1 - x] = temp;
        }
    }
}

void Block::rotateRight()
{
    int height = this->height();
    int width = this->width();
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            //
        }
    }
}
