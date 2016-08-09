/*************************************************************************
	> File Name: MyString.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月05日 星期五 11时09分20秒
 ************************************************************************/

#ifndef _MYSTRING_H
#define _MYSTRING_H

#include<iostream>
#include<cstring>

class MyString {
private:
    char* m_data;
    size_t m_len;
    void copy_data(const char *s)
    {
        m_data = new char[m_len+1];
        memcpy(m_data, s, m_len);
        m_data[m_len + 1] = '\0';
    }

public:
    MyString() 
    {
        m_data = NULL;
        m_len = 0;
    }

    MyString(const char *p)
    {
        m_len = strlen(p);
        copy_data(p);
    }

    MyString(const MyString &str)
    {
        m_len = str.m_len;
        copy_data(str.m_data);
        std::cout << "Copy constructor is called! source: " << str.m_data << std::endl;
    }
    
    MyString(MyString&& str)
    {
        std::cout << "Move constructor is called! source: " << str.m_data << std::endl;
        m_len = str.m_len;
        m_data = str.m_data;
        str.m_len = 0;
        str.m_data = NULL;
    }

    MyString& operator=(const MyString &str)
    {
        if (*this != str) {
            m_len = str.m_len;
            copy_data(str.m_data);
        }
        std::cout << "Copy Assignment is called! source: " << str.m_data << std::endl;
        return *this;
    }

    MyString& operator=(MyString&& str)
    {
        std::cout << "Move Assignment is called! source: " << str.m_data << std::endl;
        if (this != &str) {
            m_len = str.m_len;
            m_data = str.m_data;
            m_len = 0;
            m_data = NULL;
        }

        return *this;
    }

    bool operator != (const MyString rhs)
    {
        if ((rhs.m_len == m_len) && (rhs.m_data == m_data))
        {
            return false;
        }

        return true;
    }

    ~MyString()
    {
        if (m_data)
        {
            free(m_data);
        }
    }
};

#endif
