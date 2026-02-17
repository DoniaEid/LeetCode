#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class AuctionSystem {
private:
    struct Bid {
        int amount;
        int userId;

        bool operator<(const Bid& other) const {
            if (amount != other.amount) {
                return amount > other.amount; 
            }
            return userId > other.userId;
        }
    };

    unordered_map<int, set<Bid>> items;

    unordered_map<int, unordered_map<int, int>> userBids;

public:
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        if (userBids[userId].count(itemId)) {
            int oldAmount = userBids[userId][itemId];
            items[itemId].erase({oldAmount, userId});
        }
        
        items[itemId].insert({bidAmount, userId});
        userBids[userId][itemId] = bidAmount;
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = userBids[userId][itemId];
        items[itemId].erase({oldAmount, userId});
        
        items[itemId].insert({newAmount, userId});
        userBids[userId][itemId] = newAmount;
    }

    void removeBid(int userId, int itemId) {
        int oldAmount = userBids[userId][itemId];
        items[itemId].erase({oldAmount, userId});
        userBids[userId].erase(itemId);
    }

    int getHighestBidder(int itemId) {
        if (items.find(itemId) == items.end() || items[itemId].empty()) {
            return -1;
        }
        return items[itemId].begin()->userId;
    }
};