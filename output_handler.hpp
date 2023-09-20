#ifndef OUTPUT_HANDLER_H
#define OUTPUT_HANDLER_H

#include <fstream>
#include "parser.hpp"
#include <fstream>

namespace FileHandling
{
    std::ostream& print_column_names(std::ofstream& stream);
}

/* Consolidates our output into a single struct to overload our << operator */
struct Output
{
    const std::string opCode;
    const AddressingFormat format;
    const AddressingMode addresingMode;
    bool isIndexed; 
    const TargetAddressMode targetAddressMode;
    const std::string objectCode;
};

/* Wrapper so we can operator overload our bool value */
struct Indexed
{
    bool indexed; 
};

std::ostream& operator<<(std::ostream& stream, const AddressingMode addressingMode);

std::ostream& operator<<(std::ostream& stream, const Indexed wrapper);

std::ostream& operator<<(std::ostream& stream, const TargetAddressMode targetAddressMode);

std::ostream& operator<<(std::ostream& stream, const AddressingFormat instructionFormat);

std::ostream& operator<<(std::ostream& stream, const Output output);

#endif