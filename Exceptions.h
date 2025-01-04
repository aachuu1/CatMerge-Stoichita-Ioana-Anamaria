#pragma once
#include <exception>
//class for invalid key exception
class InvalidKeyException : public std::exception {
public:
    InvalidKeyException()=default;
    [[nodiscard]] const char* what() const noexcept override {
        return "Oh no, you pressed the wrong key!";
    }
    ~InvalidKeyException() override = default;
};
//class for detecting font exception
class FontNotDetectedException : public std::exception {
public:
    FontNotDetectedException()=default;
    [[nodiscard]] const char* what() const noexcept override {
        return "Oh no, the font is missing!";
    }
    ~FontNotDetectedException() override = default;
};

//all classes are derived from base class exception