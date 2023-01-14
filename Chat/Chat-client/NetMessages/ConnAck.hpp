#pragma once

#include "MessagesTypes.hpp"
#include "../AsyncNetFramework/io/BasicNetMessage.h"
#include "../typedefs.hpp"

class ConnAckMessage : public _BNetMsg
{
    // ISerializable interface
public:
    ConnAckMessage() = default;
    void deserialize(char *buffer) override
    {
        m_header.deserialize(buffer);
    }
    void serialize(char *buffer) const override
    {
        m_header.serialize(buffer);
    }
    uint32_t calculateNeededSizeForThis() const override
    {
        return _Header::getHeaderSize();
    }

    // NetMessage interface
public:
    MessageTypes getMessageType() const override
    {
        return MessageTypes::CONNACK;
    }
};
