#pragma once

#include <iostream>
#include <cstring>

class String
{
private:
    char *data;

public:
    String();
    String(const char *str);
    ~String();

    String(const String &other);
    String(String &&other) noexcept;

    String &operator=(const String &other);
    String &operator=(String &&other) noexcept;

    bool operator==(const String &other) const;
    bool operator<(const String &other) const;
    bool operator>(const String &other) const;

    String operator+(const String &other) const;

    friend std::ostream &operator<<(std::ostream &os, const String &str);
};