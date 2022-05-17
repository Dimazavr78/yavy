#pragma once
#include "string_base.h"
static int copyClassDec = 0;
class decString :
	public string
{
public:
	decString();
	decString(const char);
	decString(const char*);
	decString(const decString&);
	bool trans();
	bool check(const char);
	bool check(const char*);
	bool operator>(const decString&);
	bool operator==(const decString&);
	bool operator<(const decString&);
	char operator[](const int);
	int _atoi();
	int getCopy();
	decString& operator=(const decString&);
	decString& operator=(const char);
	decString& operator=(const char*);
	friend std::ostream& operator<<(std::ostream&, decString&);
	friend std::istream& operator>>(std::istream&, decString&);
	~decString();
protected:
	virtual void print(std::ostream&);
	virtual void write(std::istream&);
};
inline std::ostream& operator<<(std::ostream& out, decString& dec)
{
	dec.print(out);
	return out;
}
inline std::istream& operator>>(std::istream& in, decString& dec)
{
	dec.write(in);
	return in;
}