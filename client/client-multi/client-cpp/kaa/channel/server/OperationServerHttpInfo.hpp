/*
 * Copyright 2014 CyberVision, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OPERATIONSERVERHTTPINFO_HPP_
#define OPERATIONSERVERHTTPINFO_HPP_


#include "kaa/channel/server/AbstractServerInfo.hpp"

namespace kaa {

class OperationServerHttpInfo: public AbstractServerInfo<ChannelType::HTTP> {
public:
    OperationServerHttpInfo(const std::string& hostPort, const std::string& publicKey) :
        AbstractServerInfo(hostPort, publicKey) {}

    OperationServerHttpInfo(const std::string& host, const boost::int32_t& port, const std::string& publicKey)
        : AbstractServerInfo(host, port, publicKey) {}

    OperationServerHttpInfo(const std::string& host, const boost::int32_t& port
            , const Botan::MemoryVector<boost::uint8_t>& publicKey)
        : AbstractServerInfo(host, port, publicKey) {}

    virtual HttpUrl getUrl() const {
        std::stringstream ss;
        ss << getHost() << ":" << getPort() << "/EP/Sync";
        return HttpUrl(ss.str());
    }
};

typedef boost::shared_ptr<OperationServerHttpInfo> OperationServerHttpInfoPtr;

}



#endif /* OPERATIONSERVERHTTPINFO_HPP_ */