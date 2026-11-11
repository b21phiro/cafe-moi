#ifndef CAFEMOI_TAG_COMPONENT_H
#define CAFEMOI_TAG_COMPONENT_H

#include <string>

struct TagComponent
{
    std::string value;

    TagComponent();

    explicit TagComponent(const std::string& value);

};

#endif