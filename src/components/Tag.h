#ifndef CAFEMOI_TAG_H
#define CAFEMOI_TAG_H

#include <string>

struct Tag
{

    std::string value;

    bool remove;

    Tag();

    explicit Tag(std::string  value);

};

#endif
