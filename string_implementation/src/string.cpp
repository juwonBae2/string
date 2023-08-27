#include "string.hpp"
#include <spdlog/spdlog.h>

String::String() : data_(nullptr) {}

String::String(const char *str)
{
    if (str != nullptr)
    {
        initializeFromString(str);
    }
    else
    {
        this->data_ = new char[1];
        this->data_[0] = '\0';
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
    size_t totalLen = strlen(this->data_) + strlen(str.data_);
    char *temp = new char[totalLen + 1];
    strcpy(temp, data_);
    strcat(temp, str.data_);
    String result(temp);
    delete[] temp;
    return result;
}

String String::front() const
{
    if (data_ != nullptr && data_[0] != '\0')
    {
        char frontChar[2] = {data_[0], '\0'};
        return frontChar;
    }
    return String();
}

String String::back() const
{
    if (data_ != nullptr && data_[0] != '\0')
    {
        size_t sizeLength = strlen(data_);
        char backChar[2] = {data_[sizeLength - 1], '\0'};
        return backChar;
    }
    return String();
}

String String::trim() const
{
    if (data_ == nullptr)
    {
        // 이거 먼가 이상하다. String(); 이 맞는데
        return String("");
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
    try
    {
        if (data_ == nullptr)
        {
            return String("");
        }

        size_t length = strlen(data_);

        // Ensure start index is within bounds
        if (start >= length)
        {
            // Ensure start index is within bounds
            spdlog::warn("Erase start index is out of bounds. Returning original string.");
            return String(data_);
        }

        // Calculate the new length after erasing
        size_t newLength = length - count;
        if (newLength <= 0)
        {
            return String("");
        }

        char *erasedData = new char[newLength + 1];

        // Copy characters before the erased portion
        strncpy(erasedData, data_, start);
        erasedData[start] = '\0';

        // Copy characters after the erased portion
        if (start + count < length)
        {
            strcat(erasedData, data_ + start + count);
        }

        String erasedString(erasedData);
        delete[] erasedData;

        return erasedString;
    }
    catch (const std::bad_alloc &)
    {
        // Handle memory allocation failure
        spdlog::error("Memory allocation failed in erase.");
        return String("");
    }
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
