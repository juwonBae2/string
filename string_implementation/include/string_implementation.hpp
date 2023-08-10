#pragma once

#include <iostream>
#include <cstring>

class String
{
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

private:
    char *data;

    void initializeFromString(const char *str);
    void initializeFromOther(const String &other);
};