#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "mystring.h"
String::String()
{
    str = new char[1];
    *str = '\0';
    length = 0;
}
String::String(const int length)
{
    this->length = length;
    str = new char[length + 1];
    *str = '\0';
}
String::String(const char* string)
{
    length = strlen(string);
    str = new char[length + 1];
    for (int i = 0; i < length+1; i++)
    {
        *(str + i) = string[i];
    }
}
String::String(const String& string)
{
    this->length = string.length;
    str = new char[length + 1];
    strcpy(str, string.str);
}
String:: ~String()
{
    delete[] str;
}
bool  String::is_Empty()
{
    return (*str == '\0') ? true : false;
}
int String::Length()
{
    int i = 0;
    while(*(str+i)!='\0')
    {
        i++;
    }
    return i;
}
void String::Clear()
{
    delete[] str;
}
String String::Get_Substring(const int start, const int end)
{
   const int sublength = end - start+1;
   String substring(sublength);
   for (int i = 0; i < sublength; i++)
   {
       *(substring.str + i) = *(str + start + i);
   }
   return substring;
}
void String::Delete_Substring(const int start, const int end)
{
    int a = end - start+1;
    String substring(length - a);
    for (int i = 0; i < start; i++)
    {
        *(substring.str + i) = *(str + i);
    }
    for (int i = start; i < length+1; i++)
    {
        *(substring.str + i) = *(str + i+a);
    }
    *this = substring;
}
bool String::Check_char(const char ch)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) == ch)
            return true;
        i++;
    }
    return false;
}
bool String::Check_substring(const char* c)
{
    int i = 0, j;
    for (; i <length+1 ; i++)
    {
        for (j = 0; *(str + i + j) == *(c + j)&& *(str + i + j)!='\0'; j++);
        if (j == strlen(c))
            return true;
    }
    return false;
}
bool String::Check_substring(const String& c)
{
    int i = 0, j;
    for (; i < length + 1; i++)
    {
        for (j = 0; *(str + i + j) == *(c.str + j) && *(str + i + j) != '\0'; j++);
        if (j == c.length)
            return true;
    }
    return false;
}
String String::operator = (const String& string)
{
    if (&string == this)
        return *this;
    delete[] this->str;
    this->length = string.length;
    str = new char[length + 1];
    for (int i = 0; i < length + 1; i++)
    {
        *(str + i) = *(string.str + i);
    }
    return string;
}
String String::Get_First_Word()
{
    int j = 0;
    int i;
    String Delimeters(" .,:;?!'-_");
    for (i = 0; i < length + 1; i++)
    {
        for (j = 0; j < Delimeters.length; j++)
        {
            if (*(str + i) == *(Delimeters.str + j))
            {
                break;
            }
        }
        if (*(str + i) == *(Delimeters.str + j)) { break; }
    }
    String word(i);
    for (int q = 0; q < i; q++)
    {
        *(word.str + q) = *(str + q);
    }
    return word;
}
String String::Get_Last_Word()
{
    int j = 0;
    int i;
    int k = 0;
    String Delimeters(" .,:;?!'-_");
    for (i = 0; i < length + 1; i++)
    {
        for (j = 0; j < Delimeters.length; j++)
        {
            if (*(str + i) == *(Delimeters.str + j))
            {
                k = i;
                break;
            }
        }
    }
    String word(length-k-1);
    for (int q = k; q < length + 1; q++)
    {
        *(word.str + q-k) = *(str + q+1);
    }
    return word;
}
String String::operator + (const String& string)const
{
   int i= length + string.length;
    String s(i);
    strcat(s.str, str);
    strcat(s.str, string.str);
    return s;
}
String String::operator += (const String& string)
 {
     length += string.length;
     String s(length);
     strcat(s.str, str);
     strcat(s.str, string.str);
     *this = s;
     return *this;
 }
String String::operator += (const char* string)
 {
     length += strlen(string);
     String s(length);
     strcat(s.str, str);
     strcat(s.str, string);
     *this = s;
     return *this;
 }
String String::operator + (const char* string)const
 {
     int i = length + strlen(string);
     String s(i);
     strcat(s.str, str);
     strcat(s.str, string);
     return s;
 }
bool String::operator == (const String& string)const
 {
     return (strcmp(str, string.str) == 0);
 }
bool String::operator == (const char * string)const
 {
     return (strcmp(str, string) == 0);
 }
bool String::operator != (const String& string)const
 {
     return (strcmp(str, string.str) != 0);
 }
bool String::operator != (const char* string)const
 {
     return (strcmp(str, string) != 0);
 }
bool String::operator > (const String& string)const
 {
     return (strcmp(str, string.str) > 0);
 }
bool String::operator > (const char* string)const
 {
     return (strcmp( str, string)>0);
 }
bool String::operator < (const String& string)const
 {
     return (strcmp(str, string.str) < 0);
 }
bool String::operator < (const char* string)const
 {
     return (strcmp(str, string) < 0);
 }
bool String::operator >= (const String& string)const
 {
     return (strcmp(str, string.str) >= 0);
 }
bool String::operator >= (const char* string)const
 {
     return (strcmp(str, string) >= 0);
 }
bool String::operator <=(const String& string)const
 {
     return (strcmp(str, string.str) <= 0);
 }
bool String::operator <= (const char* string)const
 {
     return (strcmp(str, string) <= 0);
 }
 ostream& operator <<(ostream& os, const String& string)
 {
     for (int i = 0; i < string.length; i++)
     {
         os << *(string.str + i);
     }
     return os;
 }
 bool operator == (const char* str, const String& string)
 {
     return (strcmp(str, string.str) == 0);
 }
 bool operator != (const char* str, const String& string)
 {
     return (strcmp(str, string.str) != 0);
 }
 bool operator <= (const char* str, const String& string)
 {
     return (strcmp(str, string.str) <= 0);
 }
 bool operator >= (const char* str, const String& string)
 {
     return (strcmp(str, string.str) >= 0);
 }
 bool operator > (const char* str, const String& string)
 {
     return (strcmp(str, string.str) > 0);
 }
 bool operator < (const char* str, const String& string)
 {
     return (strcmp(str, string.str) < 0);
 }
 char& String:: operator[] (const int j)
 {
     return *(str + j);
 }
int main()
{
    String b("hello ");
    String a("world");
    String c("zz.djscdl kfvslk");
    cout << ("world" == a);
    cout << c[1];
    c[1] = 's';
    cout << c[1];
    return 0;
}
