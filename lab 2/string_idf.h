#pragma once
#include "string_base.h"
static int copyClassIdn = 0;
class indString :
	public string
{
protected:
	virtual void print(std::ostream&);
	virtual void write(std::istream&);
public:
	indString();
	indString(const char);
	indString(const char*);
	indString(const indString&);
	bool check(const char);
	bool check(const char*);
	bool operator>(const indString&);
	bool operator<(const indString&);
	bool operator==(const indString&);
	char operator[](const int);
	char lastChar();
	int getCopy();
	indString& operator=(const indString&);
	indString& operator=(const char);
	indString& operator=(const char*);
	friend std::ostream& operator<<(std::ostream&, indString&);
	friend std::istream& operator>>(std::istream&, indString&);
	~indString();
};
inline std::ostream& operator<<(std::ostream& out, indString& ind)
{
	ind.print(out);
	return out;
}
inline std::istream& operator>>(std::istream& in, indString& ind)
{
	ind.write(in);
	return in;
	
}