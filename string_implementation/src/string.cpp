#include "string.hpp"
#include <spdlog/spdlog.h>

String::String() : data_(new char[1])
{
    data_[0] = '\0';
}

String::String(const char *str)
{
    initializeFromString(str);
}

String::String(const char *str, size_t length)
{
    if (str == nullptr)
    {
        data_ = nullptr;
    }
    else
    {
        data_ = new char[length + 1];
        strncpy(data_, str, length);
        data_[length] = '\0';
    }
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
    size_t totalLength = strlen(this->data_) + strlen(str.data_);
    char *temp = new char[totalLength + 1];

    strcpy(temp, data_);
    strcat(temp, str.data_);

    String result(temp);

    delete[] temp;

    return result;
}

String &String::operator+=(const String &str)
{
    size_t totalLength = strlen(this->data_) + strlen(str.data_);
    char *temp = new char[totalLength + 1];

    strcpy(temp, data_);
    strcat(temp, str.data_);

    delete[] data_;
    data_ = temp;

    return *this;
}

char &String::front() const
{
    return this->data_[0];
}

char &String::back() const
{
    return this->data_[this->size() - 1];
}

String String::trim() const
{
    if (data_ == nullptr)
    {
        return String();
    }

    size_t length = strlen(data_);
    size_t newIndex = 0;
    char *trimmedData = new char[length + 1];

    for (size_t i = 0; i < length; ++i)
    {
        if (!isspace(data_[i]))
        {
            trimmedData[newIndex++] = data_[i];
        }
    }

    trimmedData[newIndex] = '\0';

    String trimmedString(trimmedData);
    delete[] trimmedData;

    return trimmedString;
}

String String::erase(size_t start, size_t count) const
{
    if (data_ == nullptr)
    {
        return String();
    }

    size_t length = strlen(data_);

    if (start >= length || count == 0)
    {
        spdlog::warn("Erase start index or count is out of bounds. Returning original string.");
        return String(data_);
    }

    if (start + count > length)
    {
        count = length - start;
        spdlog::warn("Erase count adjusted to fit within string length.");
    }

    try
    {
        char *erasedData = new char[length - count + 1];

        strncpy(erasedData, data_, start);
        erasedData[start] = '\0';

        strcat(erasedData, data_ + start + count);

        String erasedString(erasedData);
        delete[] erasedData;

        return erasedString;
    }
    catch (const std::bad_alloc &)
    {
        spdlog::error("Memory allocation failed in erase.");
        return String();
    }
}

String String::find(const String &str) const
{
    if (str.data_ == nullptr || data_ == nullptr)
    {
        spdlog::error("Null pointer passed to find() function.");
        throw std::runtime_error("Null pointer passed to find() function.");
    }

    char *found = strstr(data_, str.data_);
    if (found)
    {
        size_t foundIndex = found - data_;
        return String(data_ + foundIndex, str.size());
    }
    else if (str.data_ == nullptr && str.data_[0] == '\0')
    {
        spdlog::error("Empty string passed to find() function.");
        // return String();
    }
    else
    {
        spdlog::info("Substring not found.");
        // return String();
    }

    return String();
}

std::ostream &operator<<(std::ostream &os, const String &str)
{
    if (str.data_ != nullptr)
    {
        os << str.data_;
    }
    return os;
}

size_t String::size() const
{
    return data_ ? strlen(data_) : 0;
}

void String::initializeFromString(const char *str)
{
    if (str != nullptr)
    {
        // TODO: if 만약 null이 아닐경우?
        this->data_ = new char[strlen(str) + 1];
        strcpy(data_, str);
    }
    else
    {
        this->data_ = nullptr;
    }
}

void String::initializeFromOther(const String &Other)
{
    if (Other.data_ != nullptr)
    {
        this->data_ = new char[strlen(Other.data_) + 1];
        strcpy(data_, Other.data_);
    }
    else
    {
        this->data_ = nullptr;
    }
}

String::Iterator::Iterator(pointer ptr) : ptr_(ptr) {}

String::Iterator::reference String::Iterator::operator*() const
{
    return *ptr_;
}

String::Iterator::pointer String::Iterator::operator->()
{
    return ptr_;
}

String::Iterator &String::Iterator::operator++()
{
    ++ptr_;
    return *this;
}

String::Iterator String::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++ptr_;
    return temp;
}

bool String::Iterator::operator==(const Iterator &other) const
{
    return ptr_ == other.ptr_;
}

bool String::Iterator::operator!=(const Iterator &other) const
{
    return ptr_ != other.ptr_;
}

String::Iterator String::begin()
{
    return String::Iterator(data_);
}

String::Iterator String::end()
{
    return String::Iterator(data_ + size());
}
