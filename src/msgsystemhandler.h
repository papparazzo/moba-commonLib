/*
 *  Project:    moba-common
 *
 *  Copyright (C) 2016 Stefan Paproth <pappi-@gmx.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/agpl.txt>.
 *
 */

#pragma once

#include "jsonabstractitem.h"
#include "msgendpoint.h"
#include "message.h"

namespace moba {

    class MsgSystemHandler {

        public:
            MsgSystemHandler(MsgEndpointPtr msgep) : msgep(msgep) {
            }

            virtual ~MsgSystemHandler() {
            }

            void sendSetAutomaticMode(bool on) {msgep->sendMsg(Message::MT_SET_AUTOMATIC_MODE, toJsonBoolPtr(on));}

            void sendSetEmergencyStop(bool on) {msgep->sendMsg(Message::MT_SET_AUTOMATIC_MODE, toJsonBoolPtr(on));}

            void sendSetStandByMode(bool on) {msgep->sendMsg(Message::MT_SET_AUTOMATIC_MODE, toJsonBoolPtr(on));}

            void sendGetHardwareState()  {msgep->sendMsg(Message::MT_GET_HARDWARE_STATE);}

            void sendHardwareShutdown() {msgep->sendMsg(Message::MT_HARDWARE_SHUTDOWN);}

            void sendHardwareReset() {msgep->sendMsg(Message::MT_HARDWARE_RESET);}

            enum NoticeType {
                NT_INFO,
                NT_WARNING,
                NT_ERROR
            };

            void sendSystemNotice(NoticeType type, const std::string &caption, const std::string &text);

        protected:
            MsgEndpointPtr msgep;
    };
}
