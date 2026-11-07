#include "Tag.h"

#include <utility>

Tag::Tag() : value("Unknown"), remove(false) {};

Tag::Tag(std::string value) : value(std::move(value)), remove(false) {}