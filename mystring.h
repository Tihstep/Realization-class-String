#pragma once
using namespace std;

class String
{
private:
	char* str;
	int length;
public:
	String();
	String(const int length);
	String(const char* string);
	String(const String&); 
	bool is_Empty();
	int Length();
	void Clear();
	String Get_Substring(int start, int end);
	void Delete_Substring(const int start, const int end);
	bool Check_char(const char ch);
	bool Check_substring(const char*);
	bool Check_substring(const String& c);
	String Get_First_Word();
	String Get_Last_Word();
	char& operator[] (const int i);
	String operator = (const String&);
	String operator + (const String& string)const;
	String operator + (const char* string)const;
	String operator += (const String& string);
	String operator += (const char* string);
	bool operator == (const String& string)const;
	bool operator == (const char* string)const;
	bool operator != (const String& string)const;
	bool operator != (const char* string)const;
	bool operator > (const String& string)const;
	bool operator > (const char* string)const;
	bool operator < (const String& string)const;
	bool operator < (const char* string)const;
	bool operator >= (const String& string)const;
	bool operator >= (const char* string)const;
	bool operator <= (const String& string)const;
	bool operator <= (const char* string)const;
	friend ostream& operator<<(ostream& os,const String& string);
	friend bool operator == (const char* str,const String& string);
	friend bool operator != (const char* str, const String& string);
	friend bool operator <= (const char* str, const String& string);
	friend bool operator >= (const char* str, const String& string);
	friend bool operator < (const char* str, const String& string);
	friend bool operator > (const char* str, const String& string);
	~String();
};
