// Copyright (c) 2017-2018 The PIVX developers
// Copyright (c) 2018-2019 The eBlockCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef eBlockCoin_MINTPOOL_H
#define eBlockCoin_MINTPOOL_H

#include <map>
#include <list>

#include "primitives/zerocoin.h"
#include "libzerocoin/bignum.h"
#include "uint256.h"

/**
 * The MintPool only contains mint values that have not been added to the blockchain yet.
 * When a mint is generated by the wallet, or found while syncing, the mint will be removed
 * from the MintPool.
 *
 * The MintPool provides a convenient way to check whether mints in the blockchain belong to a
 * wallet's deterministic seed.
 */
class CMintPool : public std::map<uint256, uint32_t> //pubcoin hash, count
{
private:
    uint32_t nCountLastGenerated;
    uint32_t nCountLastRemoved;

public:
    CMintPool();
    explicit CMintPool(uint32_t nCount);
    void Add(const CBigNum& bnValue, const uint32_t& nCount);
    void Add(const std::pair<uint256, uint32_t>& pMint, bool fVerbose = false);
    bool Has(const CBigNum& bnValue);
    void Remove(const CBigNum& bnValue);
    void Remove(const uint256& hashPubcoin);
    std::pair<uint256, uint32_t> Get(const CBigNum& bnValue);
    std::list<std::pair<uint256, uint32_t> > List();
    void Reset();

    bool Front(std::pair<uint256, uint32_t>& pMint);
    bool Next(std::pair<uint256, uint32_t>& pMint);

    //The count of the next mint to generate will have be a mint that is already in the pool
    //therefore need to return the next value that has not been removed from the pool yet
    uint32_t CountOfLastRemoved() { return nCountLastRemoved; }

    //The next pool count returns the next count that will be added to the pool
    uint32_t CountOfLastGenerated() { return nCountLastGenerated; }
};


#endif //eBlockCoin_MINTPOOL_H
