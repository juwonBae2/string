#include "string.hpp"

String::String() : data_(nullptr) {}

String::String(const char *str)
{
    initializeFromString(str);
}

String::~String()
{
    if (this->data_ != nullptr)
    {
        delete[] this->data_;
    }
}

String::String(const String &str)
{
    initializeFromOther(str);
}

String::String(String &&str) noexcept
{
    this->data_ = str.data_;
    str.data_ = nullptr;
}

String &String::operator=(const String &str)
{
    if (this != &str)
    {
        delete[] data_;
        initializeFromOther(str);
    }
    return *this;
}

String &String::operator=(String &&str) noexcept
{
    if (this != &str)
    {
        delete[] data_;
        data_ = str.data_;
        str.data_ = nullptr;
    }
    return *this;
}

bool String::operator==(const String &str) const
{
    return (strcmp(this->data_, str.data_) == 0);
}

bool String::operator!=(const String &str) const
{
    return !(strcmp(this->data_, str.data_) == 0);
}

bool String::operator<(const String &str) const
{
    return (strcmp(this->data_, str.data_) < 0);
}

bool String::operator>(const String &str) const
{
    return (strcmp(this->data_, str.data_) > 0);
}

String String::operator+(const String &str) const
{
    size_t totalLen = strlen(this->data_) + strlen(str.data_);
    char *temp = new char[totalLen + 1];
    strcpy(temp, data_);
    strcat(temp, str.data_);
    String result(temp);
    delete[] temp;
    return result;
}

String String::trim(const String &str) const
{
    return 0;
}

std::ostream &operator<<(std::ostream &os, const String &str)
{
    if (str.data_ != nullptr)
    {
        os << str.data_;
    }
    return os;
}

void String::initializeFromString(const char *str)
{
    if (str != nullptr)
    {
        this->data_ = new char[strlen(str) + 1];
        strcpy(data_, str);
    }
    else
    {
        this->data_ = nullptr;
    }
}

void String::initializeFromOther(const String &str)
{
    if (str.data_ != nullptr)
    {
        this->data_ = new char[strlen(str.data_) + 1];
        strcpy(data_, str.data_);
    }
    else
    {
        this->data_ = nullptr;
    }
}
