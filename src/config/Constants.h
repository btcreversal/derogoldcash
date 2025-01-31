// Copyright (c) 2018-2021, The DeroGold Developers
// Copyright (c) 2019, The TurtleCoin Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <CryptoTypes.h>
#include <vector>

/* You can change things in this file, but you probably shouldn't. Leastways,
   without knowing what you're doing. */
namespace Constants
{
    /* Amounts we make outputs into (Not mandatory, but a good idea) */
    const std::vector<uint64_t> PRETTY_AMOUNTS {1,
                                                2,
                                                3,
                                                4,
                                                5,
                                                6,
                                                7,
                                                8,
                                                9,
                                                10,
                                                20,
                                                30,
                                                40,
                                                50,
                                                60,
                                                70,
                                                80,
                                                90,
                                                100,
                                                200,
                                                300,
                                                400,
                                                500,
                                                600,
                                                700,
                                                800,
                                                900,
                                                1000,
                                                2000,
                                                3000,
                                                4000,
                                                5000,
                                                6000,
                                                7000,
                                                8000,
                                                9000,
                                                10000,
                                                20000,
                                                30000,
                                                40000,
                                                50000,
                                                60000,
                                                70000,
                                                80000,
                                                90000,
                                                100000,
                                                200000,
                                                300000,
                                                400000,
                                                500000,
                                                600000,
                                                700000,
                                                800000,
                                                900000,
                                                1000000,
                                                2000000,
                                                3000000,
                                                4000000,
                                                5000000,
                                                6000000,
                                                7000000,
                                                8000000,
                                                9000000,
                                                10000000,
                                                20000000,
                                                30000000,
                                                40000000,
                                                50000000,
                                                60000000,
                                                70000000,
                                                80000000,
                                                90000000,
                                                100000000,
                                                200000000,
                                                300000000,
                                                400000000,
                                                500000000,
                                                600000000,
                                                700000000,
                                                800000000,
                                                900000000,
                                                1000000000,
                                                2000000000,
                                                3000000000,
                                                4000000000,
                                                5000000000,
                                                6000000000,
                                                7000000000,
                                                8000000000,
                                                9000000000,
                                                10000000000,
                                                20000000000,
                                                30000000000,
                                                40000000000,
                                                50000000000,
                                                60000000000,
                                                70000000000,
                                                80000000000,
                                                90000000000,
                                                100000000000,
                                                200000000000,
                                                300000000000,
                                                400000000000,
                                                500000000000,
                                                600000000000,
                                                700000000000,
                                                800000000000,
                                                900000000000,
                                                1000000000000,
                                                2000000000000,
                                                3000000000000,
                                                4000000000000,
                                                5000000000000,
                                                6000000000000,
                                                7000000000000,
                                                8000000000000,
                                                9000000000000,
                                                10000000000000,
                                                20000000000000,
                                                30000000000000,
                                                40000000000000,
                                                50000000000000,
                                                60000000000000,
                                                70000000000000,
                                                80000000000000,
                                                90000000000000,
												100000000000000};

    /* Indicates the following data is a payment ID */
    const uint8_t TX_EXTRA_PAYMENT_ID_IDENTIFIER = 0x00;

    /* Indicates the following data is a transaction public key */
    const uint8_t TX_EXTRA_PUBKEY_IDENTIFIER = 0x01;

    /* Indicates the following data is an extra nonce */
    const uint8_t TX_EXTRA_NONCE_IDENTIFIER = 0x02;

    /* Indicates the following data is a merge mine depth+merkle root */
    const uint8_t TX_EXTRA_MERGE_MINING_IDENTIFIER = 0x03;

    const uint8_t TX_EXTRA_TRANSACTION_POW_NONCE_IDENTIFIER = 0x04;

    /* Indicates the following data is arbitrary data in tx_extra */
    const uint8_t TX_EXTRA_ARBITRARY_DATA_IDENTIFIER = 0x7f;

    const Crypto::Hash NULL_HASH = Crypto::Hash({
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    });

    const Crypto::PublicKey NULL_PUBLIC_KEY = Crypto::PublicKey({
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    });

    const Crypto::SecretKey NULL_SECRET_KEY = Crypto::SecretKey({
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    });
} // namespace Constants
