// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file ControllerCommand.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "ControllerCommand.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

ControllerCommand::ControllerCommand()
{
    // m_command com.eprosima.idl.parser.typecode.StringTypeCode@1b26f7b2
    m_command ="";
    // m_args com.eprosima.idl.parser.typecode.StringTypeCode@491cc5c9
    m_args ="";

}

ControllerCommand::~ControllerCommand()
{


}

ControllerCommand::ControllerCommand(
        const ControllerCommand& x)
{
    m_command = x.m_command;
    m_args = x.m_args;
}

ControllerCommand::ControllerCommand(
        ControllerCommand&& x)
{
    m_command = std::move(x.m_command);
    m_args = std::move(x.m_args);
}

ControllerCommand& ControllerCommand::operator =(
        const ControllerCommand& x)
{

    m_command = x.m_command;
    m_args = x.m_args;

    return *this;
}

ControllerCommand& ControllerCommand::operator =(
        ControllerCommand&& x)
{

    m_command = std::move(x.m_command);
    m_args = std::move(x.m_args);

    return *this;
}

bool ControllerCommand::operator ==(
        const ControllerCommand& x) const
{

    return (m_command == x.m_command && m_args == x.m_args);
}

bool ControllerCommand::operator !=(
        const ControllerCommand& x) const
{
    return !(*this == x);
}

size_t ControllerCommand::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;


    return current_alignment - initial_alignment;
}

size_t ControllerCommand::getCdrSerializedSize(
        const ControllerCommand& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.command().size() + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.args().size() + 1;


    return current_alignment - initial_alignment;
}

void ControllerCommand::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_command;
    scdr << m_args;

}

void ControllerCommand::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_command;
    dcdr >> m_args;
}

/*!
 * @brief This function copies the value in member command
 * @param _command New value to be copied in member command
 */
void ControllerCommand::command(
        const std::string& _command)
{
    m_command = _command;
}

/*!
 * @brief This function moves the value in member command
 * @param _command New value to be moved in member command
 */
void ControllerCommand::command(
        std::string&& _command)
{
    m_command = std::move(_command);
}

/*!
 * @brief This function returns a constant reference to member command
 * @return Constant reference to member command
 */
const std::string& ControllerCommand::command() const
{
    return m_command;
}

/*!
 * @brief This function returns a reference to member command
 * @return Reference to member command
 */
std::string& ControllerCommand::command()
{
    return m_command;
}
/*!
 * @brief This function copies the value in member args
 * @param _args New value to be copied in member args
 */
void ControllerCommand::args(
        const std::string& _args)
{
    m_args = _args;
}

/*!
 * @brief This function moves the value in member args
 * @param _args New value to be moved in member args
 */
void ControllerCommand::args(
        std::string&& _args)
{
    m_args = std::move(_args);
}

/*!
 * @brief This function returns a constant reference to member args
 * @return Constant reference to member args
 */
const std::string& ControllerCommand::args() const
{
    return m_args;
}

/*!
 * @brief This function returns a reference to member args
 * @return Reference to member args
 */
std::string& ControllerCommand::args()
{
    return m_args;
}

size_t ControllerCommand::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;





    return current_align;
}

bool ControllerCommand::isKeyDefined()
{
    return false;
}

void ControllerCommand::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
      
}
