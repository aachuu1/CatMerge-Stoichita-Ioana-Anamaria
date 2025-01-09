#pragma once
#include <exception>

// class for handling invalid key exceptions
class InvalidKeyException : public std::exception {
public:
    InvalidKeyException() = default;

    // returns the error message for invalid key
    [[nodiscard]] const char* what() const noexcept override {
        return "Oh no, you pressed the wrong key!";
    }

    // destructor
    ~InvalidKeyException() override = default;
};

// class for handling font detection exceptions
class FontNotDetectedException : public std::exception {
public:
    FontNotDetectedException() = default;

    // returns the error message for missing font
    [[nodiscard]] const char* what() const noexcept override {
        return "Oh no, the font is missing!";
    }

    // destructor
    ~FontNotDetectedException() override = default;
};

// all classes are derived from the base class 'exception'
