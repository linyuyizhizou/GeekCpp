//
// Created by F4 on 2019/6/27.
//

#ifndef COMP_STRING_H
#define COMP_STRING_H

#include <cstring>
#include "iostream"

using namespace std;

class String {
public:
    String(const char *cstr = 0);

    String(const String &str);  //拷贝构造  接受了自己那种东西
    String &operator=(const String &str);

    ~String();//析构函数
    char *get_c_str() const {
        return m_data;
    }


private:
    char *m_data;
};

inline String::String(const char *cstr = 0) {
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);

    } else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::~String() {
    delete[] m_data;
}

inline String::String(const String &str) {
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);

}

inline String& String::operator=(const String &str) {
    if (this == &str)
        return *this;
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

#include <iostream>

ostream &operator<<(ostream &os, const String &str) {
    os << str.get_c_str();
    return os;
}


#endif //COMP_STRING_H
