// Copyright (c) 2018-2021, The DeroGold Developers
// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote
{
    struct CheckpointData
    {
        uint32_t index;
        const char *blockId;
    };

const std::initializer_list<CheckpointData> CHECKPOINTS = {
{       0, "7fb97df81221dd1366051b2d0bc7f49c66c22ac4431d879c895b06d66ef66f4c"},
{    5000, "acb63abe6239f97b663c2273816f310af7af8ce6bc2e3c38e08f52b45a5b4744"},
{   10000, "90d9a950a83979c10edff20215e843adcad1928ab260da28470c95eb2705a330"},
{   15000, "6a607037a7601fa0ee2d3bfc84137b0a7114587ca17fb116f10ced60ff93cda4"},
{   20000, "55cd847160754eebf2737c9b391c78cf6e595b761b91b122c229eff3338c37bb"},
{   25000, "13c46f534f4b314ce3976c38b30bb41b0c9e5fd633e004af4e12704734ea145c"},
};
} // namespace CryptoNote
