#pragma once
#include "iostream"
static int copyClassString = 0;
class string
{
public:
	explicit string();
	explicit string(const char);
	explicit string(const char*);
	explicit string(const string&);
	virtual bool trans();
	virtual bool operator>(const string&);
	virtual bool operator<(const string&);
	virtual bool operator==(const string&);
	virtual char operator[](const int);
	virtual int length();
	virtual int getCopy();
	virtual char lastChar();
	virtual string& operator=(const string&);
	virtual string& operator=(const char);
	virtual string& operator=(const char*);
	friend std::ostream& operator<<(std::ostream&, string&);
	friend std::istream& operator>>(std::istream&, string&);
	virtual ~string();
protected:
	int size;
	char* str;
	virtual void print(std::ostream&);
	virtual void write(std::istream&);
	
};
inline std::ostream& operator<<(std::ostream& out, string& st)
{
	st.print(out);
	return out;
}
inline std::istream& operator>>(std::istream& in, string& st)
{
	st.write(in);
	return in;
}
