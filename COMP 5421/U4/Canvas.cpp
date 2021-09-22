#include "Canvas.h"
#include <cstring>
#include <array>


/**
*
* validates row r and column c
* @param int r (rows), int c (columns)
* @return bool
*/
bool Canvas::check(int r, int c) const//validates row r and column c
{
    return (r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size());
}

/**
*
* resizes this Canvas's dimensions
* @param int rows (rows), int cols (columns)
*/
void Canvas::resize(size_t rows, size_t cols)//resizes this Canvas's dimentions
{
    grid.resize(rows);
    for (auto it = grid.begin(); it != grid.end(); it++)
    {
        (*it).resize(cols);
    }

}
/*
*
* creates this canvas's (rows x columns) grid filled with blank characters
* @param int rows, int columns, char fillchar
*/
Canvas::Canvas(int rows, int columns, char fillChar) : grid{ rows, vector<char>(columns) }
// creates this canvas's (rows x columns) grid filled with blank characters
{

    vector<vector<char> > vec(rows, vector<char>(columns));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            vec[i][j] = fillChar;
        }
    }
    grid = vec;
}
/*
*
* height getter
* @ return int
*/
int Canvas::getRows() const// return height
{
    return grid.size();
}
/*
*
* width getter
* @ return int
*/
int Canvas::getColumns() const// returns width
{
    return grid[0].size();
}
/*
*
* flips this canvas horizontally
*/
Canvas Canvas::flip_horizontal() const// flips this canvas horizontally

{
    Canvas flipped = *this;
    for (auto& row : flipped.grid)
        for (int i = 0; i < row.size() / 2; ++i)
            std::swap(row[i], row[row.size() - 1 - i]);

    return flipped;
}
/*
*
* flips this canvas vertically
*/
Canvas Canvas::flip_vertical() const// flips this canvas vertically

{
    Canvas flipped = *this;
    for (int i = 0; i < flipped.grid.size() / 2; ++i)
        std::swap(flipped.grid[i], flipped.grid[flipped.grid.size() - 1 - i]);

    return flipped;
}
/*
*
* prints to ostream
* @param ostream sout
*/
void Canvas::print(ostream& sout) const// prints to ostream
{

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            sout << grid[i][j];
        }
        sout << std::endl;
    }

}
/*
*
* getter char at row r and column c
* @param int r, int c
* @return char grid[r][c]
*/
char Canvas::get(int r, int c) const// returns char at row r and column c
{
    if (check(r, c)) return grid[r][c];
    throw std::invalid_argument("Canvas subscripts out of bpounds");
}
/*
*
* puts ch at row r and column c; this is the
* only function used by a shape’s draw functon;
* returns doing nothing if r or c is invalid
* @param int r (rows), int c (columns), char ch
*/
void Canvas::put(int r, int c, char ch)// puts ch at row r and column c; this is the
 // only function used by a shape’s draw functon;
 // returns doing nothing if r or c is invalid
{
    if (check(r, c)) { grid[r][c] = ch; }

}
/*
*
* draws text starting at row r and col c on the canvas
* @param int r (rows), int c (columns), const string text
*/
void Canvas::drawString(int r, int c, const string text)// draws text starting at row r and col c on the canvas
{
    if (check(r, c) && (c + text.size() < getColumns()))
        for (int i = 0; i < text.size(); ++i)
            grid[r][c + i] = text[i];
}
/*
*
* copies the non-blank characters of "can" onto the invoking canvas;
* maps can’s origin to row r and column c on the invoking canvas
* @param const Canvas& can, size_t r (rows), size_t c (columns)
*/
void Canvas::overlap(const Canvas& can, size_t r, size_t c)// copies the non-blank characters of "can" onto the invoking canvas;
 // maps can’s origin to row r and column c on the invoking canvas
{
    if (check(r, c) && (r + can.getRows()) < getRows() && (c + can.getColumns()) < getColumns())
        for (int i = 0; i < can.getRows(); ++i)
            for (int j = 0; j < can.getColumns(); ++j)
                if (can.get(i, j) != ' ')
                    grid[r + i][c + j] = can.get(i, j);
}
/*
*

* @param ostream& sout, const Canvas& f
* @return ostream
*/
ostream& operator<<(ostream& sout, const Canvas& f)
{
    f.print(sout);
    return sout;
}

