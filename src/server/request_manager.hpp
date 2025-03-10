#pragma once
#include <mutex>
#include <vector>
#include <map>
#include <list>
#include "../core/transaction.hpp"
#include "../core/host_manager.hpp"
#include "../core/common.hpp"
#include "blockchain.hpp"
#include "mempool.hpp"
using namespace std;


class RequestManager {
    public:
        RequestManager(HostManager& hosts, string ledgerPath="", string blockPath="", string txdbPath="");
        json addTransaction(Transaction& t);
        json getProofOfWork();
        json submitProofOfWork(Block & block);
        json getBlock(uint32_t blockId);
        json getLedger(PublicWalletAddress w);
        json getStats();
        json verifyTransaction(Transaction& t);
        json getPeers();
        json addPeer(string address, uint64_t time, string version);
        BlockHeader getBlockHeader(uint32_t blockId);
        std::pair<uint8_t*, size_t> getRawBlockData(uint32_t blockId);
        std::pair<char*, size_t> getRawTransactionData();
        string getBlockCount();
        string getTotalWork();
        void deleteDB();
    protected:
        HostManager& hosts;
        BlockChain* blockchain;
        MemPool* mempool;
};