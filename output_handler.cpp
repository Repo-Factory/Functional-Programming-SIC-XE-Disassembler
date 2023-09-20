/*
 *  @brief
 *          Organizes functions to output answer
 *
 *  Defines a series of operation overloaded functions to print all of our various fields
 */

#include "output_handler.hpp"
#include <iostream>
#include <vector>

#define FORMAT_ENUM_DISPLACEMENT 2
#define ADDRESSING_MODE_ENUM_DISPLACEMENT 1

std::ostream& FileHandling::print_column_names(std::ofstream& stream)
{
    return stream << ("INSTR   FORMAT   OAT   TAAM   OBJ\n"); 
}

/* Static casting our enums will give us a value we can corresponding to array index to print appropriate string  */
std::ostream& operator<<(std::ostream& stream, const AddressingMode addressingMode)
{
    std::vector<std::string> modesStrings = std::vector<std::string>{"Immediate", "Indirect", "Simple"};
    return stream << modesStrings[static_cast<int>(addressingMode)-ADDRESSING_MODE_ENUM_DISPLACEMENT];
}

std::ostream& operator<<(std::ostream& stream, const TargetAddressMode targetAddressMode)
{
    std::vector<std::string> targetAddressModeStrings = std::vector<std::string>{"Absolute", "PC", "Base"};
    return stream << targetAddressModeStrings[static_cast<int>(targetAddressMode)];
}

std::ostream& operator<<(std::ostream& stream, const AddressingFormat instructionFormat)
{
    std::vector<std::string> instructionFormatStrings = std::vector<std::string>{"2", "3", "4"};
    return stream << instructionFormatStrings[(static_cast<int>(instructionFormat))-FORMAT_ENUM_DISPLACEMENT];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* If indexed is true, print out _Indexed (this will be appended to the end of target address mode) */
std::ostream& operator<<(std::ostream& stream, const Indexed wrapper)
{
    return wrapper.indexed ? stream << "_Indexed" : stream;
}

/* Function called from main to print the answer for the output */
std::ostream& operator<<(std::ostream& stream, const Output output)
{
    if (output.format == AddressingFormat::Format2) {
        return stream << output.opCode << "      " << output.format << "              " << output.objectCode;
    } 
    else {
        return stream << output.opCode << "      " << output.format << "      " << output.addresingMode << "      " << 
        output.targetAddressMode << Indexed{output.isIndexed} << "      " << output.objectCode << std::endl;
    }
}