#pragma once
#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <iostream>


using std::vector;
using std::ostream;
using std::string;
class Canvas
{
public:
	Canvas() = default;
	virtual ~Canvas() = default;
	Canvas(const Canvas&) = default;
	Canvas(Canvas&&) = default;
	Canvas& operator=(const Canvas&) = default;
	Canvas& operator=(Canvas&&) = default;
protected:
	vector<vector<char> > grid{};
	bool check(int r, int c)const;
	void resize(size_t rows, size_t cols);
public:
	Canvas(int rows, int columns, char fillChar = ' ');

	int getRows()const;
	int getColumns()const;
	Canvas flip_horizontal() const;
	Canvas flip_vertical() const;
	void print(ostream&) const;
	char get(int r, int c)const;
	void put(int r, int c, char ch);

	void drawString(int r, int c, const string text);

	void overlap(const Canvas& can, size_t r, size_t c);
};
ostream& operator<<(ostream& sout, const Canvas& f);
#endif

